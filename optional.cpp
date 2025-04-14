#include <iostream>
#include <optional> // place for null optional to live
#include <vector>

struct ExpensiveObj
{
    std::vector<int> v;
    void setSize(size_t size){v.reserve(size);}
};

int main()
{
    //=-----------------=-//
    //    std::optional   //
    //=-----------------=-//
    std::optional<int> i;
    ExpensiveObj obj;
    obj.setSize(40);
    // no more dynamic alocation for o_obj
    std::optional<ExpensiveObj> o_obj{obj}; 

    std::cout << sizeof(obj) << std::endl;
    std::cout << sizeof(o_obj) << std::endl;
    
    
    i.has_value();
    i.value_or(10); // as abackup option for out optional
    //i = 10;
    //std::cout << i.value() << std::endl; // should be covered with all protection  code and prepara to trow exeption
    //=-----------------=-//
    //     std nullopt    //
    //=-----------------=-//

    std::optional<ExpensiveObj*> empty_opt = std::nullopt;
    if(empty_opt)
        std::cout << "Here is smth\n";
    else
        std::cout << "Now optionall is clearly empty\n";
        
    return 0;
}