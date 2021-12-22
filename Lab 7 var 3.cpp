#include <iostream>
#include <string>
using namespace std;

int Strcmp(char, char );

int checkInt()		//функция проверки int
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

double checkDouble()		//функция проверки double
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

T* reverse(T *mas, int size)		//шаблонная функция
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
char* reverse(char* mas, int size)		//явная специализация шаблонной функции
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

template <class T2>

void sort(T2* &mas, const int& size)
{
	cout << "1 - by uprising, 2 - by decreasing: " << endl;
	int  option;
	option = checkInt();
	switch (option)
	{
	case 1:
		for (int i = 0; i < size; ++i)
			for (int j = i + 1; j < size; ++j)
				if (mas[i] > mas[j])
					swap(mas[i], mas[j]);
		break;
	case 2:
		for (int i = 0; i < size; ++i)
			for (int j = i + 1; j < size; ++j)
				if (mas[i] < mas[j])
					swap(mas[i], mas[j]);
		break;
	default:
		break;
	}

}

template<>

void sort(char*& mas, const int& size)
{
	cout << "1 - by uprising, 2 - by decreasing: " << endl;
	int  option;
	option = checkInt();
	switch (option)
	{
	case 1:
		for (int i = 0; i < size; ++i)
			for (int j = i + 1; j < size; ++j)
				if (Strcmp(mas[i], mas[j])>0)
					swap(mas[i], mas[j]);
		break;
	case 2:
		for (int i = 0; i < size; ++i)
			for (int j = i + 1; j < size; ++j)
				if (Strcmp(mas[i], mas[j]) < 0)
					swap(mas[i], mas[j]);
		break;
	default:
		break;
	}

}

int Strcmp(char string1, char string2)
{
	int i = 0;
	int flag = 0;
	if (string1 > string2)
		flag = 1;
	else if (string1 < string2)
		flag = -1;
	else if (string1 == string2)		
		flag = 0;

	return flag;
}

void printMenu()
{
	cout << "1 - change size of massive" << endl;
	cout << "2 - fill in massive" << endl;
	cout << "3 - print massive" << endl;
	cout << "4 - reverse massive" << endl;
	cout << "5 - divide string" << endl;
	cout << "6 - change type of massive" << endl;
	cout << "7 - sort massive" << endl;
	cout << "0 - exit" << endl;
}

int main()
{
	int* Int;
	double* Double;
	char* Char;
	int option, size = 5, type = 0, symbols, i ,j=5, k, s, fd, d=5;
	char symbol = '0';
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
		case 1:		//смена размера массива
			system("cls");
			cout << "Enter size: " << endl;
			j=d=size = checkInt();
			break;
		case 2:		//выбор типа массива
			system("cls");
			cout << "Choose type of massive:\n1 - int\n2 - double\n3 - char " << endl;
			type = checkInt();
			switch (type)
			{
			case 1:
				Int = new int[j];
				for (int i = 0; i < j; i++)
				{
					cout << "Enter the value: " << endl;
					Int[i] = checkInt();
				}
				break;
			case 2:
				Double = new double[d];
				for (int i = 0; i < d; i++)
				{
					cout << "Enter the value: " << endl;
					Double[i] = checkDouble();
				}
				break;
			case 3:
				cout << "Enter the value: " << endl;
				symbols = 0;
				Char = new char[symbols];
				cin.clear();
				cin.ignore();
				while (Char[symbols - 1] != '\n')
				{
					Char[symbols] = getchar();
					symbols++;
				}
				Char[symbols - 1] = '\0';
				break;
			default:
				break;
			}
			break;
		case 3:		//вывод массива
			system("cls");
			switch (type)
			{
			case 1:
				printMassive(Int, j);
				break;
			case 2:
				printMassive(Double, d);
				break;
			case 3:
				printMassive(Char, symbols);
				break;
			}
			break;
		case 4:		//реверс массива
			system("cls");
			switch (type)
			{
			case 1:
				Int = reverse(Int, j);
				printMassive(Int, j);
				break;
			case 2:
				Double = reverse(Double, d);
				printMassive(Double, d);
				break;
			case 3:
				Char = reverse(Char, symbols);
				printMassive(Char, symbols);
				break;
			}
			break;
		case 5:			//доп
			i = 0, j=0, s=0, fd=0, d=0;
			char* str;
			str = new char[i];
			while (Char[i] != '\0')
			{
				if ((Char[i] >= '0' && Char[i] <= '9') || (Char[i]=='.' && (Char[i+1] >= '0' && Char[i+1] <= '9')))
				{
					if (Char[i] == '.' && (Char[i + 1] >= '0' && Char[i + 1] <= '9'))
					{
						fd = 1;
					}
					else if (Char[i] == '.' && (Char[i + 1] < '0' && Char[i + 1] > '9'))
					{
						fd = 0;
					}
						
					str[s] = Char[i];
					k = i;
					while (Char[k] != '\0')
					{
						Char[k] = Char[k+1];
						k++;
					}
					if ((Char[i] >= '0' && Char[i] <= '9')|| Char[i]=='.')
					{
						s++;
						continue;						
					}
					else if(fd == 0)
					{
						Int[j] = atoi(str);
						s = 0;
						str = new char[s];
						j++;
					}		
					else if (fd == 1)
					{
						Double[d] = atof(str);
						s = 0;
						fd = 0;
						str = new char[s];
						d++;
					}
				}
				else
					i++;
			}
			delete[] str;
			break;
		case 6:
			do
			{
				cout << "Choose type 1 - int, 2 - double, 3 - char" << endl;
				type = checkInt();
			} while (type < 1 && type>3);
			break;
		case 7:
			system("cls");
			switch (type)
			{
			case 1:
				sort(Int, j);
				printMassive(Int, j);
				break;
			case 2:
				sort(Double, d);
				printMassive(Double, d);
				break;
			case 3:
				sort(Char, symbols);
				printMassive(Char, symbols);
				break;
			}
			break;
		case 0:
			delete[] Int;
			delete[] Double;
			return 0;
		}
	}
}	//вводим строку и разбиваем её на 3 типа int, double и char, сортировка этих строк
