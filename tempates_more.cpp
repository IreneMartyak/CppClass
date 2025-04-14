#include <iostream>
#include <string>
#include <vector>
#include <array>

template <typename T>
void foo(T val)
{
    
}

template <typename T1, typename T2>
class Szablonowa
{
public:
    T1 fst; T2 snd; 
    Szablonowa(T1 f, T2 s) : fst{f}, snd{s} {}
};

int main()
{
std::array arr{12,3,4,5};
std::vector v{1,2.1,3,4,5};
Szablonowa<int, double> sz1(1, 3.14); 
Szablonowa sz2(1, 3.14); // Szablonowa<int, double>
Szablonowa sz3{1, '3'}; // Szablonowa<int, double>
auto sz4 = Szablonowa(1, "text"); // Szablonowa<int, const char*>
auto sz5 = Szablonowa{3.14, std::string("pi") }; // Szablonowa< double, std::string>

return 0;
}