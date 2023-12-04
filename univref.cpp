#include<iostream>
#include<utility>

struct C
{
    int val = 10; 
};
// pass value without creating a copy
// bind to everything
void foo(const int& x)
{
    std::cout << "wszystkie wartosci" << std::endl;
}
// pass named entity to  return a value
// only non const lvalue
void foo(int& x)
{
    std::cout << "non-const lvalue" << std::endl;
}
// pass value that is no longer needed
// only non const rvalue or moved
void foo(int&& x)// 
{
    std::cout << "non-const rvalue" << std::endl;
    
}

void foo(int&& x, int&& y)// 
{
    std::cout << "non-const rvalue 2x" << std::endl;
    
}
void foo (int&& x, int& y) 
{
    std::cout << "non-const rvalue amd lvalue 2x" << std::endl;
    
}

//lets call foo
template<typename ...T>  
void callFoo(T&&... x)  //&&1el &l
{
    //std::cout << x << std::endl;
    
    foo(std::forward<T>(x) ...); // Forward as lvalue or as rvalue, depending on T

    
}
 
int main()
{

    
C v;
const C c;
/*foo(v);
foo(c);
foo(C{});*/
//foo(std::move(v)); 
int l = 9;
callFoo(9, l);





return 0;
}