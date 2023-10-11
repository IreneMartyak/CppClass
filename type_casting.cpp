#include <iostream>
#include <typeinfo>
#include <utility>
#include <array>

#include <string>
#include <vector> 


class A
{
public:
	int param1;
};

class B : public A
{
public:
	int param1;
	double param2;
};
int retMul(int *m)
{
	*m = 10;
	return (*m)*(*m);
}

int main()
{
	int integer = 35;
	double doublevalue = 3.1415;
	char character = 'a';



	//Case 0: C style casting

	 
	//std::cout << (int)doublevalue << std::endl; //value was truncated
	//std::cout << (double)integer  << std::endl;
	
	//Case 1: simple type casting
	
	double test1 = static_cast<double>(integer);

	//std::cout << test1  << std::endl;
	//std::cout << typeid(test1).name()  << std::endl;
	

	char test3 = static_cast<char>(integer);

	//std::cout << test3  << std::endl;
	//std::cout << typeid(test3).name()  << std::endl;
	std::cout << "|===-------------------------------===|" << std::endl;

	//Case 2: data structures casting

	/*B obj1;
	obj1.param1 = 5;
	A newObj = static_cast<A>(obj1);
	*/


	// Scallar type, whats that ?
    //
	// Scalar type: A type that holds a single value of a defined range. 
    //
	//  https://en.cppreference.com/w/cpp/named_req/ScalarType

    /* 	The following types are collectively called scalar types:

		1. arithmetic types 
		2. enumeration types
		3. pointer types
		4. pointer-to-member types
		5. std::nullptr_t
		6. cv(const and volatile)- qualified versions of these types */
	//===-------------------------------===	
	// So int, double, char is ??
	// Why ?
	//===-------------------------------===
	// Hmmmm, and char[10] is ?
	//
	//===-------------------------------===
	// How about containers like std::string or std::vector<int> ?
	//
	//===-------------------------------===
	// Yeah and classes ?
	//
	//===-------------------------------===
	// Now wait a minute, that cv thing, like const int* ?
	//
	
	/*if( std::is_scalar_v<void> )
	{
		std::cout << "Current type is scallar \nSo we can use \"static_cast\""  << std::endl;
	}else{
		std::cout << "This type IS NOT scallar" << std::endl;
	}*/
	

	// Safely converts pointers and references to classes up, down, and sideways along the inheritance hierarchy.
	B obj1;
	obj1.param1 = 10;
	A newObj = dynamic_cast<A&>(obj1);
	//A *objpointer = &(obj1);

	std::cout << newObj.param1 << std::endl;

	//  const_cast
    // In any program, const_cast can be used to pass constant data to another function that does not accept constant data.
	const int var = 5;

    int res = retMul(const_cast<int *>(&var));

	
	std::cout << var << std::endl;


	return 0;
}

	


	/*std::cout << "|===-------------------------------===|" << std::endl;
	std::cout << "| Typesize according to curent system |" << std::endl; 
	std::cout << "|===-------------------------------===|" << std::endl;
	std::cout << "|  Integer size: "<< sizeof(integer)     << std::endl;
	std::cout << "|  Double  size: "<< sizeof(doublevalue) << std::endl;
    std::cout << "|  Char    size: "<< sizeof(character)   << std::endl;
	std::cout << "|===-------------------------------===|" << std::endl; */