#include "Tree.h"

using namespace std;
using namespace green;

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


class List
{
public:
	List();
	~List();

	void push_back();
	void pop_front();
	void clear();
	/*void push_front(T data);
	void insert(T data, int index);*/
	void removeAt(int index);
	void pop_back();
	void printList();
	void findData(int index);
	void findIntData(int data, int index);
	void findStringData(string data, int index);
	int getSize() { return size; }
	Tree& operator[](const int index);

private:

	class Element
	{
	public:
		Element* pNext;
		Tree data;
		int index;

		Element(Tree data = Tree(), Element* pNext = nullptr)
		{
			this->data = data;
			this->pNext = pNext;
		}

	};

	Element* head;
	int size;

};


List::List()
{
	size = 0;
	head = nullptr;
}


List::~List()
{
	clear();
}



void List::push_back()
{
	int Int;
	double Double;
	string String;
	if (head == nullptr)
	{
		head = new Element;
		head->index = 0;
		cout << "Enter age of tree" << endl;
		Int = checkInt();
		head->data.setAge(Int);
		cout << "Enter name of tree" << endl;
		cin >> String;
		head->data.setName(String);
		head->data.changeNest();
		cout << "Enter root length of tree" << endl;
		Int = checkInt();
		head->data.setRoot_length(Int);
		cout << "Enter leaf color" << endl;
		cin >> String;
		head->data.setColor(String);
		cout << "Enter fruit taste" << endl;
		cin >> String;
		head->data.setTaste(String);
		cout << "Enter stick length of tree" << endl;
		Int = checkInt();
		head->data.setStick_length(Int);
		cout << "Enter truck length of tree" << endl;
		Int = checkInt();
		head->data.setTrunk_length(Int);
	}
	else
	{
		Element* current = this->head;
		int previousIndex = 0;
		previousIndex = current->index;
		while (current->pNext != nullptr)
		{			
			current = current->pNext;
			previousIndex = current->index;
		}		
		current->pNext = new Element;
		current->pNext->index = previousIndex + 1;
		cout << "Enter age of tree" << endl;
		Int = checkInt();
		current->pNext->data.setAge(Int);
		cout << "Enter name of tree" << endl;
		cin >> String;
		current->pNext->data.setName(String);
		current->pNext->data.changeNest();
		cout << "Enter root length of tree" << endl;
		Int = checkInt();
		current->pNext->data.setRoot_length(Int);
		cout << "Enter leaf color" << endl;
		cin >> String;
		current->pNext->data.setColor(String);
		cout << "Enter fruit taste" << endl;
		cin >> String;
		current->pNext->data.setTaste(String);
		cout << "Enter stick length of tree" << endl;
		Int = checkInt();
		current->pNext->data.setStick_length(Int);
		cout << "Enter truck length of tree" << endl;
		Int = checkInt();
		current->pNext->data.setTrunk_length(Int);
	}
	size++;
}


void List::pop_front()
{
	Element*temp = head;
	head = head->pNext;
	delete temp;
	size--;
}

void List::clear()
{
	while (size)
	{
		pop_front();
	}
}

//template<typename T>
//void List<T>::push_front(T data)
//{
//	head = new Element<T>(data, head);
//	size++;
//}

//template<typename T>
//void List<T>::insert(T data, int index)
//{
//	if (index == 0)
//	{
//		push_front(data);
//	}
//	else
//	{
//		Element<T>* previous = this->head;
//		for (int i = 0; i < index - 1; i++)
//		{
//			previous = previous->pNext;
//		}
//
//		Element<T>* newElement = new Element<T>(data, previous->pNext);
//		previous->pNext = newElement;
//		size++;
//	}
//}


void List::removeAt(int index)
{
	Element* previous = this->head;
	
	if (index == previous->index)
	{
		pop_front();
	}
	else
	{		
		while (previous->pNext != nullptr )
		{
			if (index == previous->pNext->index)
				break;
			previous = previous->pNext;
		}

		if (previous->pNext != nullptr)
		{
			Element* toDelete = previous->pNext;
			previous->pNext = toDelete->pNext;
			delete toDelete;
			size--;
		}
	}
}


