#include "Stick.h"

green::Stick::Stick()
{
	stick_length = 2;
}

green::Stick::Stick(int root_length, int age, std::string name, string color, string taste, int stick_length) : Root(root_length, age, name), Leaf(color), Fruit(taste)
{
	this->stick_length = stick_length;
}

green::Stick::~Stick()
{
}

void green::Stick::setStick_length(int stick_length)
{
	this->stick_length = stick_length;
}

int green::Stick::getStick_length()
{
	return stick_length;
}

void green::Stick::showStickInfo()
{
	cout << "Stick length is " << this->stick_length << " m" << endl;
}
