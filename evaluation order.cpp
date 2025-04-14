
// For x86 msvc
// /std:c++11
// For x86-64 gcc 14.1
// -std=c++11
// 
// https://www.cppstories.com/2021/evaluation-order-cpp17/

#include <iostream>
#include <string>

int main() {
    std::string s = "but I have heard it works even"
                    "if you don't believe in it";
    s.replace(0, 4, "")
     .replace(s.find("even"), 4, "only")
     .replace(s.find(" don't"), 6, "");
    std::cout << s;

    return 0;
}
