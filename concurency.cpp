#include <iostream>
#include <random>
#include <future>
#include <thread>
#include <chrono>


bool guess_number(int atempts, unsigned int number)
{

    std::random_device rd;  
    std::mt19937 gen(rd()); 
    std::uniform_int_distribution<> distrib(1, 20000);

    while(atempts )
    {
        distrib(gen);
        if(distrib(gen) == number)
            return true;
        atempts--;
    }
    return false; 

}
int main()
{
    auto res1 = std::async(std::launch::async, guess_number, 3000, 42);
    auto res2 = std::async(std::launch::async, guess_number, 3500, 1);
    auto res3 = std::async(std::launch::async, guess_number, 8000, 100);   
    
    res2.wait();
    //std::promise promise;
    return 0;
}