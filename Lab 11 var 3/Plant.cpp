#include "Plant.h"

green::Plant::Plant()
{
	{
		age = 10;
		name = "Cherry";
	}
}

green::Plant::Plant(int age, std::string name)
{
	{
		this->age = age;
		this->name = name;
	}
}

green::Plant::~Plant()
{
}

void green::Plant::setAge(int age)
{
	this->age = age;
}

void green::Plant::setName(std::string name)
{
	this->name = name;
}

int green::Plant::getAge()
{
	return this->age;
}

std::string green::Plant::getName()
{
	return this->name;
}

void green::Plant::showInfo()
{
	std::cout << "Name: " << this->name <<std::endl<< "Age: " << this->age << std::endl;
}

void green::Plant::inspectNest()
{
	this->nest.showNestInfo();
}

void green::Plant::changeNest()
{
	int newSize;
	cout << "Enter new size of nest" << endl;
	cin >> newSize;
	nest.setNestSize(newSize);
}

void green::Plant::searchPlant(int age, std::string name)
{

}
