#include <iostream>
#include <memory>

int main()
{
    std::shared_ptr<int[]> sp(new int[10]); //delete[]
    sp[9] = 10;

    std::cout << sp[9] <<"\n";
    return 0;
}