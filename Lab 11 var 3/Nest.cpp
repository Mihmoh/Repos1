#include "Nest.h"
#include <string>
#include <iostream>

green::Nest::Nest()
{
	this->nestSize = 5;
}

green::Nest::Nest(int NestSize)
{
	this->nestSize = NestSize;
}

green::Nest::~Nest()
{

}

void green::Nest::setNestSize(int NestSize)
{
	this->nestSize = NestSize;
}

int green::Nest::getNestSize()
{
	return this->nestSize;
}



void green::Nest::showNestInfo()
{
	std::cout << "Nest size: " << this->nestSize<< " cm" << std::endl;
}
