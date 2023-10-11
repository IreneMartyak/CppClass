
#include <iostream>
#include <string>
#include <folly>

#define MESSAGE "This macro is considered to be often changed"
using namespace std;

//own namespace
namespace my_namespace{
	int age = 25;
}

using std::cout;
using std::cin;
using std::endl;


int main()
{
	int condition = 1;
    std::string
	folly::string 
	
	//==---------------------------------------------==//
	//  https://en.cppreference.com/w/cpp/language/if  //
	//==---------------------------------------------==//

	// simple IF construction
/* 	if (condition)
		statement-true;

    // IF-ELSE construction
	if (condition)
	{
		statement-true;
		with more then one line;
	}else{
		statement-false;
	} */

	//==-------------------------------------------------==//
	//  https://en.cppreference.com/w/cpp/language/switch  //
	//==-------------------------------------------------==//

	// CASE construction
/* 	switch (condition) 
	{
		case 1:
			std::cout << '1'; 
			break;            
		case 2:
			std::cout << '2';
			break; 
		default:
            std::cout << "Unknown choise..." ;
	} */

	/* continie and brake specific example - loop controle
	for(int i=0; i<=16; i++)
	{
		if(i%2 == 0)
			continue;
        if(i == 15)
            std::exit(EXIT_SUCCESS);
		std::cout << "Value: " << i  << std::endl;
	}*/
    int age =20;
    cout << my_namespace::age << " -- " << age << endl;
   // cout << i << std::endl;


	std::string msg; 

 // return in main
 return 0; 
}