#pragma once
#include <string>
#include <iostream>
using namespace std;

namespace green
{
	class Leaf
	{
	protected:
		string color;
	public:
		Leaf();
		Leaf(string color);
		~Leaf();
		void setColor(string color);
		string getColor();
		void showLeafInfo();
	};

}