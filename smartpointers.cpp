#include <iostream>
#include <memory>
#include <vector>
typedef  std::vector<int> vec; 

int main()
{

    std::shared_ptr<vec> ps1;
    //std::cout << "1. number of ptr mapping this Obj: " << ps1.use_count() << std::endl;
    {
        std::unique_ptr<vec> ps3( new vec({1,2,3}));

        std::unique_ptr<vec> p = std::make_unique<vec>(vec({1,2,10}));
        
        std::shared_ptr<vec> ps2 = std::make_shared<vec>(vec(5));

        ps1  = ps2;
        //std::cout << "1. number of ptr mapping this Obj: " << ps1.use_count() << std::endl;
        //std::cout << "Vector size is: " << ps2->size() << std::endl;

        
        //for(auto el : *ps2)
        //    std::cout << el << std::endl;

        //std::unique_ptr<vec> bad_p_copy = p;
    }

    //std::cout << "2. number of ptr mapping this Obj: " << ps1.use_count() << std::endl;
    //for(auto el : *ps1)
    //    std::cout << el << std::endl;

    std::weak_ptr<vec> pw;
    {
        
        std::shared_ptr<vec> ps2 = std::make_shared<vec>(vec(5));
        std::cout << "number of ptr mapping this Obj: " << ps2.use_count() << std::endl;
        pw = ps2;

        //if (std::shared_ptr<vec> ps3 = pw.lock() )
        //     std::cout << *ps3 << "\n";
        //else
            //std::cout << "gw is expired\n";

        
        std::cout << "number of ptr mapping this Obj: " << ps2.use_count() << std::endl;
    }
    
    if (pw.expired())
       std::cout << "Weak pointer is alive but Obg is gone now. Sad pointer :( " << std::endl;


    return 0;
}