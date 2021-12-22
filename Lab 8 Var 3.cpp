#include <iostream>
#include <string>
using namespace std;

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
	MyException(int except) : excep{except}
	{

	}
	void answer()
	{
		switch (excep)
		{
		case 1:
			cout << "Stack is not created" << endl;
			break;
		}
	}
};

class stack
{
private:
	int number;
	string name;
	
public:
	stack* pointerNext;

	stack* creator(stack* pointerHead)
	{
		int counter = 0, number = 0, end = 1;
		stack* pointerPrevious;
		system("CLS");
		printf("Creating a stack :\n");
		do
		{
			pointerPrevious = pointerHead;
			if (!(pointerHead = new stack))
			{
				printf("No memory.");
				return pointerHead;
			}
			counter++;

			cout << "Enter number" << endl;
			pointerHead->number = checkInt();
			cout << "Enter name" << endl;
			cin >> pointerHead->name;
			
			printf("1 - continue\n0 - stop\n");
			end = checkInt();
			system("cls");

			pointerHead->pointerNext = pointerPrevious;

		} while (end != 0);
		return pointerHead;
	}

	void output(stack* pointerHead)
	{
		stack* pointerPrevious;
		pointerPrevious = pointerHead;
		system("CLS");
		if (pointerHead == nullptr)
		{
			throw MyException(1);
		}

		while (true)
		{
			cout<<"Number " << pointerPrevious->number << endl;
			cout<< "Name " << pointerPrevious->name << endl;
			pointerPrevious = pointerPrevious->pointerNext;
			if (pointerPrevious == nullptr)
				break;
		}
		continuationCondition();
	}

	void search(stack* pointerHead)
	{
		if (pointerHead == nullptr)
		{
			throw MyException(1);
		}
		int numb = 0;
		int choose = 0;
		stack* pointerPrevious;
		pointerPrevious = pointerHead;
		cout << "1 - number 2 - name" << endl;
		choose = checkInt();
		switch (choose)
		{
		case 1:
			
			printf("Enter number which you want to find:\n");
			numb = checkInt();
			while (pointerPrevious != nullptr) {
				if (pointerPrevious->number == numb) {
					cout<<"\nNumber " << pointerPrevious->number << endl;
					cout<< "Name " << pointerPrevious->name << endl;
				}
				pointerPrevious = pointerPrevious->pointerNext;
			}
			continuationCondition();
			break;
		case 2:
			string  str;
			printf("Enter name which you want to find:\n");
			cin >> name;
			while (pointerPrevious != nullptr) {
				if (pointerPrevious->name == name) {
					cout << "Number " << pointerPrevious->number << endl;
					cout << "Name " << pointerPrevious->name << endl;
				}
				pointerPrevious = pointerPrevious->pointerNext;
			}
			continuationCondition();
			break;
		}
	}

	stack* deleteStack(stack* pointerPrevious, stack* pointerHead)
	{
		int number = 0;
		stack* pointerDel = nullptr;
		stack* pointerNotDel = nullptr;
		printf_s("Are you sure?\n1.Yes\n2.No\n");
		number = checkInt();
		/*do {
			number = checkInt();
			if (number > 3 || number < 0) {
				printf("Incorrect input. Try again.");
				continuationCondition();
				system("CLS");
				printf_s("Are you sure?\n1.Yes\n2.No\n");
				continue;
			}
		} while (true);*/
		if (number == 2)
			return pointerHead;
		pointerNotDel = pointerHead;
		if (pointerNotDel == pointerPrevious) //если нужно удалить первый элемент
		{
			if (pointerPrevious->pointerNext != nullptr) //если есть больше одного
			{
				pointerHead = pointerPrevious->pointerNext;
				free(pointerNotDel);
				return pointerHead;
			}
			else //если есть всего один элемент
			{

				free(pointerNotDel);
				pointerHead = nullptr;
				return pointerHead;
			}
		}
		else //если нужно удалить не первый элемент
		{
			while (pointerNotDel->pointerNext != pointerPrevious)
			{
				pointerNotDel = pointerNotDel->pointerNext;
			}
			pointerDel = pointerNotDel->pointerNext;
			pointerNotDel->pointerNext = pointerDel->pointerNext;
			free(pointerDel);
			return pointerHead;
		}
	}

	stack* findStackForDelete(stack* pointerHead)
	{
		int  numb = 0;
		if (pointerHead == nullptr)
		{
			throw MyException(1);
		}
		int choose = 0;
		stack* pointerPrevious;
		pointerPrevious = pointerHead;
		printf("Find by number - 1; find by name - 2:\n");
		choose = checkInt();
		switch (choose)
		{
		case 1:
			numb = 0;
			printf("Enter the number you want to find:\n");
			numb = checkInt();
			system("CLS");
			while (pointerPrevious != nullptr)
			{
				if (pointerPrevious->number == numb)
				{
					cout << "Number " << pointerPrevious->number << endl;
					cout << "Name " << pointerPrevious->name << endl;
					printf("\nThis the element, which you want to delete\n");
					continuationCondition();
					pointerHead = deleteStack(pointerPrevious, pointerHead);
					return pointerHead;
				}
				pointerPrevious = pointerPrevious->pointerNext;
			}
			break;
		case 2:
			string  str;
			printf("Enter name which you want to find:\n");
			cin >> name;
			while (pointerPrevious != nullptr) {
				if (pointerPrevious->name == name) {
					cout << "Number " << pointerPrevious->number << endl;
					cout << "Name " << pointerPrevious->name << endl;
					printf("\nThis the element, which you want to delete\n");
					continuationCondition();
					pointerHead = deleteStack(pointerPrevious, pointerHead);
					return pointerHead;
				}
				pointerPrevious = pointerPrevious->pointerNext;
				
			}
			break;
		}
	}
};








int main()
{
	stack object;
	int option = 100;
	while (true)
	{
		system("CLS");
		printf_s("List of possible actions:\n1.Create a stack.\n2.Print a stack.\n3.Search info.\n4.Delete by given parameter.");
		printf_s("\n0.Exit.");
		printf("\nWrite number: ");
		option = checkInt();
		switch (option)
		{
		case 1:
			object.pointerNext = object.creator(object.pointerNext);
			break;
		case 2:
			try
			{
				object.output(object.pointerNext);
			}
			catch(MyException &ex)
			{
				system("cls");
				ex.answer();
				continuationCondition();
			}
			break;
		case 3:
			try
			{
				object.search(object.pointerNext);
			}
			catch (MyException& ex)
			{
				system("cls");
				ex.answer();
				continuationCondition();
			}
			break;
		case 4:
			try
			{
				object.pointerNext = object.findStackForDelete(object.pointerNext);
			}
			catch (MyException& ex)
			{
				system("cls");
				ex.answer();
				continuationCondition();
			}
			break;
		case 0:
			return 0;
		}
	}
	
}
