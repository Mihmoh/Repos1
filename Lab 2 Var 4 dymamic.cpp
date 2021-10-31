#include <iostream>
#include <string>
#include <windows.h>
using namespace std;

class STO;
class automobile;
void Stop();
int checkInt();

class STO		//дружественный класс СТО
{

public:
	int SetMileage(int value)		//установка пробега
	{
		int Mileage = 0;
		cout << "Enter mileage " << endl;
		Mileage = checkInt();
		value = Mileage;
		return value;
	}
};

class automobile		//3.класс автомобиль
{
private:		//закрытая секция
	int id, mileage;
	string name;
	automobile* next;
	automobile* previous;
	automobile* head=nullptr;

	friend STO;
	friend void print(automobile& value);
public:			//открытая секция

	automobile()		//3.конструктор по умолчанию
	{
		id = 0;
		mileage = 0;
		name = "noname";
	}

	automobile(int ID, int MILEAGE, string NAME)		//3.конструктор инциализации
	{
		id = ID;
		mileage = MILEAGE;
		name = NAME;
	}

	~automobile()		//3.деструктор
	{
		head = nullptr;
	}

	int GetId()
	{
		return id;
	}

	string GetName()
	{
		return name;

	}

	int GetMileage()
	{
		return mileage;
	}

	void SetId(int ID)
	{
		id = ID;
	}

	void SetName(string NAME)
	{
		name = NAME;
	}

	void SetMileage(int MILEAGE)
	{
		mileage = MILEAGE;
	}

	void creator()
	{
		int choose = 1;
		automobile* next = nullptr;
		automobile* previous = nullptr;
		if (head == nullptr)
		{
			while (choose != 0)
			{
				automobile* newCar = new automobile;
				cout << "Enter id\n";
				cin >> newCar->id;
				cout << "Enter mileage\n";
				cin >> newCar->mileage;
				cout << "Enter name\n";
				cin >> newCar->name;
				newCar->next = next;
				next = newCar;
				cout << "1 - continue, 0 - stop\n";
				cin >> choose;
				system("cls");
				if (head != nullptr)
				{
					head->previous = newCar;
				}
				head = next;
			}
		}
		else
		{
			automobile* newCar = new automobile;
			cout << "Enter id\n";
			cin >> newCar->id;
			cout << "Enter mileage\n";
			cin >> newCar->mileage;
			cout << "Enter name\n";
			cin >> newCar->name;
			newCar->next = head;
			next = newCar;
			cout << "1 - continue, 0 - stop\n";
			cin >> choose;
			system("cls");
			if (head != nullptr)
			{
				head->previous = newCar;
			}
			head = next;
		}
		
		
	}

	void printClass()
	{
		if (head == nullptr)
		{
			cout << "There are no any cars" << endl;
			return;
		}
		automobile* current = nullptr;
		current = head;
		while (current->next != nullptr)
		{			
			current = current->next;
		}
		while (current != nullptr)
		{			
			cout << "ID " << current->id << "\nmileage " << current->mileage << "\nName " << current->name << endl << endl;
			current = current->previous;
		}
	}

	automobile ChangeMileage(automobile& value)
	{
		if (head == nullptr)
		{
			cout << "There are no any cars" << endl;
			return value;
		}
		automobile* current = nullptr;
		current = head;
		int chooser = 0;
		cout << "Choose id" << endl;
		cin >> chooser;
		while (current != nullptr && chooser != current->id)
		{
			current = current->next;
		}
		if (current == nullptr)
		{
			cout << "There is no such id" << endl;
			return value;
		}
		else
		{
			STO Car;
			current->mileage = Car.SetMileage(current->mileage);
			return value;
		}
	}

	void SpecialOutput()
	{
		if (head == nullptr)
		{
			cout << "There are no any cars" << endl;
			return;
		}
		int min, max;
		cout << "Enter minimum mileage" << endl;
		cin >> min;
		cout << "Enter maximum mileage" << endl;
		cin >> max;
		int i = 0;

		automobile* current = nullptr;
		current = head;
		while (current->next != nullptr)
		{
			current = current->next;
		}
		system("cls");
		while (current != nullptr)
		{
			if (current->mileage >= min && current->mileage <= max)
			{
				cout << "ID " << current->id << "\nmileage " << current->mileage << "\nName " << current->name << endl << endl;
				i++;
			}			
			current = current->previous;
		}
		if (i == 0)
		{
			cout << "There are no any cars in such diapason" << endl;
		}
	}

};

void print(automobile& value)		//4.функция вывода
{
	cout << "ID " << value.id << "\nmileage " << value.mileage << "\nName " << value.name << endl << endl;
}

void Stop()
{
	int stop;
	cout << "\nPress any number, then enter to continue " << endl;
	cin >> stop;
}

int checkInt() {
	int value = 0;
	while (true) {
		if (cin >> value) {
			break;
		}
		else {
			cin.clear();
			cin.ignore();
			cout << "Enter right value ";
		}
	}
	return value;
}

void printMenu()
{
	cout << "1 - add car" << endl
		<< "2 - show cars" << endl
		<< "3 - change milleage" << endl
		<< "4 - special output" << endl
		<< "0 - exit" << endl;
}



int main()
{
	automobile car;
	int chooser = 1;
	printMenu();
	while (chooser != 0)
	{		
		cin >> chooser;
		switch (chooser)
		{
		case 1:
			system("cls");
			car.creator();
			printMenu();
			break;
		case 2:
			system("cls");
			car.printClass();
			printMenu();
			break;
		case 3:
			system("cls");
			car = car.ChangeMileage(car);
			printMenu();
			break;
		case 4:
			system("cls");
			car.SpecialOutput();
			printMenu();
			break;
		case 0:
			system("cls");
			return 0;
		}
	}
	
}

//меню: 1 - добавить автомобиль, 2 - вывести автомобили, 3 - изменить пробег определённого автомобиля, 4 - вывести в алфавитном порядке автомобили с заданным диапазоном пробега
