#include <iostream>
#include <string>
using namespace std;

int checkInt() 
{
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

double checkDouble()
{
	double value = 0;
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

template <class T>

T* reverse(T *mas, int size)
{
	T* sam;
	sam = new T[size];
	int j = 0;
	for (int i = size - 1; i > -1; i--)
	{
		sam[j] = mas[i];
		j++;
	}
	return sam;
}

template<>
char* reverse(char* mas, int size)
{
	char* sam;
	sam = new char[size];
	int j = 0;
	for (int i = size - 1; i > -1; i--)
	{
		sam[j] = mas[i];
		j++;
	}
	return sam;
}

template <class T1>

void printMassive(T1* mas, int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << mas[i] << " ";
	}
	cout << endl;
	cout << endl;
}

template<>

void printMassive(char* mas, int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << mas[i];
	}
	cout << endl;
	cout << endl;
}

void printMenu()
{
	cout << "1 - change size of massive" << endl;
	cout << "2 - fill in massive" << endl;
	cout << "3 - print massive" << endl;
	cout << "4 - reverse massive" << endl;
	cout << "5 - exit" << endl;
}

int main()
{
	int* Int;
	double* Double;
	char* Char;
	int option, size = 5, type=0;
	Int = new int[size];
	Double = new double[size];
	Char = new char[size];
	
	while (true)
	{
		printMenu();
		option = checkInt();
		switch (option)
		{
		default:
			break;
		case 1:
			system("cls");
			cout << "Enter size: " << endl;
			size = checkInt();
			break;
		case 2:
			system("cls");
			cout << "Choose type of massive:\n1 - int\n2 - double\n3 - char " << endl;
			type = checkInt();
			switch (type)
			{
			case 1:
				Int = new int[size];
				for (int i = 0; i < size; i++)
				{
					cout << "Enter the value: " << endl;
					Int[i] = checkInt();
				}
				break;
			case 2:
				Double = new double[size];
				for (int i = 0; i < size; i++)
				{
					cout << "Enter the value: " << endl;
					Double[i] = checkDouble();
				}
				break;
			case 3:
				cout << "Enter the value: " << endl;
				Char = new char[size + 1];
				cin.getline(Char, size+1);
				cin.getline(Char, size+1);
				break;
			default:
				break;
			}
			break;
		case 3:
			system("cls");
			switch (type)
			{
			case 1:
				printMassive(Int, size);
				break;
			case 2:
				printMassive(Double, size);
				break;
			case 3:
				printMassive(Char, size);
				break;
			}
			break;
		case 4:
			system("cls");
			switch (type)
			{
			case 1:
				Int = reverse(Int, size);
				printMassive(Int, size);
				break;
			case 2:
				Double = reverse(Double, size);
				printMassive(Double, size);
				break;
			case 3:
				Char = reverse(Char, size);
				printMassive(Char, size);
				break;
			}
			break;
		case 5:
			return 0;
		}
	}
	
}
