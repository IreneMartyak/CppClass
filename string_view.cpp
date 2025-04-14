#include <string>
#include <string_view>
#include <iostream>
#include <utility>


std::size_t length(const std::string &s)
{
    return s.size();
}

int main()
{
    std::cout << length("Some string") << std::endl;

    constexpr auto str = std::string_view("It is surprisingly const. Maybe not so ;)");
    std::string_view smt = "smth";
    std::cout << smt << std::endl;
    std::cout << length("Some string") << std::endl;
    //smt[3]='C';
    std::string mutable_string= "Hello World!";

    return 0;
} 