#include <boost/make_shared.hpp>
#include <boost/shared_ptr.hpp> // For boost::shared_ptr
#include <cstdint>
#include <iostream>
#include <memory>               // For std::shared_ptr
#include <type_traits>
#include <vector>




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


template<typename Underlying_type_t> // Adapter = Simple Wraper
class Smart_pointer_factory_adapter
{
public:

    [[nodiscard]] boost::shared_ptr<Underlying_type_t> make_shared(std::shared_ptr<Underlying_type_t>&& std_pointer)
    {
        return boost::make_shared<Underlying_type_t>(std::move(*std_pointer));
    };

    // To unclude unique pointer functionality
    // #include <boost/move/unique_ptr.hpp>
    // #include <boost/make_unique.hpp>
    /*[[nodiscard]] boost::unique_ptr<Underlying_type_t> make_unique(std::unique_ptr<Underlying_type_t>&& std_pointer)
    {
        return boost::make_unique<Underlying_type_t>(std::move(*std_pointer));
    };*/

};



int main()
{
    Object_Factory_lmplementation* factory_object = new Object_Factory_lmplementation();
    
    // but i want a boost pointer to handle my object :( or std im so unsure !!
    Smart_pointer_factory_adapter<Product> adapter;

    
    boost::shared_ptr<Product> what_i_want  = adapter.make_shared(factory_object->create_object(Catalog::HELICOPTER));
    std::cout << what_i_want->get_name() << "\n";

    return 0;
}
std::vector<int> v;
//  https://www.open-std.org/jtc1/sc22/wg21/docs/papers/2003/n1450.html
//  A Proposal to Add General Purpose Smart Pointers to the Library Technical Report