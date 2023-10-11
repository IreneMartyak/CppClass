#include <iostream>
#include <array>
#include <vector>


// general function template
// 2 or more type template
// Class template

template<class T1, typename T2>
T2 add(T1 a , T2 b)
{
  return a+b;
}



template<typename T, unsigned int N> 
class CustomTable
{
public:
  T table[N];
};








int main()
{
  CustomTable<int,6> ctb = {1,2,3,4,5,6};

  std::array<int, 2> a5;
 
  
  std::cout << ctb.table[1] << std::endl;
  //std::cout << "Operation resulted in value: " << add<int>(8,9) << std::endl;

  std::cout << add(8,5) << std::endl;
  std::cout << add(8,5.15) << std::endl;
  std::cout << add(8,'C') << std::endl; 
  return 0;
}




