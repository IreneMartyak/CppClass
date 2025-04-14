#include<iostream>
#include<typeinfo>
#include<type_traits>
#include<cxxabi.h> //for demangling

template <typename T> 
void staticcast_info(const T& value) 
{ 
    int status; 
    std::cout << abi::__cxa_demangle(typeid(T).name(), 0, 0, &status); 

    if constexpr(std::is_scalar_v<T>)
    {   std::cout << " type is scallar. So we can use \"static_cast\""  << std::endl;   }
    else
    {  std::cout <<  " type IS NOT scallar" << std::endl;  }
}
int main()
{
    char tab[10]{};
    void *ptr = nullptr;

    staticcast_info(tab);
    staticcast_info(ptr);

    return 0;
}