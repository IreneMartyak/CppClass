#include <iostream>
#include <string_view>
#include <any>
#include <array>

// more commonly used as int N
template <typename T, unsigned int N> 
struct myArray
{  
    T array[N];
};
//
template <auto N> 
class Generic
{  /*…*/ };

int main()
{

    Generic<42> g1; // -> N jest int’em
    Generic<'a'> g2; // -> N jest char’em
    //Generic<3.14f> g3; // ERROR, bo nadal nie może być double’m
    auto il  = {1,3,5,6};
    Generic<il> g4;
    Generic<2U> g5;
    Generic<(short)2> g6;

    const std::any av = 3;
    std::string_view sv = "Some string";
    //Generic<av> g7;
    //Generic<"smth"> g8;
    //Generic<void> g9;
    
    myArray<int,10> ma{10};
    std::array<int,10> array;
    return 0;
}