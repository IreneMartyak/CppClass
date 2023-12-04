#include<iostream>
#include<initializer_list>
#include<typeinfo>

template<typename T>
void foo(T param)
{
    std::cout << typeid(param).name()  << std::endl;
}

int main()
{
  
auto el = {1,2,3,4,5};

auto ii = el.begin();

std::cout << el.size()  << std::endl;


foo(el);
    return 0;
}

