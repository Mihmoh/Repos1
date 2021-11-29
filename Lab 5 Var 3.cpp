#include <iostream>
#include <string>
#include <Windows.h>
#include <locale.h>
using namespace std;

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

class salary;
int Strcmp(string , string );

class worker
{
protected:
	string name;
public:
	worker()
	{
		name = "default";
	}
	worker(string NAME)
	{
		name = NAME;
	}
	~worker()
	{

	}

	void print()
	{
		cout << name << endl;
	}

	void sortName(salary*&, const int&);
};

class engineer : public virtual worker
{
protected:
	string specialization;
public:
	engineer()
	{
		specialization = "default";
	}
	engineer(string name, string Specialization) : worker(name), specialization(Specialization) {}
	~engineer()
	{

	}
	void print()
	{
		cout << name << " " << specialization << endl;
	}
	void sortSpecialization(salary*&, const int&);
};

class category : public engineer
{
protected:
	int Razryad;
public:
	category()
	{
		Razryad = 1;
	}
	category(string name, string specialization, int RAZRYAD) : engineer(name, specialization), Razryad(RAZRYAD) {	}
	~category()
	{

	}
	void print()
	{
		cout << name << " " << specialization << " " << Razryad << " razryada" << endl;
	}
	void sortCategory(salary*&, const int&);
};

class electric : public virtual worker
{
protected:
	string rank;
public:
	electric()
	{
		rank = "default";
	}
	electric(string name, string Rank) : worker(name), rank(Rank)
	{

	}
	~electric()
	{

	}
	void print()
	{
		cout << name << " " << rank << endl;
	}

	void sortRank(salary*&, const int&);
};

class cabinet : public electric
{
protected:
	int Cabinet;
public:
	cabinet()
	{
		Cabinet = 1;
	}
	cabinet(string name, string rank, int CAB) : electric(name, rank), Cabinet(CAB)
	{

	}
	~cabinet()
	{

	}
	void print()
	{
		cout << name << " " << rank << " " << Cabinet << " cabinet" << endl;
	}
	void sortCabinet(salary*&, const int& );
};

class salary : public category, public cabinet
{
private:
	int Zarplata = 0;
public:
	salary()
	{
		Zarplata = 1000;
	}
	salary(string name, string specialization, int Razryad, string rank, int Cabinet, int ZARPLATA):category(name, specialization, Razryad), cabinet(name, rank, Cabinet), Zarplata(ZARPLATA)
	{
		Zarplata = ZARPLATA;
	}
	~salary()
	{

	}
	salary init()
	{
		cout << "Enter name: " << endl;
		cin >> name;
		cout << "Enter specialization: " << endl;
		cin >> specialization;
		cout << "Enter category: " << endl;
		cin >> Razryad;
		cout << "Enter rank: " << endl;
		cin >> rank;
		cout << "Enter cabinet: " << endl;
		cin >> Cabinet;
		cout << "Enter salary: " << endl;
		cin >> Zarplata;
		return salary(name, specialization, Razryad, rank, Cabinet, Zarplata);
		
	}
	void print()
	{
		cout << "Name: " << name << ";\n specialization: " << specialization << ";\n category: " << Razryad << ";\n rank: " << rank << ";\n cabinet: " << Cabinet << ";\n salary: " << Zarplata << "." << endl;
		cout << "_____________________________________" << endl;

	}
	void sortSalary(salary*& mas, const int& size)
	{
		cout << "1 - by uprising, 2 - by decreasing: " << endl;
		int  option;
		option = checkInt();
		switch (option)
		{
		case 1:
			for (int i = 0; i < size; ++i)
				for (int j = i + 1; j < size; ++j)
					if (mas[i].Zarplata > mas[j].Zarplata)
						swap(mas[i], mas[j]);
			break;
		case 2:
			for (int i = 0; i < size; ++i)
				for (int j = i + 1; j < size; ++j)
					if (mas[i].Zarplata < mas[j].Zarplata)
						swap(mas[i], mas[j]);
			break;
		default:
			break;
		}
		
	}

	salary& operator () (string Name, string Specialization, int razryad, string Rank, int Cab, int Zar)
	{
		name = Name;
		specialization = Specialization;
		Razryad = razryad;
		rank = Rank;
		Cabinet = Cab;
		Zarplata = Zar;
		return*this;
	}
};

void cabinet :: sortCabinet(salary*& mas, const int& size)
{
	cout << "1 - by uprising, 2 - by decreasing: " << endl;
	int  option;
	option = checkInt();
	switch (option)
	{
	case 1:
		for (int i = 0; i < size; ++i)
			for (int j = i + 1; j < size; ++j)
				if (mas[i].Cabinet > mas[j].Cabinet)
					swap(mas[i], mas[j]);
		break;
	case 2:
		for (int i = 0; i < size; ++i)
			for (int j = i + 1; j < size; ++j)
				if (mas[i].Cabinet < mas[j].Cabinet)
					swap(mas[i], mas[j]);
		break;
	default:
		break;
	}

}

