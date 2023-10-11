#include<iostream>
#include<initializer_list>
#include<functional> // for: less
#include<set>
#include<array>
#include<vector>
#include<map>
#include<list>
#include<algorithm>

void Printsize(int* array)
{
    std::cout << sizeof(array) << std::endl;
}


int main()
{
    //==----------------------------------------==//
    //                 STD::array                 //
    //==----------------------------------------==//
    // 1. passing array to funktion and method size
    // Casse of raw array
    int array[3] = {11,51,101};
    // vs std::array
    std::array<int,3> listarraylist = {1, 10 ,30}; 

    //std::cout << sizeof(array) << std::endl;
    //Printsize(array);
    
    

    // 2. method fill
    //listarraylist.fill(5);

    /*for(auto el : listarraylist)
    {
        std::cout << el << std::endl;
    }*/
    // 3. method at - ensures bouns checking
    //std::cout << listarraylist[5] << std::endl;
    //==----------------------------------------==//
    //                 STD::vector                //
    //==----------------------------------------==//
    // 1.member access, [], at
    // overloaded index operator to use for(i, i<n, i++)
    // also  range base for for(el: container) can be used
    std::vector<int> my_vec = {1,3,5,7,9};
    std::cout << my_vec.at(3) << std::endl;

    auto it = my_vec.begin();
    // 2. method capacity
    my_vec.push_back(11);
    
    // 3. method hrink_to_fit
    my_vec.push_back(77);
   
    /*my_vec.shrink_to_fit();
    std::cout << "Vector capasity is: " << my_vec.capacity() << "\nVector actual size is: " << my_vec.size()<< std::endl;
    my_vec.erase(my_vec.begin()+2);
    my_vec.shrink_to_fit();
    std::cout << "Vector capasity is: " << my_vec.capacity() << "\nVector actual size is: " << my_vec.size()<< std::endl;*/

    //auto it = std::find(my_vec.begin(), my_vec.end(), 7);
   // my_vec.erase(it);
    // 4. method erase
    //  -- real time writing example here --
    
    //Bonus: CTAD - Class  argument template deduction 

    // 4. mathod reserve

    /*std::vector<int> my_vec2 ;

    my_vec2.reserve(5);
    std::cout << my_vec2.capacity() << "\n" ;
    for(auto i =0 ; i<5; i++)
    {
        my_vec2.push_back(i);
        std::cout << my_vec2.capacity() << "\n" ;

    }*/

    //==----------------------------------------==//
    //                 STD::set                   //
    //==----------------------------------------==//
    

    // Set --  sorted set of unique objects of type Key
    // non sequential
    std::set<int> test_set = {30, 1, 10 , 1, 30 , 1}; 

    //std::cout << test_set.max_size() << std::endl; 

    // 1. method insert
    test_set.insert(5);
    test_set.insert(30);
    /*for(auto el : test_set)
    {
        std::cout << el << " " << std::endl;
    }*/

    // 2. method count
    auto exists = test_set.count(15);
    //std::cout << exists << std::endl;
    // 3. method ind
   // auto it = test_set.find(30);

    //==----------------------------------------==//
    //                 STD::map                   //
    //==----------------------------------------==//
    // 1. member access, [], at
    std::map< unsigned int, std::string > id_list;
    id_list[12345] = "EIRYMAT";  
    //std::cout << id_list.at(12345) << std::endl;

    // 2. method insert
    id_list.insert(std::pair<unsigned int, std::string>(12345, "EIRYMAT"));
    id_list.insert(std::pair<unsigned int, std::string>(23456, "ERANDOM"));
    id_list.insert(std::pair<unsigned int, std::string>(55555, "EJUSTDO"));
    id_list.insert(std::pair<unsigned int, std::string>(76543, "ESOMGUY"));
    //structure binding
    //use  const auto& [ keys, values]
    for (const auto&  [ keys, values] : id_list)
        std::cout << keys << " " << values << std::endl;

    // 3. method find and erase
    //auto it = id_list.find(12345);
    id_list.erase(55555);
    
    

    //==----------------------------------------==//
    //                 STD::list                  //
    //==----------------------------------------==//   
    std::list<int> list ;
    
    list.push_back(1);
    list.push_back(2);
    list.push_back(12);
    list.push_front(10);
    
   // method insert
   auto it = std::find(list.begin(), list.end(), 1);
    list.insert(it, 77);

    /*for (const auto& val : list)
        std::cout << val << std::endl;*/
    std::cout << *list.begin() << std::endl;
    return 0;
}







