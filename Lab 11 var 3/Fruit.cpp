#include "Fruit.h"

green::Fruit::Fruit()
{
	taste = "sweet";
}

green::Fruit::Fruit(string taste)
{
	this->taste = taste;
}

green::Fruit::~Fruit()
{
}

void green::Fruit::setTaste(string taste)
{
	this->taste = taste;
}

string green::Fruit::getTaste()
{
	return this->taste;
}

void green::Fruit::showTasteInfo()
{
	cout << "Fruit's taste is " << taste << endl;
}