void List::pop_back()
{
	removeAt(size - 1);
}


void List::printList()
{
	Element* current = this->head;
	for (int i = 0; i < size; i++)
	{
		cout<<"[" << current->index << "] " << endl;
		current->data.showInfo();
		current->data.inspectNest();
		current->data.showRootInfo();
		current->data.showLeafInfo();
		current->data.showTasteInfo();
		current->data.showStickInfo();
		current->data.showTrunkInfo();
		cout << "_____________________" << endl;
		current = current->pNext;
	}
	cout << endl;
}


void List::findData(int index)
{
	Element* current = this->head;
	int flg = 0;
	for (int i = 0; i < size; i++)
	{
		if (i == index)
		{
			current->data.showInfo();
			current->data.inspectNest();
			current->data.showRootInfo();
			current->data.showLeafInfo();
			current->data.showTasteInfo();
			current->data.showStickInfo();
			current->data.showTrunkInfo();
			flg = 1;
		}
		current = current->pNext;
	}

	if (flg == 0)
		cout << "There are no such elements " << endl;
	else
		cout << endl;
}

void List::findIntData(int data, int index)
{
	Element* current = this->head;
	int flg = 0;
	switch (index)
	{
	case 1:
		for (int i = 0; i < size; i++)
		{
			if (current->data.getAge() == data)
			{
				current->data.showInfo();
				current->data.inspectNest();
				current->data.showRootInfo();
				current->data.showLeafInfo();
				current->data.showTasteInfo();
				current->data.showStickInfo();
				current->data.showTrunkInfo();
				flg = 1;
			}
			current = current->pNext;
		}

		if (flg == 0)
			cout << "There are no such elements " << endl;
		else
			cout << endl;
		break;
	case 3:
		for (int i = 0; i < size; i++)
		{
			if (current->data.getRoot_length() == data)
			{
				current->data.showInfo();
				current->data.inspectNest();
				current->data.showRootInfo();
				current->data.showLeafInfo();
				current->data.showTasteInfo();
				current->data.showStickInfo();
				current->data.showTrunkInfo();
				flg = 1;
			}
			current = current->pNext;
		}

		if (flg == 0)
			cout << "There are no such elements " << endl;
		else
			cout << endl;
		break;
	case 6:
		for (int i = 0; i < size; i++)
		{
			if (current->data.getStick_length() == data)
			{
				current->data.showInfo();
				current->data.inspectNest();
				current->data.showRootInfo();
				current->data.showLeafInfo();
				current->data.showTasteInfo();
				current->data.showStickInfo();
				current->data.showTrunkInfo();
				flg = 1;
			}
			current = current->pNext;
		}

		if (flg == 0)
			cout << "There are no such elements " << endl;
		else
			cout << endl;
		break;
	case 7:
		for (int i = 0; i < size; i++)
		{
			if (current->data.getTrunk_length() == data)
			{
				current->data.showInfo();
				current->data.inspectNest();
				current->data.showRootInfo();
				current->data.showLeafInfo();
				current->data.showTasteInfo();
				current->data.showStickInfo();
				current->data.showTrunkInfo();
				flg = 1;
			}
			current = current->pNext;
		}

		if (flg == 0)
			cout << "There are no such elements " << endl;
		else
			cout << endl;
		break;
	}


	
}

