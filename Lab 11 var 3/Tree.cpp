#include "Tree.h"

green::Tree::Tree()
{
	trunk = 1.5;
}

green::Tree::Tree(int root_length, int age, std::string name, string color, string taste, int stick_length, double trunk) : Stick(root_length, age, name, color, taste, stick_length)
{
	this->trunk = trunk;
}

green::Tree::~Tree()
{
}

void green::Tree::setTrunk_length(int trunk)
{
	this->trunk = trunk;
}

double green::Tree::getTrunk_length()
{
	return trunk;
}

void green::Tree::showTrunkInfo()
{
	cout << "Truck length is " << this->trunk << " m" << endl;
}

bool green::Tree::operator==(const Tree other)
{
	if (this->age == other.age && this->color == other.color && this->name == other.name && this->root_length == other.root_length && this->stick_length == other.stick_length && this->root_length == other.root_length && this->taste == other.taste && this->trunk == other.trunk)
		return true;
	else
		return false;
}


