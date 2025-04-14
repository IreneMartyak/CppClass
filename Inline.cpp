#include<iostream>


/// Pre C++17 style
/* template< class Dummy >
struct Kath_
{
    static std::string const hi;
};

template< class Dummy >
std::string const Kath_<Dummy>::hi = "Zzzzz...";

using Kath = Kath_<void>;    // Allows you to write `Kath::hi`. */
/// C++17 style
struct Kath
{
    static inline std::string  hi = "Zzzzz...";    // Simplest!
};

int main()
{

    std::cout << Kath::hi  << std::endl;
    return 0;
}