void List::findStringData(string data, int index)
{
	Element* current = this->head;
	int flg = 0;
	switch (index)
	{
	case 2:
		for (int i = 0; i < size; i++)
		{
			if (current->data.getName() == data)
			{
				current->data.showInfo();
				current->data.inspectNest();
				current->data.showRootInfo();
				current->data.showLeafInfo();
				current->data.showTasteInfo();
				current->data.showStickInfo();
				current->data.showTrunkInfo();
				flg = 1;
			}
			current = current->pNext;
		}

		if (flg == 0)
			cout << "There are no such elements " << endl;
		else
			cout << endl;
		break;
	case 4:
		for (int i = 0; i < size; i++)
		{
			if (current->data.getColor() == data)
			{
				current->data.showInfo();
				current->data.inspectNest();
				current->data.showRootInfo();
				current->data.showLeafInfo();
				current->data.showTasteInfo();
				current->data.showStickInfo();
				current->data.showTrunkInfo();
				flg = 1;
			}
			current = current->pNext;
		}

		if (flg == 0)
			cout << "There are no such elements " << endl;
		else
			cout << endl;
		break;
	case 5:
		for (int i = 0; i < size; i++)
		{
			if (current->data.getTaste() == data)
			{
				current->data.showInfo();
				current->data.inspectNest();
				current->data.showRootInfo();
				current->data.showLeafInfo();
				current->data.showTasteInfo();
				current->data.showStickInfo();
				current->data.showTrunkInfo();
				flg = 1;
			}
			current = current->pNext;
		}

		if (flg == 0)
			cout << "There are no such elements " << endl;
		else
			cout << endl;
	}
}


Tree& List::operator[](const int index)
{
	int counter = 0;
	Element* current = this->head;
	while (current != nullptr)
	{
		if (counter == index)
		{
			return current->data;
		}
		current = current->pNext;
		counter++;
	}
	current->pNext = new Element;
}

void printMenu()
{
	cout << "1 - add element" << endl;
	cout << "2 - print list" << endl;
	cout << "3 - search element" << endl;
	cout << "4 - delete element" << endl;
	cout << "5 - find by field element" << endl;
	cout << "0 - exit" << endl;
}


int main()
{
	List tree;
	int option, type = 0, addInt, index, i=0, Size=0;
	int* mas_index;
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
				tree.push_back();					
				break;
			case 2:
				system("cls");				
				tree.printList();
				break;
			case 3:
				system("cls");				
				cout << "Enter index which you want to find" << endl;
				addInt = checkInt();
				tree.findData(addInt);
				break;
			case 4:
				system("cls");
				tree.printList();
				Size = tree.getSize();
				mas_index = new int[Size];
				i = 0;
				for (i = 0; i < Size; i++)
				{
					cout << "Enter indexes of data which you want to delete" << endl;
					cout << "Enter -1 to stop entering" << endl;
					mas_index[i] = checkInt();
					if (mas_index[i] == -1)
						break;
				}
				for (int g = 0; g < i; g++)
				{
					tree.removeAt(mas_index[g]);
				}
				
				break;
			case 5:
				system("cls");
				cout << "Enter type of data which you want to find" << endl;
				cout << "1 - age, 2 - name, 3 - root length, 4 - color, 5 - taste, 6 - stick length, 7 - trunk length" << endl;
				index = checkInt();
				switch (index)
				{
				case 1:
					cout << "Enter age which you want to find" << endl;
					addInt = checkInt();
					tree.findIntData(addInt, index);
					break;
				case 2:
					cout << "Enter name which you want to find" << endl;
					cin >> addString;
					tree.findStringData(addString, index);
					break;
				case 3:
					cout << "Enter root length which you want to find" << endl;
					addInt = checkInt();
					tree.findIntData(addInt, index);
					break;
				case 5:
					cout << "Enter taste which you want to find" << endl;
					cin >> addString;
					tree.findStringData(addString, index);
					break;
				case 4:
					cout << "Enter color which you want to find" << endl;
					cin >> addString;
					tree.findStringData(addString, index);
					break;
				case 6:
					cout << "Enter stick length which you want to find" << endl;
					addInt = checkInt();
					tree.findIntData(addInt, index);
					break;
				case 7:
					cout << "Enter trunk length which you want to find" << endl;
					addInt = checkInt();
					tree.findIntData(addInt, index);
					break;
				}
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

//поиск по любому полю, удаление нескольких