#pragma once
#include <string>
#include <iostream>
using namespace std;

namespace green
{
	class Fruit
	{
	protected:
		string taste;
	public:
		Fruit();
		Fruit(string taste);
		~Fruit();
		void setTaste(string taste);
		string getTaste();
		void showTasteInfo();
	};

}