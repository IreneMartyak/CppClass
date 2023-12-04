#include <iostream>
#include <cassert>
#include <tuple>
#include <string>

typedef  std::tuple<int,char, float, std::string > mytuple;

void printTuple( mytuple tuple)
{
    std::cout << "Tuple el: " << std::get<0>(tuple) << 
    "  " << std::get<1>(tuple) << 
    "  " << std::get<2>(tuple) << 
    "  " << std::get<3>(tuple) << std::endl;
}

int main()
{
    std::tuple<int,char, float, std::string > tuple (1, 'c', 3.1415, "Something");
    std::tuple<int,char, float, std::string > tuple2 (2, 'b', 56.8, "TFB");
    //printTuple(tuple);
    //std::cout << std::get<char>(tuple2) << std::endl;
    /*std::cout << "Tuple el: " << std::get<0>(tuple) << 
    "  " << std::get<1>(tuple) << 
    "  " << std::get<2>(tuple) << 
    "  " << std::get<3>(tuple) << std::endl;
    */
    //auto my_tuple = std::make_tuple(45.8 , 10 , std::string("String"));

    int a{0} , b{0};
    char c;
    float f{0};
    std::string str{""};
    std::tie(a, c,f, str) = tuple ;
    //std::cout << a <<  "  and  " << c << std::endl;
    //std::cout << f <<  "  and  " << str << std::endl;
    //tuple.swap(tuple2);
    std::get<0>(tuple) = 20;
    printTuple(tuple);

    return 0;
}