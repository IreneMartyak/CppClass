#include <string>
#include <variant>
#include <iostream>
#include <vector>
//#pragma  pack(1)

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

class O
{
    int number;
    char symbol;
    O(int num, char ch):number(num),symbol(ch) {}
    void print(){std::cout <<  "num: " <<number << "symb: " << symbol << std::endl;}
};

class I
{
    int number;
    char symbol;
    I(int num, char ch):number(num),symbol(ch) {}
    void print(){std::cout  << "Symb: " << symbol <<  "Num: " <<number << std::endl;}
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
    std::variant<Class1,Class2> tt = Class1("Class1 entyty");

    // Visitor case
    MyClass mc = Class1("Class1 entyty");

    auto value = std::visit(NewFunctionalityVisitor{}, mc);
    
    //std::cout << value << std::endl;
    // unio and variant comparison
    union
    {
        int value;   // | int       |
        char name;   // |__|__|__|ch|      
    } uv;

    //uv.value = 444;

    std::variant<int,char> v;// |ch|int|
    //auto index = static_cast<unsigned long long>(v.index());
    
    //std::cout << sizeof(uv) << std::endl;
    std::cout << std::get<0>(v) << std::endl;

    //std::cout << sizeof(int) << std::endl;


    auto result = std::get_if<int>(&v); 
    //std::cout << uv.name << std::endl;

    //std::variant<I,O> var;// this will not work ! add monostate
    // std::monostate - placeholder type for use as the first alternative in a variant of non-default-constructible types
    // Run, its gonna throw, its gonna THROW !!!
    //auto KaBooM = std::get<O>(var) ;

    // Raymond Chen
    // C++17 introduced std::monostate, and I used it as a placeholder to represent the results of a coroutine that produces nothing. In the comments, Neil Rashbrook asked what you are expected to do with a std::monostate, seeing as has no members and only trivial member functions.
    // The answer is “nothing”.
    // The purpose of std::monostate is to be a dummy type that does nothing. All instances are considered equal to each other. It is basically this:

    // struct monostate {};
    // plus relational operators and a hash specialization
    std::vector<int> vv;
    auto it = vv.begin();
    

    return 0;
}