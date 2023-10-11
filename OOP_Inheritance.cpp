#include <iostream>


// Avoiding code duplication
// public, private, protected

/*
 class GenericBoard
{
		bool softwareInstaled = false;
		const char* name = "Undefined" ;
		friend class G3;
		friend class BB6631;

};


// 3 generation hardware
class G3 : public GenericBoard
{

public:
	G3()
	{
		name = "DUSG3";
		std::cout << "Creating G3 node" << std::endl;
	}
	const char* getName(){ return name;}
	
};

class BB6631 : public G3
{
	const char* label;
public:
	BB6631(const char* lb):label(lb)
	{
		name = "BB6631";
		std::cout << "Assigned label - "<< label << std::endl;
	}
	const char* getName(){ return name;}
};*/
  
class D 
{
public:
	int secter_number_3 = 42;
	D(){ std::cout << "Constructor D called "<< std::endl;}

};  

class A : virtual public D
{
public:
	int secter_number_1 = 42;
	A()
	{
		std::cout << "Constructor A called "<< std::endl;
	}

};

class B : virtual public D
{
public:	
	B()
	{
		std::cout << "Constructor B called "<< std::endl;
		secter_number_3 = 43;
		
	}
};

class C : public B, public A 
{

}; 



int main()
{
	//GenericBoard T;
	//BB6631 dus3_node("L78");
	
	//std::cout << dus3_node.getName() << std::endl;

 	C c;

	std::cout << "Public val from class A - " << c.secter_number_1 << std::endl;
	std::cout << "Public val from class B - " << c.secter_number_3 << std::endl;

	
	//std::cout << c.name << std::endl;

	return 0;    
}