#include <cstdint>
#include <iostream>
#include <memory>

// Product
class Product
{
    const char* _name = "RC toy" ;
public: 
    // clang tidy : [modernize-use-nodiscard]   
    [[nodiscard]] constexpr const char* get_name() const noexcept {return _name;}
    constexpr void set_name(const char* name){_name = name;}

    Product() = default;

    constexpr Product(const Product& other) = default;
    Product& operator=(const Product& other) = default;
    constexpr Product( Product&& other) = default;
    Product& operator=( Product&& other) = default;
    virtual ~Product() = default;

};

// Concreate product
class Car : public Product
{
public:    
    Car(){set_name("RC toy car");}
};

class Helicopte : public Product
{ 
public:
    Helicopte(){set_name("RC toy helicopter");}
};

class Boat : public Product
{
public:    
    Boat(){set_name("RC toy boat");}
};

enum class Catalog : uint8_t {CARS, HELICOPTER, BOAT};

class Object_Factory_lmplementation //: public ObjectFactory
{
    public:
    Object_Factory_lmplementation() = default;

    [[nodiscard]] std::shared_ptr<Product> create_object(const Catalog item) const
    {
        std::shared_ptr<Product> result = nullptr;
        switch(item)
        {
            case Catalog::CARS:
                result = std::make_shared<Car>(); 
                break;
            case Catalog::HELICOPTER:
                result =  std::make_shared<Helicopte>();
                break;
            case Catalog::BOAT:
                result = std::make_shared<Boat>();
                break;
            default:
                std::cout << "This product is not supported yet";  
        }
        return result;
    }

};


int main()
{
    // IGNORING clang tidy :  [hicpp-use-auto,modernize-use-auto] & [cppcoreguidelines-owning-memory]
    Object_Factory_lmplementation* factory_object = new Object_Factory_lmplementation();
    
    auto my_helicopter = factory_object->create_object(Catalog::HELICOPTER);
    
    std::cout << my_helicopter->get_name() << "\n";
    
    delete factory_object;
    return 0;
}
