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
		cout << "Destructor of worker..." << endl;
	}
	virtual int Counting() = 0;
	virtual void printInfo() = 0;
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
		name = "Vasiliy";
		workDays = 5;
		workHours = 8;
		totalWork = 40;
	}
	engineer(string Name, int WD, int WH):worker(Name)
	{
		name = Name;
		workDays = WD;
		workHours = WH;
	}
	~engineer() 
	{
		cout << "Destructor of engineer..." << endl;
	}
	int Counting() override
	{
		cout << "Counting total work of engineer..." << endl;
		totalWork = workHours * workDays;
		return totalWork;
	}
	void printInfo() override
	{
		cout << "Name: " << name << "\n work days: " << workDays << "\n work hours: " << workHours << "\n total work: " << totalWork << endl;
	}
};

class salary: public engineer
{
protected:
	int moneyPerHour;
	int totalSalary;
public:
	salary()
	{
		name = "Vasiliy";
		workDays = 5;
		workHours = 8;
		totalWork = 40;
		moneyPerHour = 10;
		totalSalary = 400;
	}
	salary(string Name, int WD, int WH, int MPH)
	{
		name = Name;
		workDays = WD;
		workHours = WH;
		moneyPerHour = MPH;
	}
	~salary()
	{
		cout << "Destructor of salary..." << endl;
	}
	int Counting() override
	{
		cout << "Counting total salary of engineer..." << endl;
		totalSalary = totalWork * moneyPerHour;
		return totalSalary;
	}
	void printInfo() override
	{
		cout << "Name: " << name << "\n work days: " << workDays << "\n work hours: " << workHours << "\n total work: " << totalWork<<"\n money per hour: "<< moneyPerHour<<"\n total salary: "<< totalSalary << endl;
	}
};

class medic : public worker
{
protected:
	int quantity_Of_Patients;
	int time_Of_work;
public:
	medic()
	{
		name = "Arcadiy";
		quantity_Of_Patients = 30;
		time_Of_work = 150;
	}
	medic(string Name, int QOP)
	{
		name = Name;
		quantity_Of_Patients = QOP;
	}
	~medic()
	{
		cout << "Destructor of medic..." << endl;
	}
	int Counting() override
	{
		cout << "Counting time of work of medic..." << endl;
		time_Of_work = quantity_Of_Patients * 5;
		return time_Of_work;
	}
	void printInfo() override
	{
		cout << "Name: " << name << "\n quantity of patients: " << quantity_Of_Patients << "\n time of work: " << time_Of_work  << endl;
	}
};

int main()
{
	worker **proletariy;
	proletariy = new worker*[3];
	proletariy[0] = new engineer;
	proletariy[1] = new salary;
	proletariy[2] = new medic;
	for (int i = 0; i < 3; i++)
	{
		proletariy[i]->Counting();
		proletariy[i]->printInfo();
	}
	delete[] proletariy;
}
