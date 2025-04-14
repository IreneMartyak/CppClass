#include <iostream>
#include <array>

std::array<int,7> v{1};
struct One
{
    void print(){std::cout << "One printed\n";};
};

struct Two
{
    void print(){std::cout << "Two printed\n";};
};

struct Three
{
    void print(){std::cout << "Three printed\n";};
};

//It's a variadic macro. It means you can call it with any number of arguments. 
//The three ... is similar to the same construct used in a variadic function in C
#define fw(...) std::forward<decltype(__VA_ARGS__)>(__VA_ARGS__)


template <typename... T> 
auto sum(T... t)
{  
    typename std::common_type<T...>::type result{};
    (void)std::initializer_list<int>{ (result += t, 0)... };
    return result;
};

// better version
template <typename... T> 
auto sum2(T... t)
{  
    return (t+ ...);
};

int main()
{
    One one;
    Two two;
    Three three;
    std::cout << sum(1,2,3.4,10) << "\n";
    std::cout << sum2(1,2,3.4,10) << "\n";
    

    auto pr = [](auto&&... args){ (fw(args).print(), ...); };
    pr(one,two, three);
    return 0;
}