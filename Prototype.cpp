#include <cstdint>
#include <iostream>
#include <thread>
#include <chrono>
#include <memory>
#include <utility>

enum class CARS : uint8_t {LAMBORGINI, CHEVROLET};

// This is trivial 
class Car_data
{
    float _engine_volume{};
    int _top_speed{};
    float _acceleration{};
    int _kerbWeight{};

public:

    explicit Car_data (float engine_volume, int top_speed, float acceleration, int kerbWeight):
    _engine_volume(engine_volume),_top_speed(top_speed),_acceleration(acceleration),_kerbWeight(kerbWeight)
    {};

    void show_top_speed() const
    {std::cout << "Top speed is: " << _top_speed << "\n";}


};

class Car
{
    int _color{};
public: 
    std::shared_ptr<Car_data> _data = nullptr;

    Car(const Car& other):_data(other._data){};
    Car& operator=(const Car& other) = default;
    Car( Car&& other) = default;
    Car& operator=( Car&& other) = default;
    virtual ~Car() = default;

    explicit Car(int color):_color(color){}

    virtual std::unique_ptr<Car> clone() = 0;
};



class Lamborgini_Diablo_SV: public Car
{   
    
public:  
    explicit Lamborgini_Diablo_SV(int color):Car(color)
    {
        _data = std::make_unique<Car_data>(5.7, 328, 3.8, 1530);
        //this should simulate costlyness of creation process for example by database request
        std::this_thread::sleep_for(std::chrono::milliseconds(3600));
    }; 
    Lamborgini_Diablo_SV() = delete;
    ~Lamborgini_Diablo_SV()final = default;

    Lamborgini_Diablo_SV(const Lamborgini_Diablo_SV& other) = default;
    
    std::unique_ptr<Car> clone() override
    { 
        return std::make_unique<Lamborgini_Diablo_SV>(*this);
    };
    

};

class Chevrolet_Corvette: public Car
{
    
public: 
    explicit Chevrolet_Corvette(int color):Car(color)
    {
        _data = std::make_unique<Car_data>(5.7, 277, 4.9, 1459);
        //this should simulate costlyness of creation process for example by database request
        std::this_thread::sleep_for(std::chrono::milliseconds(3600));
    };
    Chevrolet_Corvette() = delete;
    ~Chevrolet_Corvette()final = default;
    Chevrolet_Corvette(const Chevrolet_Corvette& other) = default;

    std::unique_ptr<Car> clone() override
    {  
        return std::make_unique<Chevrolet_Corvette>(*this);
    };
};

class Car_factory // consider to repurpouse into friend's factory
{

public:
    Car_factory() = default;
    [[nodiscard]] std::shared_ptr<Car> create_car(const CARS item) const
    {
        std::shared_ptr<Car> car = nullptr;
        switch(item)
        {
            case CARS::LAMBORGINI:
                car = std::make_shared<Lamborgini_Diablo_SV>(2); 
                break;  
            case CARS::CHEVROLET:
                car = std::make_shared<Chevrolet_Corvette>(3);  
                break;
            default:
                std::cout << "Model not found in database \n"; 
        }    
        return car; 
    }  

};


int main()
{
    // Chosing from drop down menu a car for the race
    
    auto car_factory = std::make_unique<Car_factory>();
    auto my_chevrolet =  car_factory->create_car(CARS::CHEVROLET);

    // Fast redrawing of a player model onto racing track
    std::cout << "Prepare for race ! 3, 2, 1... \n";
    auto cpu_player1 = my_chevrolet->clone();
    auto cpu_player2 = my_chevrolet->clone();

    // and cheking it parameters in menu
    std::cout << "PAUSE. Entering menu: \n" ;
    my_chevrolet->_data->show_top_speed();
    // Generating rival that will match our characteristics, best same model
    
    return 0;
}
