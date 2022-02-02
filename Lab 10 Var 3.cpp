#include <iostream>
#include <string>
using namespace std;

void continuationCondition() //пауза продолжения
{
	char s;
	rewind(stdin);
	printf("\nPress enter to continue... \n");
	scanf_s("%c", &s);
}

class MyException
{
private:
	int excep;
public:
	MyException(int except) : excep{ except }
	{

	}
	void answer()
	{
		switch (excep)
		{
		case 1:
			cout << "Exception: wrong index" << endl;
			break;
		case 2:
			cout << "Exception: type is not chosen" << endl;
			break;
		case 3:
			cout << "Exception: non-numeric value" << endl;
			break;
		case 4:
			cout << "Exception: there are no such elements in stack" << endl;
			break;
		case 5:
			cout << "Exception: there is already such element" << endl;
			break;
		case 6:
			cout << "Exception: not char type" << endl;
			break;
		}
	}
};

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
			throw MyException(3);
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
			throw MyException(3);
		}
	}
	return value;
}

template<typename T>
class List
{
public:
	List();
	~List();

	void push_back(T data);
	void pop_front();
	void clear();
	void push_front(T data);
	void insert(T data, int index);
	void removeAt(int index);
	void pop_back();
	void printList();
	void findData(T data);
	void comparing(string data, int Length);
	int getSize() { return size; }
	T& operator[](const int index);

private:

	template<typename T>
	class Element
	{
	public:
		Element* pNext;
		T data;

		Element(T data = T(), Element *pNext = nullptr)
		{
			this->data = data;
			this->pNext = pNext;
		}

	};

	Element<T>* head;
	int size;

};

template<typename T>
List<T>::List()
{
	size = 0;
	head = nullptr;
}

template<typename T>
List<T>::~List()
{
	clear();
}


template<typename T>
void List<T>::push_back(T data)
{
	if (head==nullptr)
	{
		head = new Element<T>(data);
	}
	else
	{
		Element<T>* current = this->head;
		if (current->data == data)
		{
			throw MyException(5);
		}
		else
		while (current->pNext != nullptr)
		{
			if (current->data != data)
			{
				current = current->pNext;
			}
			else
				throw MyException(5);
		}
		current->pNext = new Element<T>(data);

	}
	size++;
}

template<typename T>
void List<T>::pop_front()
{
	Element<T>* temp = head;
	head = head->pNext;
	delete temp;
	size--;
}

template<typename T>
void List<T>::clear()
{
	while (size)
	{
		pop_front();
	}
}

template<typename T>
void List<T>::push_front(T data)
{
	head = new Element<T>(data, head);
	size++;
}

template<typename T>
void List<T>::insert(T data, int index)
{
	if (index == 0)
	{
		push_front(data);
	}
	else
	{
		Element<T>* previous = this->head;
		for (int i = 0; i < index - 1; i++)
		{
			previous = previous->pNext;
		}

		Element<T>* newElement = new Element<T>(data, previous->pNext);
		previous->pNext = newElement;
		size++;
	}
}

template<typename T>
void List<T>::removeAt(int index)
{
	if (index > size)
	{
		throw MyException(1);
	}
	if (index == 0)
	{
		pop_front();
	}
	else
	{
		Element<T>* previous = this->head;
		for (int i = 0; i < index - 1; i++)
		{
			previous = previous->pNext;
		}

		Element<T>* toDelete = previous->pNext;
		previous->pNext = toDelete->pNext;
		delete toDelete;
		size--;
	}
}

template<typename T>
void List<T>::pop_back()
{
	removeAt(size - 1);
}

template<typename T>
void List<T>::printList()
{
	Element<T>* current = this->head;
	for (int i = 0; i < size; i++)
	{
		cout << i << ": " << current->data << endl;
		current = current->pNext;
	}
	cout << endl;
}

template<typename T>
void List<T>::findData(T data)
{
	Element<T>* current = this->head;
	int flg = 0;
	for (int i = 0; i < size; i++)
	{
		if (current->data == data)
		{
			cout << i << ": " << current->data << endl;
			flg = 1;
		}
		current = current->pNext;
	}
	if (flg == 0)
		cout << "There are no such elements " << endl;
	else
		cout << endl;
}

