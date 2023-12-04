#include<iostream>
#include <functional>

int main()
{

auto lambdaFun = [](int x) { return [x](int y) {return x + y; }; };

auto uzyjLambdy = [](const std::function<int(int)>& f, int z) { return f(z) * 2; };

auto wynik = uzyjLambdy(lambdaFun(7), 8);
std::cout << wynik << std::endl;

//generic lambda

auto add = [](auto a, auto b){ return a+b;};
std::cout << add(2,6) << std::endl;
std::cout << add(std::string("Generic "), std::string("Lambda")) << std::endl;


return 0;
}