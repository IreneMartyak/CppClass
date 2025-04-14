#include<string>
#include<memory>
#include<iostream>


struct Czas
{
    int godz, min, sek;
};

struct Data
{
    int value;
    char character;
};

Data foo()
{
    return Data{77, 'a'};
}

int main()
{
Czas czas{12, 0, 30};
auto [h, m, s] =  czas;

int tab[]{ 0, 0 };
auto [x, y]{tab};

auto& [rx, ry] = tab; // rx oraz ry odnoszą się do elementów w tab
tab[0]= 42;
std::cout << x << "  " << rx << std::endl;
const auto [v, w] = tab; // v oraz w mają typ const int, zainicjalizowane są wartościami elementów tab
alignas(4) auto[i, d] = foo(); // i oraz d odnoszą się do niejawnej jednostki, wyrównanej do 16 bajtów
std::cout << alignof(i) << "  " << alignof(d) << std::endl;
union Structure_binding_struct_case
{
    int val{93};
    char el;
};
 

Czas cz1{12, 0, 30};
auto [h1, m1, s1] = std::move(cz1);


    return 0;
}