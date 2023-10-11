#include<iostream>
//__argv, __argc

//===-----------------------------------------------------------------===//
   int p;  // - "declaration of a var named "p" of int(4 byte typically) type  
//===-----------------------------------------------------------------===//

// So, pointers....
    int* p1 ; 
    int *p2 ;                // What is the difference ?
    //int  p3*;
    //*int  p4 ;    

//And pointer to a ...pointer !

    int** pp1 ; 
    int* *pp2 ;         // What is the difference ?
    int **pp3 ;



 class Menu{
    private:
       int _numParameters{0};
       char *(*(Parameters)) = nullptr;
    public:
        const char* name = "Something";
        

    ~Menu()
    {
         std::cout << "" << std::endl;
    }
    Menu(const char* n):name{n}, _numParameters{__argc},_Parameters{__argv}
    {
        // Do some cheks
    }
    void getParams()
    {
         std::cout << "Numbers of parameters passed to program is: " <<  _numParameters << std::endl;
         //std::cout << "Thouse parameters are: " << *_Parameters << std::endl;
    }

}; 



int main() //int argc, char* argv[], char** env
{
    // pointer arythmetics and indexing array
    // array decay to pointer
    int array[5]= {1,2,3,4,5};
    int *pa = nullptr; 
    int a = 5;

    pa = array;
    


    //std::cout << sizeof(int)    << std::endl;

    //std::cout << sizeof(pa)    << std::endl;
    //std::cout << sizeof(array) << std::endl; 
    //int& addres = &a;
    //std::cout << "Vartosc na ktora wskazuje "<< *(pa+7)   << std::endl;
    //std::cout << "Adress, wlasnie wartoscia " << pa << std::endl;
    //std::cout << "Adres na ktorym lezy "<< &pa << std::endl;
    //std::cout << pa << std::endl;
    
    //Menu arguments("My_set_of_data");
    Menu *otherArgs ;
    //otherArgs->name = "Other_set";
    

    //std::cout << "Our first set of arguments from the system name: " << arguments.name << std::endl;
    std::cout << "Our custom one name: " << otherArgs->name << std::endl; //   (*otherArgs).name
    




    //std::cout << *__argv << std::endl; */

    return 0;
}