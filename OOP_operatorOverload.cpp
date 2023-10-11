#include <iostream>
#include <string>

//operator overload


// 2x2 matrix representation
// Indexation overload
// I/O overload

class QuadMatrix
{
	int mx[2][2] = {0,0,0,0};

public:
	QuadMatrix(int a, int b, int c, int d):mx{{a, c},{b,d}}
	{
	
	}
	void printVal()
	{
		std::cout << "┌" << "   "      << "┐" << std::endl;
		std::cout << "|" << mx[0][0] << " "<< mx[1][0] <<"|" << std::endl;
		std::cout << "|" << mx[0][1] << " "<< mx[1][1] <<"|" << std::endl;
		std::cout << "└" <<  "   "     << "┘" << std::endl;
		
	}
    
	void operator+(QuadMatrix other){
		mx[0][0]+=other.mx[0][0];
		mx[0][1]+=other.mx[0][1];
		mx[1][0]+=other.mx[1][0];
		mx[1][1]+=other.mx[1][1];	
	}

	
	const int operator[](int index) const
	{
		switch(index){
			case 0:
				return mx[0][0];
			case 1:
				return mx[1][0];
			case 2:
				return mx[0][1];
			case 3:
				return mx[1][1];
			default:
				std::cout << "Out of bouds..." ;
		}
	return -1;	
	}

};

 std::ostream& operator<<(std::ostream& os, const QuadMatrix& matrix ) 
{
	os << "┌" << "   "      << "┐\n"; 
	os << "|" << matrix[0] << " "<< matrix[1] <<"|\n";
	os << "|" << matrix[2] << " "<< matrix[3] <<"|\n" ;
	os << "└" <<  "   "     << "┘\n" ;
	return os;
}


int main() 
{
	QuadMatrix A(1,3,0,0), B(0,2,2,1);
	

	//A.printVal();
	//B.printVal();

    A+B;

	//A.printVal();

    
	
	std::cout << A[3] << std::endl;
	return 0;
}