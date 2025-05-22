#include <string>
#include <variant>
#include <iostream>


struct Class1
{
    const std::string mName;
    Class1() = default;
    Class1(std::string name): mName(name){}
};

struct Class2
{
    const std::string wName;
    Class2() = default;
    Class2(std::string name): wName(name){}
};


using MyClass = std::variant<Class1,Class2>; //
// Length functionality block
struct NewFunctionalityVisitor{
    int operator()(const Class1& c)
    {  return c.mName.length();}
    int operator()(const Class2& c)
    {  return c.wName.length();}
};

int main()
{
    MyClass tt = Class1("Class1 entyty");

    // Visitor case
    MyClass mc = Class1("Class1 entyty");

    auto value = std::visit(NewFunctionalityVisitor{}, mc);

    return 0;
}