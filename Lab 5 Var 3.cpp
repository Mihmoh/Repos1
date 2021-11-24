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
	engineer(string NAME, string Specialization) : worker(NAME), specialization(Specialization)	{}
	~engineer()
	{

	}
	void print()
	{
		cout << name << " "<< specialization << endl;
	}
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
	category(string NAME, string Specialization, int RAZRYAD) : engineer(name, specialization), Razryad(RAZRYAD){	}
	~category()
	{

	}
	void print()
	{
		cout << name << " " << specialization<< " "<< Razryad<< " razryada" << endl;
	}
};

class medic : public virtual worker
{
protected:
	string rank;
public:
	medic()
	{
		rank = "default";
	}
	medic(string NAME, string Rank) : worker(name), rank(Rank)
	{

	}
	~medic()
	{

	}
	void print()
	{
		cout << name << " " << rank << endl;
	}
};

class cabinet : protected medic
{
protected:
	int Cabinet;
public:
	cabinet()
	{
		Cabinet = 1;
	}
	cabinet(string NAME, string Specialization, int CAB) : medic(name, rank), Cabinet(CAB)
	{

	}
	~cabinet()
	{

	}
	void print()
	{
		cout << name << " " << rank << " " << Cabinet << " cabinet" << endl;
	}
};

class salary : public category , public cabinet
{
private:
	int Zarplata = 0;
public:
	salary()
	{
		Zarplata = 1000;
	}
	salary(string NAME, string Specialization, int RAZ, string RANK, int CAB, int ZARPLATA)
	{
		name = NAME;
		specialization = Specialization;
		Razryad = RAZ;
		rank = RANK;
		Cabinet = CAB;
		Zarplata = ZARPLATA;
	}
	~salary()
	{

	}
	salary init()
	{
		cout << "Choose type of worker 1 - engineer, 2 - medic: " << endl;
		int option;
		option = checkInt();
		switch (option)
		{
		case 1:
			cout << "Enter name: " << endl;
			cin >> name;
			cout << "Enter specialization: " << endl;
			cin >> specialization;
			cout << "Enter category: " << endl;
			cin >> Razryad;
			cout << "Enter salary: " << endl;
			cin >> Zarplata;
			return salary(name, specialization, Razryad, "-", 0, Zarplata);
		case 2:
			cout << "Enter name: " << endl;
			cin >> name;
			cout << "Enter rank: " << endl;
			cin >> rank;
			cout << "Enter cabinet: " << endl;
			cin >> Cabinet;
			cout << "Enter salary: " << endl;
			cin >> Zarplata;
			return salary(name, "-", 0, rank, Cabinet, Zarplata);
		}
	}
	void print()
	{
		cout<< "Name: " << name << "; specialization: " << specialization << "; category: " << Razryad << "; rank: "<< rank << "; cabinet: "<< Cabinet << "; salary: " << Zarplata << "." << endl;
	}
};



int main()
{
	salary a;
	a.init();
	a.print();
}
