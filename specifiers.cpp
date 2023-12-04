#include <iostream>
#include <array>
#include <type_traits>
#include <vector>

constexpr int foo(int&& value) noexcept
{
    int a = 10;
    // do smth here
    return value*value+a;
}


int main()
{
 int ci = 10, &cj = ci;
// decltype  
///decltype(ci+ci) x = 0 ;
//decltype(cj) y = x ;

//noexept
auto result = foo(10);
int inp;
std::cin >> inp;

constexpr int x = 1 + 1 ;

std::array<int,4> va = {1,2,3};
inp = va[2];
static_assert(x > 0, "should be positive." );
std::vector<int> vt = {1,3,6,9};
vt.push_back(14);


    return 0;
}

