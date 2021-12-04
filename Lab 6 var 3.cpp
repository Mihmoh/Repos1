#include <iostream>
#include <string>
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

class worker
{
protected:
	string name;
public:
	worker()
	{
		name = "Ivan";
	}
	worker(string NAME)
	{
		name = NAME;
	}
	virtual ~worker()
	{

	}
	virtual int Counting() = 0;
	virtual void printInfo() = 0;
	virtual void init() = 0;
	friend void sortName(worker**&, const int&);
	friend void sortWorkDays(worker**&, const int&);
	friend void sortWorkHours(worker**&, const int&);
	friend void sortTotalWork(worker**&, const int&);
};

class engineer : public worker
{
protected:
	int workDays;
	int workHours;
	int totalWork;
public:
	engineer()
	{
		name = "Ivan";
		workDays = 5;
		workHours = 8;
		totalWork = 40;
	}
	engineer(string name, int WD, int WH, int TW):worker(name), workDays (WD), workHours(WH), totalWork(0)
	{
		workDays = WD;
		workHours = WH;
		totalWork = 0;
	}
	~engineer() 
	{

	}
	void init() override
	{
		cout << "Enter name..." << endl;
		cin >> name;
		cout << "Enter work days..." << endl;
		workDays = checkInt();
		cout << "Enter work hours..." << endl;
		workHours = checkInt();
	}
	int Counting() override
	{
		cout << "Total work = work days * work hours..." << endl;
		totalWork = workHours * workDays;
		return totalWork;
	}
	void printInfo() override
	{
		cout << "Name: " << name << "\n work days: " << workDays << "\n work hours: " << workHours << "\n total work: " << totalWork << endl;
		cout << "___________________________________" << endl;
	}
	engineer& operator () (string Name, int WD, int WH)
	{
		name = Name;
		workDays = WD;
		workHours = WH;
		return*this;
	}
	friend void sortWorkDays(worker**& , const int& );
	friend void sortWorkHours(worker**&, const int&);
	friend void sortTotalWork(worker**&, const int&);
	friend void search(worker**&, const int&, int);
};

class salary: public engineer
{
protected:
	int moneyPerHour;
	int totalSalary;
public:
	salary()
	{
		name = "Boris";
		workHours = 6;
		workDays = 7;
		totalWork = 42;
		moneyPerHour = 10;
		totalSalary = 420;
	}
	salary(string name, int workDays, int workHours, int totalWork, int MPH): engineer(name, workDays, workHours, totalWork), moneyPerHour(MPH)
	{
		moneyPerHour = MPH;
	}
	~salary()
	{

	}
	void init() override
	{
		cout << "Enter name..." << endl;
		cin >> name;
		cout << "Enter work days..." << endl;
		workDays = checkInt();
		cout << "Enter work hours..." << endl;
		workHours = checkInt();
		cout << "Enter money per hour..." << endl;
		moneyPerHour = checkInt();
	}
	int Counting() override
	{
		totalWork = workDays * workHours;
		cout << "Total salary = total work * money per hour..." << endl;
		totalSalary = totalWork * moneyPerHour;
		return totalSalary;
	}
	void printInfo() override
	{
		cout << "Name: " << name << "\n work days: " << workDays << "\n work hours: " << workHours << "\n total work: " << totalWork<<"\n money per hour: "<< moneyPerHour<<"\n total salary: "<< totalSalary << endl;
		cout << "___________________________________" << endl;
	}
	friend void sortMPH(worker**&, const int&);
	friend void sortTotalSalary(worker**&, const int&);
	friend void search(worker**&, const int&, int);
};

