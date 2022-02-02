#pragma once
namespace green
{
	class Nest
	{
	private:
		int nestSize;
	public:
		Nest();
		Nest(int nestSize);
		~Nest();
		void setNestSize(int nestSize);
		int getNestSize();
		void showNestInfo();
	};
}

