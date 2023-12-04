#include<iostream>
#include<vector>
#include<string>
#include<typeinfo>

//template <typename T>
void foo (int x)  // < entry point
{

    std::cout << typeid(x).name() << std::endl;
    // does something super important
    //return x;   // < exit point
};

int main()
{
// lvalue - on left; rlavue - on right
// coul be or could not  be asigneed ?
// lvalue can be referenced -  rlave - can not
int i = 7;

const int a = 10;

int* b = new int(10);

foo(10); 
foo(1);
delete b;

std::vector<std::string> vt;
std::string str = std::string("Text") + std::string("String");
vt.push_back(str);
vt.push_back("str");
vt.emplace_back("str");


return 0;
}

// https://www.youtube.com/watch?v=PNRju6_yn3o
// TODO : Look for some extra stuff in Nicolai Josuttis vid