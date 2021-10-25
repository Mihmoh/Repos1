#include <iostream>
#include <string>
#include <windows.h>
using namespace std;

class STO;
class automobile;
void Stop();
int checkInt();

class automobile		//3.класс автомобиль
{
private:		//закрытая секция
	int id, mileage;
	string name;

	friend STO;
	friend void print(automobile& value);
	//friend automobile SetClass(automobile& value);
	//friend void menu();
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
		name.clear();
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

};

void print(automobile& value)		//4.функция вывода
{
	cout << "ID " << value.id << "\nmileage " << value.mileage << "\nName " << value.name << endl << endl;
}

class STO		//дружественный класс СТО
{

public:
	automobile SetMileage(automobile& value)		//установка пробега
	{
		int Mileage = 0;
		cout << "Enter mileage " << endl;
		Mileage = checkInt();
		value.mileage = Mileage;
		return value;
	}
};

//automobile SetClass(automobile& value)
//{
//	automobile Automobile;
//	cout << "Enter ID " << endl;
//	cin >> Automobile.id;
//	cout << "Enter name " << endl;
//	cin >> Automobile.name;
//	cout << "Enter mileage " << endl;
//	cin >> Automobile.mileage;
//	return Automobile;
//}

//void printMenu()
//{
//	cout << "Choose action " << endl
//		<< "1 - create object " << endl
//		<< "2 - print object " << endl
//		<< "3 - change mileage " << endl
//		<< "0 - exit " << endl;
//}

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

//void menu()
//{
//	int chooser;
//	printMenu();
//	automobile car(1, 100, "somebody");
//	automobile cars[5];
//	while (1)
//	{
//		int chooser{ checkChooser() };
//		switch (chooser)
//		{
//		case 0:
//			return;
//		case 1:
//			car = SetClass(car);
//			system("cls");
//			printMenu();
//			break;
//		case 2:
//			print(car);
//			Stop();
//			system("cls");
//			printMenu();
//			break;
//		case 3:
//			STO Car;
//			car = Car.SetMileage(car);
//			printMenu();
//		}
//	}
//}

int main()
{
	automobile car1(1, 100, "Petr");		//7.одиночные экземпляры в головной функции
	automobile car2(2, 150, "Alex");
	automobile car3(3, 125, "Oleg");

	cout << "Single exemplars: " << endl << endl;

	print(car1);		//7.вывод одиночных экземпляров до обработки
	print(car2);
	print(car3);

	STO Car;

	car1 = Car.SetMileage(car1);		//7.обработка одиночных экземпляров с помощью метода дружественного класса
	car2 = Car.SetMileage(car2);
	car3 = Car.SetMileage(car3);

	system("cls");

	print(car1);	//7.вывод одиночных экземпляров после обработки
	print(car2);	
	print(car3);

	Stop();
	system("cls");

	automobile cars[3];		//8.массив экземпляров класса

	cout << "Massive: " << endl << endl;

	for (int i = 0; i < 3; i++)		//8.вывод массива до обработки
	{
		cars[i].SetId(i + 1);
		cars[i].SetMileage((i + 1) * 100);
		if (i == 0)
			cars[i].SetName("Maxim");
		if (i == 1)
			cars[i].SetName("Ivan");
		if (i == 2)
			cars[i].SetName("Bob");
		print(cars[i]);
	}

	for (int i = 0; i < 3; i++)		//8.обработка массива
	{
		cars[i] = Car.SetMileage(cars[i]);
	}

	system("cls");

	for (int i = 0; i < 3; i++)		//8.вывод массива после обработки
	{
		print(cars[i]);
	}
}

