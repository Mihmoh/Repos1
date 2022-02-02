#pragma once

#include <string>
#include <iostream>
#include "Nest.h"
using namespace std;

namespace green
{
	class Plant
	{
	protected:
		int age;
		std::string name;
		Nest nest;
		
	public:
		Plant();
		Plant(int age, std::string name);
		~Plant();
		void setAge(int age);
		void setName(std::string name);
		int getAge();
		std::string getName();
		void showInfo();
		void inspectNest();
		void changeNest();
		void searchPlant(int age, std::string name);
	};
}