void category:: sortCategory(salary*& mas, const int& size)
{
	cout << "1 - by uprising, 2 - by decreasing: " << endl;
	int  option;
	option = checkInt();
	switch (option)
	{
	case 1:
		for (int i = 0; i < size; ++i)
			for (int j = i + 1; j < size; ++j)
				if (mas[i].Razryad > mas[j].Razryad)
					swap(mas[i], mas[j]);
		break;
	case 2:
		for (int i = 0; i < size; ++i)
			for (int j = i + 1; j < size; ++j)
				if (mas[i].Razryad < mas[j].Razryad)
					swap(mas[i], mas[j]);
		break;
	default:
		break;
	}

}

void electric::sortRank(salary*& mas, const int& size)
{
	cout << "1 - by uprising, 2 - by decreasing: " << endl;
	int  option;
	option = checkInt();
	switch (option)
	{
	case 1:
		for (int i = 0; i < size; ++i)
			for (int j = i + 1; j < size; ++j)
				if (Strcmp(mas[i].rank, mas[j].rank) > 0)
					swap(mas[i], mas[j]);
		break;
	case 2:
		for (int i = 0; i < size; ++i)
			for (int j = i + 1; j < size; ++j)
				if (Strcmp(mas[i].rank, mas[j].rank) < 0)
					swap(mas[i], mas[j]);
		break;
	default:
		break;
	}
	
}

void engineer::sortSpecialization(salary*& mas, const int& size)
{
	cout << "1 - by uprising, 2 - by decreasing: " << endl;
	int  option;
	option = checkInt();
	switch (option)
	{
	case 1:
		for (int i = 0; i < size; ++i)
			for (int j = i + 1; j < size; ++j)
				if (Strcmp(mas[i].specialization, mas[j].specialization) > 0)
					swap(mas[i], mas[j]);
		break;
	case 2:
		for (int i = 0; i < size; ++i)
			for (int j = i + 1; j < size; ++j)
				if (Strcmp(mas[i].specialization, mas[j].specialization) < 0)
					swap(mas[i], mas[j]);
		break;
	default:
		break;
	}

}

void worker::sortName(salary*& mas, const int& size)
{
	cout << "1 - by uprising, 2 - by decreasing: " << endl;
	int  option;
	option = checkInt();
	switch (option)
	{
	case 1:
		for (int i = 0; i < size; ++i)
			for (int j = i + 1; j < size; ++j)
				if (Strcmp(mas[i].name, mas[j].name) > 0)
					swap(mas[i], mas[j]);
		break;
	case 2:
		for (int i = 0; i < size; ++i)
			for (int j = i + 1; j < size; ++j)
				if (Strcmp(mas[i].name, mas[j].name) < 0)
					swap(mas[i], mas[j]);
		break;
	default:
		break;
	}

}

void printMenu()
{
	cout << "1 - sort by name " << endl;
	cout << "2 - sort by specialization " << endl;
	cout << "3 - sort by category " << endl;
	cout << "4 - sort by rank " << endl;
	cout << "5 - sort by cabinet " << endl;
	cout << "6 - sort by salary " << endl;
	cout << "0 - exit " << endl;
}

int Strcmp(string string1, string string2)
{
	int i = 0;
	int flag = 0;
	while (flag == 0)
	{
		if (string1[i] > string2[i])
		{
			flag = 1;
		}
		else if (string1[i] < string2[i])
		{
			flag = -1;
		}

		if (string1[i] == '\0')
		{
			break;
		}

		i++;
	}
	return flag;
}

int main()
{
	setlocale(LC_ALL, "ru");
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	salary *a;
	int size, option;
	cout << "Enter type of initialization: 1 - by default, 2 - your input " << endl;
	option = checkInt();
	switch (option)
	{
	case 1:
		size = 3;
		a = new salary[size];
		a[0]("Ivan", "microschemes", 1, "older", 3, 1250);
		a[1]("Boris", "wires", 3, "younger", 1, 1000);
		a[2]("Vyacheslav", "radio", 2, "moderate", 2, 1500);
		for (int i = 0; i < size; i++)
		{
			a[i].print();
		}
		break;
	case 2:
		cout << "Enter size of massive: " << endl;
		size = checkInt();
		a = new salary[size];
		for (int i = 0; i < size; i++)
		{
			a[i].init();
		}
		for (int i = 0; i < size; i++)
		{
			a[i].print();
		}
		break;
	default:
		break;
	}
	option = 100;
	while (option != 0)
	{
		printMenu();
		option = checkInt();
		switch (option)
		{
		case 1:
			system("cls");
			a->sortName(a, size);
			for (int i = 0; i < size; i++)
			{
				a[i].print();
			}
			break;
		case 2:
			system("cls");
			a->sortSpecialization(a, size);
			for (int i = 0; i < size; i++)
			{
				a[i].print();
			}
			break;
		case 3:
			system("cls");
			a->sortCategory(a, size);
			for (int i = 0; i < size; i++)
			{
				a[i].print();
			}
			break;
		case 4:
			system("cls");
			a->sortRank(a, size);
			for (int i = 0; i < size; i++)
			{
				a[i].print();
			}
			break;
		case 5:
			system("cls");
			a->sortCabinet(a, size);
			for (int i = 0; i < size; i++)
			{
				a[i].print();
			}
			break;
		case 6:
			system("cls");
			a->sortSalary(a, size);
			for (int i = 0; i < size; i++)
			{
				a[i].print();
			}
			break;
		case 0:
			return 0;

		}
	}
	
}

// массив последнего класса, сортировка по любому полю в своём классе, если числовое по возрастанию убыванию, если строковое по алфавиту
