#include "Leaf.h"

green::Leaf::Leaf()
{
	color = "green";
}

green::Leaf::Leaf(string color)
{
	this->color = color;
}

green::Leaf::~Leaf()
{
}

void green::Leaf::setColor(string color)
{
	this->color = color;
}

string green::Leaf::getColor()
{
	return this->color;
}

void green::Leaf::showLeafInfo()
{
	cout << "Color of leaves is " << this->color << endl;
}