class medic : public worker
{
protected:
	int quantity_Of_Patients;
	int time_Of_work;
public:
	medic()
	{
		name = "Alexander";
		quantity_Of_Patients = 30;
		time_Of_work = 150;
	}
	medic(string name, int QOP):worker(name), quantity_Of_Patients(QOP)
	{
		quantity_Of_Patients = QOP;
	}
	~medic()
	{

	}
	void init() override
	{
		cout << "Enter name..." << endl;
		cin >> name;
		cout << "Enter quantity of patients..." << endl;
		quantity_Of_Patients = checkInt();
	}
	int Counting() override
	{
		cout << "Time of work = quantity of patients * 5..." << endl;
		time_Of_work = quantity_Of_Patients * 5;
		return time_Of_work;
	}
	void printInfo() override
	{
		cout << "Name: " << name << "\n quantity of patients: " << quantity_Of_Patients << "\n time of work: " << time_Of_work  << endl;
		cout << "___________________________________" << endl;
	}
	friend void sortQOP(worker**& , const int& );
	friend void sortTOW(worker**&, const int&);
	friend void search(worker**&, const int&, int);
};

void printMenu()
{
	cout << "1 - add element " << endl;
	cout << "2 - print all " << endl;
	cout << "3 - sort by name " << endl;
	cout << "4 - sort by work days " << endl;
	cout << "5 - sort by work hours " << endl;
	cout << "6 - sort by total work " << endl;
	cout << "7 - sort by money per hour " << endl;
	cout << "8 - sort by quantity of patients " << endl;
	cout << "9 - sort by time of work " << endl;
	cout << "10 - sort by total salary " << endl;
	cout << "11 - search by diapason " << endl;
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

void sortName(worker**& mas, const int& size)
{
	cout << "1 - by uprising, 2 - by decreasing: " << endl;
	int  option;
	option = checkInt();
	switch (option)
	{
	case 1:
		for (int i = 0; i < size; ++i)
			for (int j = i + 1; j < size; ++j)
				if (Strcmp(mas[i]->name, mas[j]->name) > 0)
					swap(mas[i], mas[j]);
		break;
	case 2:
		for (int i = 0; i < size; ++i)
			for (int j = i + 1; j < size; ++j)
				if (Strcmp(mas[i]->name, mas[j]->name) < 0)
					swap(mas[i], mas[j]);
		break;
	default:
		break;
	}	
}

void sortWorkDays(worker**& mas, const int& size)
{
	engineer *A, * B;
	cout << "1 - by uprising, 2 - by decreasing: " << endl;
	int  option;
	option = checkInt();
	switch (option)
	{
	case 1:
		for (int i = 0; i < size; ++i)
			for (int j = i + 1; j < size; ++j)
			{
				A = (engineer *)mas[i];
				B = (engineer *)mas[j];
				if (A->workDays > B->workDays)
					swap(mas[i], mas[j]);
			}
		break;
	case 2:
		for (int i = 0; i < size; ++i)
			for (int j = i + 1; j < size; ++j)
			{
				A = (engineer*)mas[i];
				B = (engineer*)mas[j];
				if (A->workDays < B->workDays)
					swap(mas[i], mas[j]);
			}
		break;
	default:
		break;
	}

}

void sortWorkHours(worker**& mas, const int& size)
{
	engineer* A, * B;
	cout << "1 - by uprising, 2 - by decreasing: " << endl;
	int  option;
	option = checkInt();
	switch (option)
	{
	case 1:
		for (int i = 0; i < size; ++i)
			for (int j = i + 1; j < size; ++j)
			{
				A = (engineer*)mas[i];
				B = (engineer*)mas[j];
				if (A->workHours > B->workHours)
					swap(mas[i], mas[j]);
			}
		break;
	case 2:
		for (int i = 0; i < size; ++i)
			for (int j = i + 1; j < size; ++j)
			{
				A = (engineer*)mas[i];
				B = (engineer*)mas[j];
				if (A->workHours < B->workHours)
					swap(mas[i], mas[j]);
			}
		break;
	default:
		break;
	}

}

void sortTotalWork(worker**& mas, const int& size)
{
	engineer* A, * B;
	cout << "1 - by uprising, 2 - by decreasing: " << endl;
	int  option;
	option = checkInt();
	switch (option)
	{
	case 1:
		for (int i = 0; i < size; ++i)
			for (int j = i + 1; j < size; ++j)
			{
				A = (engineer*)mas[i];
				B = (engineer*)mas[j];
				if (A->totalWork > B->totalWork)
					swap(mas[i], mas[j]);
			}
		break;
	case 2:
		for (int i = 0; i < size; ++i)
			for (int j = i + 1; j < size; ++j)
			{
				A = (engineer*)mas[i];
				B = (engineer*)mas[j];
				if (A->totalWork < B->totalWork)
					swap(mas[i], mas[j]);
			}
		break;
	default:
		break;
	}

}

void sortMPH(worker**& mas, const int& size)
{
	salary* A, * B;
	cout << "1 - by uprising, 2 - by decreasing: " << endl;
	int  option;
	option = checkInt();
	switch (option)
	{
	case 1:
		for (int i = 0; i < size; ++i)
			for (int j = i + 1; j < size; ++j)
			{
				A = (salary*)mas[i];
				B = (salary*)mas[j];
				if (A->moneyPerHour > B->moneyPerHour)
					swap(mas[i], mas[j]);
			}
		break;
	case 2:
		for (int i = 0; i < size; ++i)
			for (int j = i + 1; j < size; ++j)
			{
				A = (salary*)mas[i];
				B = (salary*)mas[j];
				if (A->moneyPerHour < B->moneyPerHour)
					swap(mas[i], mas[j]);
			}
		break;
	default:
		break;
	}

}

void sortTotalSalary(worker**& mas, const int& size)
{
	salary* A, * B;
	cout << "1 - by uprising, 2 - by decreasing: " << endl;
	int  option;
	option = checkInt();
	switch (option)
	{
	case 1:
		for (int i = 0; i < size; ++i)
			for (int j = i + 1; j < size; ++j)
			{
				A = (salary*)mas[i];
				B = (salary*)mas[j];
				if (A->totalSalary > B->totalSalary)
					swap(mas[i], mas[j]);
			}
		break;
	case 2:
		for (int i = 0; i < size; ++i)
			for (int j = i + 1; j < size; ++j)
			{
				A = (salary*)mas[i];
				B = (salary*)mas[j];
				if (A->totalSalary < B->totalSalary)
					swap(mas[i], mas[j]);
			}
		break;
	default:
		break;
	}

}

void sortQOP(worker**& mas, const int& size)
{
	medic* A, * B;
	cout << "1 - by uprising, 2 - by decreasing: " << endl;
	int  option;
	option = checkInt();
	switch (option)
	{
	case 1:
		for (int i = 0; i < size; ++i)
			for (int j = i + 1; j < size; ++j)
			{
				A = (medic*)mas[i];
				B = (medic*)mas[j];
				if (A->quantity_Of_Patients > B->quantity_Of_Patients)
					swap(mas[i], mas[j]);
			}
		break;
	case 2:
		for (int i = 0; i < size; ++i)
			for (int j = i + 1; j < size; ++j)
			{
				A = (medic*)mas[i];
				B = (medic*)mas[j];
				if (A->quantity_Of_Patients < B->quantity_Of_Patients)
					swap(mas[i], mas[j]);
			}
		break;
	default:
		break;
	}

}

void sortTOW(worker**& mas, const int& size)
{
	medic* A, * B;
	cout << "1 - by uprising, 2 - by decreasing: " << endl;
	int  option;
	option = checkInt();
	switch (option)
	{
	case 1:
		for (int i = 0; i < size; ++i)
			for (int j = i + 1; j < size; ++j)
			{
				A = (medic*)mas[i];
				B = (medic*)mas[j];
				if (A->time_Of_work > B->time_Of_work)
					swap(mas[i], mas[j]);
			}
		break;
	case 2:
		for (int i = 0; i < size; ++i)
			for (int j = i + 1; j < size; ++j)
			{
				A = (medic*)mas[i];
				B = (medic*)mas[j];
				if (A->time_Of_work < B->time_Of_work)
					swap(mas[i], mas[j]);
			}
		break;
	default:
		break;
	}

}

void search(worker**& mas, const int& size, int option)
{
	engineer a("0", 0, 0, 0);
	salary b("0", 0, 0, 0, 0);
	medic c("0", 0);
	engineer* A;
	salary* B;
	medic* C;
	int min, max, j=0;
	switch (option)
	{
	case 1:
		cout << "Enter min work days" << endl;
		min = checkInt();
		cout << "Enter max work days" << endl;		
		max = checkInt();		
		for (int i = 0; i < size; i++)
		{
			A = (engineer*)mas[i];
			B = (salary*)mas[i];
			if (A->workDays >= min && A->workDays <= max)
			{
				if (typeid(*mas[i]).name() == typeid(a).name() || typeid(*mas[i]).name() == typeid(b).name())
				{
					mas[i]->printInfo();
					j++;
				}				
			}
		}
		if (j == 0)
			cout << "There are no elements in this diapason" << endl;
		j = 0;
		break;
	case 2:
		cout << "Enter min work hours" << endl;
		min = checkInt();
		cout << "Enter max work hours" << endl;
		max = checkInt();
		for (int i = 0; i < size; i++)
		{
			A = (engineer*)mas[i];
			B = (salary*)mas[i];
			if (A->workHours >= min && A->workHours <= max)
			{
				if (typeid(*mas[i]).name() == typeid(a).name() || typeid(*mas[i]).name() == typeid(b).name())
				{
					mas[i]->printInfo();
					j++;
				}
			}
		}
		if (j == 0)
			cout << "There are no elements in this diapason" << endl;
		j = 0;
		break;
	case 3:
		cout << "Enter min total work" << endl;
		min = checkInt();
		cout << "Enter max total work" << endl;
		max = checkInt();
		for (int i = 0; i < size; i++)
		{
			A = (engineer*)mas[i];
			B = (salary*)mas[i];
			if (A->totalWork >= min && A->totalWork <= max)
			{
				if (typeid(*mas[i]).name() == typeid(a).name() || typeid(*mas[i]).name() == typeid(b).name())
				{
					mas[i]->printInfo();
					j++;
				}
			}
		}
		if (j == 0)
			cout << "There are no elements in this diapason" << endl;
		j = 0;
		break;	
	case 4:
		cout << "Enter min money per hour" << endl;
		min = checkInt();
		cout << "Enter max money per hour" << endl;
		max = checkInt();
		for (int i = 0; i < size; i++)
		{
			B = (salary*)mas[i];
			if (B->moneyPerHour >= min && B->moneyPerHour <= max)
			{
				if (typeid(*mas[i]).name() == typeid(b).name())
				{
					mas[i]->printInfo();
					j++;
				}
			}
		}
		if (j == 0)
			cout << "There are no elements in this diapason" << endl;
		j = 0;
		break;
	case 5:
		cout << "Enter min total salary" << endl;
		min = checkInt();
		cout << "Enter max total salary" << endl;
		max = checkInt();
		for (int i = 0; i < size; i++)
		{
			B = (salary*)mas[i];
			if (B->totalSalary >= min && B->totalSalary <= max)
			{
				if (typeid(*mas[i]).name() == typeid(b).name())
				{
					mas[i]->printInfo();
					j++;
				}
			}
		}
		if (j == 0)
			cout << "There are no elements in this diapason" << endl;
		j = 0;
		break;
	case 6:
		cout << "Enter min quantity of patients" << endl;
		min = checkInt();
		cout << "Enter max quantity of patients" << endl;
		max = checkInt();
		for (int i = 0; i < size; i++)
		{
			C = (medic*)mas[i];
			if (C->quantity_Of_Patients >= min && C->quantity_Of_Patients <= max)
			{
				if (typeid(*mas[i]).name() == typeid(c).name())
				{
					mas[i]->printInfo();
					j++;
				}
			}
		}
		if (j == 0)
			cout << "There are no elements in this diapason" << endl;
		j = 0;
		break;
	case 7:
		cout << "Enter min quantity of patients" << endl;
		min = checkInt();
		cout << "Enter max quantity of patients" << endl;
		max = checkInt();
		for (int i = 0; i < size; i++)
		{
			C = (medic*)mas[i];
			if (C->time_Of_work >= min && C->time_Of_work <= max)
			{
				if (typeid(*mas[i]).name() == typeid(c).name())
				{
					mas[i]->printInfo();
					j++;
				}
			}
		}
		if (j == 0)
			cout << "There are no elements in this diapason" << endl;
		j = 0;
		break;
	}
}

int main()
{
	engineer a("0", 0, 0, 0);
	salary b("0", 0, 0, 0, 0);
	medic c("0", 0);
	int size = 3;
	worker **proletariy;
	proletariy = new worker * [size];
	int option = 100;
	cout << "Choose type of initialization: 1 - default, 2 - manualy" << endl;
	option = checkInt();
	switch (option)
	{
	default:
		proletariy[0] = new engineer;
		proletariy[1] = new salary;
		proletariy[2] = new medic;
		size = 3;
		break;
	case 2:
		size = 0;
		proletariy = new worker * [size];
		break;
	}	
	while (option != 0)
	{
		printMenu();
		option = checkInt();
		switch (option)
		{
		case 1:			
			while (option != 0)
			{
				system("cls");
				cout << "Choose type of object: 1 - engineer, 2 - salary, 3 - medic, 0 - stop " << endl;
				option = checkInt();
				switch (option)
				{
				case 1:
					proletariy[size] = new engineer;
					proletariy[size]->init();
					proletariy[size]->Counting();
					size++;					
					break;
				case 2:
					proletariy[size] = new salary;
					proletariy[size]->init();					
					proletariy[size]->Counting();
					size++;
					break;
				case 3:
					proletariy[size] = new medic;
					proletariy[size]->init();
					proletariy[size]->Counting();
					size++;
					break;
				default:
					break;
				}
			}		
			option = 100;
			break;
		case 2:
			system("cls");
			for (int i = 0; i < size; i++)
			{
				proletariy[i]->printInfo();
			}
			break;
		case 3:
			system("cls");
			sortName(proletariy, size);
			for (int i = 0; i < size; i++)
			{
				proletariy[i]->printInfo();
			}
			break;
		case 4:
			system("cls");
			sortWorkDays(proletariy, size);
			for (int i = 0; i < size; i++)
			{
				if (typeid(*proletariy[i]).name() == typeid(a).name() || typeid(*proletariy[i]).name() == typeid(b).name())
					proletariy[i]->printInfo();
			}
			break;
		case 5:
			system("cls");
			sortWorkHours(proletariy, size);
			for (int i = 0; i < size; i++)
			{
				if (typeid(*proletariy[i]).name() == typeid(a).name() || typeid(*proletariy[i]).name() == typeid(b).name())
					proletariy[i]->printInfo();
			}
			break;
		case 6:
			system("cls");
			sortTotalWork(proletariy, size);
			for (int i = 0; i < size; i++)
			{
				if (typeid(*proletariy[i]).name() == typeid(a).name()|| typeid(*proletariy[i]).name() == typeid(b).name())
					proletariy[i]->printInfo();
			}
			break;
		case 7:
			system("cls");
			sortMPH(proletariy, size);			
			for (int i = 0; i < size; i++)
			{
				if(typeid(*proletariy[i]).name()== typeid(b).name())
					proletariy[i]->printInfo();				
			}
			break;
		case 8:
			system("cls");
			sortQOP(proletariy, size);
			for (int i = 0; i < size; i++)
			{
				if (typeid(*proletariy[i]).name() == typeid(c).name())
					proletariy[i]->printInfo();
			}
			break;
		case 9:
			system("cls");
			sortTOW(proletariy, size);
			for (int i = 0; i < size; i++)
			{
				if (typeid(*proletariy[i]).name() == typeid(c).name())
					proletariy[i]->printInfo();
			}
			break;
		case 10:
			system("cls");
			sortTotalSalary(proletariy, size);
			for (int i = 0; i < size; i++)
			{
				if (typeid(*proletariy[i]).name() == typeid(b).name())
					proletariy[i]->printInfo();
			}
			break;
		case 11:
			system("cls");
			cout << "Enter what to search: \n1 - work days\n2 - work hours\n3 - total work\n4 - money per hour\n5 - total salary\n6 - quantity of patients\n7 - time of work" << endl;
			option = checkInt();
			search(proletariy, size, option);				
			option = 100;
			break;
		case 0:
			for (int i = 0; i < size; i++)
				delete proletariy[i];
			return 0;
		}
	}
}
//меню, удаление дубликатов, поиск по диапазону, сортировка по любому полю
