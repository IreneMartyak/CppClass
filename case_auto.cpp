#include <iostream>
#include <array>
#include <typeinfo>
#include <cxxabi.h>
#include <vector>
struct A
{
    int a;
    int b;
};
struct B : public A
{
    int c;
};

// Deduction machanism 
template<class U>
void foo(U val) 
{
    std::cout << typeid(val).name() << std::endl;

}

int main()
{
// Can use c++filt for decoding
//
//  cd /msys64/mingw64/bin
//  ./c++filt.exe -t  [mangled names]


int a = 8;
auto b("string"); 
char c = 'A';
auto d = 8.7f; 
const auto i = 10;
auto* pa= &a;
auto& ra= a;

auto test = i; // !!

//auto smt = B{2,3};
//std::cout << smt.a << std::endl;
//https://itanium-cxx-abi.github.io/cxx-abi/abi.html#mangling-type
auto listValue = {1,2,3,4,5};



const std::array<int,7> arr = {1,2,3,4,5,0,0};

std::vector<int> v = {1,2,3,4,5};
// Case usage: to avoid writing long but obvious types, like iterators
auto bv = v.begin();
auto it = arr.end();
// Case usage: in for loops especialy instead of int

// some magic
int new_a = a;



foo(8.7f);
// Case usage: to guarantee type that function returns and not perform implicid casting



//std::cout << val << std::endl;

return 0;
}