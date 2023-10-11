#include <iostream>
#include <functional>

int add(int a, int b)
{
	return a+b;
}



void printStars(int n)
{
	for(int i=0;i<n;i++)
	{
		std::cout << '*';
	}
	std::cout << std::endl;
}
//int (*pointer1)(int,int)=add
auto *pointer1 = add;


  *p_log
 //*p_print


 
void swap(int* a, int* b, bool(*funk)(void))
{
	int temp{0};

	/*if( funk() )
	{
		temp = *a;
		*a = *b ;
		*b = temp;
	}else{
		std::cout << "No swap, smth went wrong..." << std::endl;
	}*/

	std::cout << getLog() << std::endl;

}

const char* getLog()
{
	return "Some log to pass.";
}

bool prindVal()
{
    std::cout << "Calling a func." << std::endl;
	return true;
} 

int main()
{
	int a = 5, b = 7, c = 0;
    const char* (*p_log) () = getLog;
	//bool (*printFunk)() = prindVal;
	
    
	swap(&a, &b, prindVal);



	
	std::function<int(int,int)> add_number = add;
    
	//std::cout << std::endl;

	

	return 0;
}  