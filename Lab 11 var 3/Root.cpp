#include "Root.h"

green::Root::Root()
{
	root_length = 50;
}

green::Root::Root(int root_length, int age, std::string name) : Plant(age, name)
{
	this->root_length = root_length;
}

green::Root::~Root()
{

}

void green::Root::setRoot_length(int root_length)
{
	this->root_length = root_length;
}

int green::Root::getRoot_length()
{
	return this->root_length;
}

void green::Root::showRootInfo()
{
	cout << "Root length is " << this->root_length<<" cm" << endl;
}
