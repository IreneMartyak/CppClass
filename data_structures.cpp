#include<iostream>

int main()
{

	//struct
	struct DataStructs
	{
		int a =10;
		int b =5;
		char g;
		char c = 'h';
	};
	union Letter
	{
		int  a;
		char b;	
	};

	Letter letter = {'H'};
	DataStructs sturc;

	std::cout << letter.b  << std::endl;

	std::cout << "Test" << std::endl;


	return 0;
}