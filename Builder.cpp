#include <iostream>
#include <stack>
#include <vector>
// Age of empires 1

enum class CAMPAIGN { STANDART, ASCENT_OF_EGIPT_CP0, ASCENT_OF_EGIPT_CP1, ASCENT_OF_EGIPT_CP7 };
class Base_Building
{
public:
     std::string _name;
};

class Builder
{
public:
     std::string _id;
};
class Market
{
public:
     std::string _name;
};
class Baracs
{
public:
     std::string _name;
};

class Campain
{
     Base_Building *_base_building;
     std::vector<Builder> *_builders;
     Market *_market;
     Baracs *_baracs;
public:
     Base_Building* get_base_building(){}
     Builder* get_builders(){ }
     Market* get_market(){}
     Baracs* get_baracs(){}
};
class Builder
{

public:
    //virtual void reset() = 0;
    virtual void createBaseBuilding()  = 0;
    virtual void createBuilders(int number) = 0;
    virtual void createMarket() = 0;
    virtual void createBaracs() = 0;
};


class Builder_Greek_style_campain : public Builder
{
     
     //Campain *campagn = nullptr;
public:
     //void reset(){}
     int number_of_workers{};
     void createBaseBuilding() override {std::cout << "Creating Agora" << std::endl;}
     void createBuilders(int number) override {number_of_workers = number; std::cout << "Generating " << number << " greek workers" << std::endl;}
     void createMarket() override {std::cout << "Settling trading stall and shops amid arkades" << std::endl;}
     void createBaracs() override {std::cout << "We can train Hoplite" << std::endl;}
     Builder_Greek_style_campain* getResult(){ return this;}
};

class Builder_Egyptian_style_campain : public Builder
{
     Campain *campagn = nullptr;
public:
     //void reset(){}
     void createBaseBuilding() override {std::cout << "Creating town center with obelisk" << std::endl;}
     void createBuilders(int number) override {std::cout << "Generating " << number << " egyptian workers" << std::endl;}
     void createMarket() override {std::cout << "Creating outdoor marketplace" << std::endl;}
     void createBaracs() override {std::cout << "We can train chariot archers" << std::endl;}
     Builder_Egyptian_style_campain getResult(){ return *this;}
};

class Builder_Mesopotamian_style_campain : public Builder
{
     Campain *campagn = nullptr;
public:
     //void reset(){}// Actually constructor
     void createBaseBuilding() override {std::cout << "Creating Ziggurat" << std::endl;}
     void createBuilders(int number) override {std::cout << "Generating " << number << " mesopotamian workers" << std::endl;}
     void createMarket() override {std::cout << "Creating Bazar" << std::endl;}
     void createBaracs() override {std::cout << "We can train cammel riders" << std::endl;}
     Builder_Mesopotamian_style_campain getResult(){ return *this;}
};

class Director
{

Builder* builder = nullptr;    
public:
     Director(Builder* bd):builder(bd)
     {

     }
     void changeBuilder(Builder* new_builder)
     {
          builder = new_builder;
     }
     void makeCampain(CAMPAIGN choise)
     {
          if(choise  == CAMPAIGN::STANDART )
          {
               builder->createBaseBuilding();
               builder->createBuilders(4);
          }
          else //should be tree of dedicated campains
               //for simplification just create Ascent_of_Egipt_CP2
          {
               builder->createBaseBuilding();
               builder->createBuilders(4);  
               builder->createMarket();
               builder->createBaracs();   
          } 
     }
};

int main()
{
    Director game_engine(Builder_Greek_style_campain().getResult());
    game_engine.makeCampain(CAMPAIGN::STANDART);

    return 0;
}
