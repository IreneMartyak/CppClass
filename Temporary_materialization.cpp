#include<string>
#include<memory>
#include<iostream>


struct dispatcher
{
    int index{66};
    char value{'B'};
    dispatcher() = default;
    dispatcher(const dispatcher& x ){ std::cout << "Performing an anwanted copy. Especially bad for uncopiable objects." << std::endl;};
    //dispatcher& operator=(dispatcher other) = delete;
    
};

// lets create a string factory
dispatcher maker()
{
    return dispatcher{};
}

int main()
{
    std::unique_ptr< dispatcher> b = std::make_unique< dispatcher >( maker());

    return 0;
}