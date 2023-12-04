#include<iostream>

void intTest(int val)
{
    std::cout << "is int" << std::endl;
};


void ptrTest(int val)
{
    std::cout << "int" << std::endl;
}
void ptrTest(void* val)
{
    std::cout << "void*" << std::endl;
} 
void ptrTest(std::nullptr_t val)
{
    std::cout << "nullptr_t" << std::endl;
} 


int main()
{
//nullptr; 

// IN ALL CASES actuall value is zero 
// 1. Case zero "0"   - *int* type
// 2. Case "NULL"     - !!implementation-defined!! Macro in curent case *long long* (mingw64)
//                      explicid casting to int fix the issue, otherwise ambiguous behaviour
// 3. Case "nullptr"  - std::nullptr_t defined type
//                      in considered by compiler as a totaly different type
//intTest(NULL);

ptrTest(nullptr);




return 0;
// https://gcc.gnu.org/onlinedocs/gcc/Warning-Options.html#index-Wconversion
// - Wconversion-null --> convertion to smaller type
}