#include <iostream>

class Lambdy
{
    std::string m_name = "NAZWA";
public:
   //void przechwycThis1() { [] { std::cout << m_name << std::endl; }(); } // ERROR – nie jest przechwycone
   void przechwycThis2() { [&] { std::cout << m_name << std::endl; }(); } // OK - this przechwycone niejawnie przez &
   void przechwycThis3() { [=] { std::cout << m_name << std::endl; }(); } // OK - this przechwycone niejawnie przez =
   void przechwycThis4() { [this] { std::cout << m_name << std::endl; }(); } // OK - this przechwycone jawnie
   void przechwycThis5() { [*this] { std::cout << m_name << std::endl; }(); } 
};

struct Test
{
  int number = 5;
  const int value = [=]() constexpr { return 0; }();
};

int main()
{
    Lambdy lm;
     lm.przechwycThis4();

    return 0;
}