template<typename T>
void List<T>::comparing(string data, int Length)
{
	Element<string>* current = this->head;
	int flg = 0;
	int length = 0;
	int j = 0;

	if (Length == 1)
	{
		for (int i = 0; i < size; i++)
		{
			while (current->data[j] != '\0')
			{
				length++;
				j++;
			}
			for (j = 0; j < length; j++)
			{
				if (current->data[j] == data[0])
				{
					cout << i << ": " << current->data << endl;
					flg = 1;
				}
			}
			current = current->pNext;
			j = 0;
			length = 0;
		}
	}

	if (Length == 2)
	{
		for (int i = 0; i < size; i++)
		{
			while (current->data[j] != '\0')
			{
				length++;
				j++;
			}
			for (j = 0; j < length - 1; j++)
			{
				if (current->data[j] == data[0] && current->data[j + 1] == data[1])
				{
					cout << i << ": " << current->data << endl;
					flg = 1;
				}
			}
			current = current->pNext;
			j = 0;
			length = 0;
		}
	}

	if (Length == 3)
	{
		for (int i = 0; i < size; i++)
		{
			while (current->data[j] != '\0')
			{
				length++;
				j++;
			}
			for (j = 0; j < length - 2; j++)
			{
				if (current->data[j] == data[0] && current->data[j + 1] == data[1] && current->data[j + 2] == data[2])
				{
					cout << i << ": " << current->data << endl;
					flg = 1;
				}
			}
			current = current->pNext;
			j = 0;
			length = 0;
		}
	}
	
	if (flg == 0)
		cout << "There are no such elements " << endl;
	else
		cout << endl;
	
}

template<typename T>
T& List<T>::operator[](const int index)
{
	int counter = 0;
	Element<T>* current = this->head;
	while (current != nullptr)
	{
		if (counter == index)
		{
			return current->data;
		}
		current = current->pNext;
		counter++;
	}
	current->pNext = new Element<T>(data);
}

void printMenu()
{
	cout << "1 - choose type of element" << endl;
	cout << "2 - add element" << endl;
	cout << "3 - print list" << endl;
	cout << "4 - search element" << endl;
	cout << "5 - delete element" << endl;
	cout << "6 - find char with several letters" << endl;
	cout << "0 - exit" << endl;
}


int main()
{
	List<int> Int;
	List<double> Double;
	List<string> String;
	int option, type=0, addInt, index, length = 0;
	double addDouble;
	string addString;
	while (true)
	{
		try
		{
			printMenu();
			option = checkInt();
			switch (option)
			{
			default:
				break;
			case 1:
				system("cls");
				do
				{
					cout << "Choose type 1 - int, 2 - double, 3 - char" << endl;
					type = checkInt();
				} while (type < 1 || type>3);
				break;
			case 2:
				system("cls");
				if (type == 0)
					throw MyException(2);
				switch (type)
				{
				case 1:
					cout << "Enter integer data" << endl;
					addInt = checkInt();
					Int.push_back(addInt);
					break;
				case 2:
					cout << "Enter double data" << endl;
					addDouble = checkDouble();
					Double.push_back(addDouble);
					break;
				case 3:
					cout << "Enter string data" << endl;
					cin >> addString;
					String.push_back(addString);
					break;
				}
				break;
			case 3:
				system("cls");
				if (type == 0)
					throw MyException(2);
				switch (type)
				{
				case 1:
					Int.printList();
					break;
				case 2:
					Double.printList();
					break;
				case 3:
					String.printList();
					break;
				}
				break;
			case 4:
				system("cls");
				if (type == 0)
					throw MyException(2);
				switch (type)
				{
				case 1:
					cout << "Enter integer data" << endl;
					addInt = checkInt();
					Int.findData(addInt);
					break;
				case 2:
					cout << "Enter double data" << endl;
					addDouble = checkDouble();
					Double.findData(addDouble);
					break;
				case 3:
					cout << "Enter string data" << endl;
					cin >> addString;
					String.findData(addString);
					break;				
				}
				break;
			case 5:
				if (type == 0)
					throw MyException(2);
				system("cls");
				switch (type)
				{
				case 1:
					Int.printList();
					cout << "Enter index of data which you want to delete" << endl;
					index = checkInt();
					Int.removeAt(index);
					break;
				case 2:
					Double.printList();
					cout << "Enter index of data which you want to delete" << endl;
					index = checkInt();
					Double.removeAt(index);
					break;
				case 3:
					String.printList();
					cout << "Enter index of data which you want to delete" << endl;
					index = checkInt();
					String.removeAt(index);
					break;
				}
				break;
			case 6:
				if (type != 3)
					throw MyException(6);				
				system("cls");					
				do
				{
					int j = 0;
					length = 0;
					cout << "Enter three letters" << endl;
					cin >> addString;
					while (addString[j] != '\0')
					{
						length++;
						j++;
					}
				} while (length > 3);				
				String.comparing(addString, length);
				break;
			case 0:
				return 0;
			}
		}
		catch (MyException& ex)
		{
			system("cls");
			ex.answer();
			continuationCondition();
		}
	}
}

//поиск по трём буквам, несколько объектов в контейнере
