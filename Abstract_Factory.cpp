#include <cstdint>
#include <iostream>
#include <memory>

enum class Food_catalog : uint8_t {MARGHERITA, ESPRESSO, NEW_YORK, AMERICANO};


class Pizza_product_famiily_A 
{
public:
    virtual void preparing() = 0;
    void baking()const{std::cout << "placeholder for baking process \n" ;};
    void packaging()const{std::cout << "placeholder for packaging process \n";};

    Pizza_product_famiily_A() = default;

    constexpr Pizza_product_famiily_A(const Pizza_product_famiily_A& other) = default;
    Pizza_product_famiily_A& operator=(const Pizza_product_famiily_A& other) = default;
    constexpr Pizza_product_famiily_A( Pizza_product_famiily_A&& other) = default;
    Pizza_product_famiily_A& operator=( Pizza_product_famiily_A&& other) = default;
    virtual ~Pizza_product_famiily_A() = default; 
};
class Margherita_1: public Pizza_product_famiily_A 
{
public:
    Margherita_1(){std::cout << "creattin Pizza with thin dough \n";}
    void preparing() override 
    {
        std::cout << "adding: sos z pomidorów z ziołami, ser żółty, oregano \n"; 
    }
};
class Mew_York_2 : public Pizza_product_famiily_A 
{
public:
    Mew_York_2(){std::cout << "creattin Pizza with thick dough \n";}
    void preparing() override
    {
        std::cout << "adding: becon, pomidor, sos BBQ \n"; 
    }
};


class Coffee_product_famiily_B   
{
public:
    virtual void brewing_process() = 0;
    void add_water()const{std::cout << "placeholder for adding water process \n" ;};
    void add_milk()const{std::cout << "placeholder for adding milk process \n" ;};
    void add_sugar()const{std::cout << "placeholder for adding suger process \n" ;};

    Coffee_product_famiily_B() = default;

    constexpr Coffee_product_famiily_B(const Coffee_product_famiily_B& other) = default;
    Coffee_product_famiily_B& operator=(const Coffee_product_famiily_B& other) = default;
    constexpr Coffee_product_famiily_B( Coffee_product_famiily_B&& other) = default;
    Coffee_product_famiily_B& operator=( Coffee_product_famiily_B&& other) = default;
    virtual ~Coffee_product_famiily_B() = default;  
};
class Espresso_1 : public Coffee_product_famiily_B //-- Abstract Product B --//
{
public:
    Espresso_1(){std::cout << "Using small cup \n";}
    void brewing_process() override
    {
        std::cout << "Using: espresso machine. Two parts of brew \n"; 
    }
};
class Americano_2 : public Coffee_product_famiily_B //-- Abstract Product A --//
{
public:
    Americano_2(){std::cout << "Using big cup \n";}
    void brewing_process() override 
    {
        std::cout << "Using: drip brew. Two parts watter to one part brew \n"; 
    }
};



class Pizzeria   //-- Abstract Factory  --//
{   
public:
    Pizzeria() = default;

    constexpr Pizzeria(const Pizzeria& other) = default;
    Pizzeria& operator=(const Pizzeria& other) = default;
    constexpr Pizzeria( Pizzeria&& other) = default;
    Pizzeria& operator=( Pizzeria&& other) = default;
    virtual ~Pizzeria() = default;  

    // No need for const use in declartion. Satisfyes clang tidy : [readability-avoid-const-params-in-decls]
    virtual  std::shared_ptr<Pizza_product_famiily_A> create_pizza(Food_catalog type) = 0;
    virtual  std::shared_ptr<Coffee_product_famiily_B> create_coffe(Food_catalog type) = 0;
};
class PizzeriaWloska : public Pizzeria  //-- Concreate Factory 1 --//
{
public:
    
    std::shared_ptr<Pizza_product_famiily_A> create_pizza(const Food_catalog item)  override 
    {
        std::shared_ptr<Pizza_product_famiily_A> pizza = nullptr;
        switch(item)
        {
            case Food_catalog::MARGHERITA:
                pizza = std::make_shared<Margherita_1>(); 
                break;
            default:
                std::cout << "This product is not supported yet \n";  
        }
        return pizza;
    }

    std::shared_ptr<Coffee_product_famiily_B> create_coffe(const Food_catalog item)  override 
    {
        std::shared_ptr<Coffee_product_famiily_B> coffe = nullptr;
        switch(item)
        {
            case Food_catalog::ESPRESSO:
                coffe = std::make_shared<Espresso_1>(); 
                break;
            default:
                std::cout << "This product is not supported yet \n";  
        }
        return coffe;
    }
};

class PizzeriaAmerykanska : public Pizzeria  //-- Concreate Factory 2 --//
{
public:

    std::shared_ptr<Pizza_product_famiily_A> create_pizza(const Food_catalog item)  override 
    {
        std::shared_ptr<Pizza_product_famiily_A> pizza = nullptr;
        switch(item)
        {
            case Food_catalog::NEW_YORK:
                pizza = std::make_shared<Margherita_1>(); 
                break;
            default:
                std::cout << "This product is not supported yet \n";  
        }
        return pizza;
    }

    std::shared_ptr<Coffee_product_famiily_B> create_coffe(const Food_catalog item)  override 
    {
        std::shared_ptr<Coffee_product_famiily_B> coffe = nullptr;
        switch(item)
        {
            case Food_catalog::AMERICANO:
                coffe = std::make_shared<Espresso_1>(); 
                break;
            default:
                std::cout << "This product is not supported yet \n";  
        }
        return coffe;
    }
};

int main()
{
// or to be breef 
    PizzeriaWloska  napoletana;
    auto moja_zamowiona_pizza = napoletana.create_pizza(Food_catalog::MARGHERITA);

    return 0;
}