#include<iostream>
#include <typeinfo>

// Old way Enums work:
enum class Colors : int {red, blue, green, orange}; 
enum class Fruits : int { banana, apple, peach, orange};
// Ups ! But thouse orange's are two compleatly different thing ?
// C++11 way, declare enum class Fruits

int main()
{
enum  Colors var1 = Colors::orange; // blue
enum  Fruits var2 = Fruits::orange; // apple

if(var1 == var2 )
    std::cout << "To same" << std::endl;


std::cout << typeid(std::underlying_type_t<Colors>).name()  << std::endl;

return 0;
}