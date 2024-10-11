#include<iostream>
#include<initializer_list>
#include<functional> // for: less
#include<set>
#include<array>
#include<vector>
#include<map>
#include<list>
#include<algorithm>

void Printsize(std::array<int,3> array)
{
    //std::cout << sizeof(array) << std::endl;
}


int main()
{
   //std::__cxx11::list;

   
    //==----------------------------------------==//
    //                 STD::array                 //
    //==----------------------------------------==//
    // 1. passing array to function and method size
    // Casse of raw array
    int array[3] = {11,51,101};
    // vs std::array
    std::array<int,3> listarraylist = {1, 10 ,30}; 
    

    //listarraylist.begin(); // *pointer_to array 
    //listarraylist.end();   // *(pointer+array.length()-1)
    //std::cout << listarraylist[2] << std::endl;
    //Printsize(listarraylist);
    
    

    // 2. method fill
    //listarraylist.fill(5);

    //for(auto& el : listarraylist) 
    //{
       // std::cout << el << std::endl;
    //}
    // 3. method at - ensures bouns checking
    //std::cout << listarraylist.at(10) << std::endl;
    //==----------------------------------------==//
    //                 STD::vector                //
    //==----------------------------------------==//
    // 1.member access, [], at
    // overloaded index operator to use for(i, i<n, i++)
    // also  range base for for(el: container) can be used
    //std::vector<int> my_vec{1,2,3,4,5};
    //std::cout << my_vec.size() << std::endl;
    //std::cout << my_vec.capacity() << std::endl;

    //auto it = my_vec.begin();


    // 2. method capacity
    /*for(auto& el : my_vec) 
    {
        el=el+2;
    }*/
    //for(auto el : my_vec) 
    //{
       // std::cout << el << std::endl;
    //}
    //int a= 10;
    //my_vec.emplace_back(10); 
 
    
    // 3. method shrink_to_fit
    //my_vec.push_back(77);  
    //std::cout << "Vectors capacity:  " << my_vec.capacity() << std::endl;
    //std::cout << "Vector length:  " << my_vec.size() << std::endl;
    //auto it = my_vec.begin(); 
   
    //my_vec.shrink_to_fit();
 
 

    //std::cout << my_vec.capacity() << std::endl;
   
    //my_vec.erase(my_vec.begin()+2);
    //my_vec.shrink_to_fit();
    //std::cout << "Vector capasity is: " << my_vec.capacity() << "\nVector actual size is: " << my_vec.size()<< std::endl;
    // 4. method erase
   // auto it = std::find(my_vec.begin(), my_vec.end(), 4);
    //my_vec.erase(it);
   //std::cout << "Vector capasity is: " << my_vec.capacity() << "\nVector actual size is: " << my_vec.size()<< std::endl;
    //for(auto el : my_vec) 
    {
       //std::cout << el << std::endl;
    }
    //std::cout << "Vector capasity is: " << my_vec.capacity() << "\nVector actual size is: " << my_vec.size()<< std::endl;
    

    // 5. method reserve

    //std::vector<int> my_vec2;   // ({9,5,4,5,6}) 

    //my_vec2.reserve(6); 
    //std::cout << my_vec2.capacity() << "\n" ;  //
    //std::cout << "========================" << "\n" ; 
    for(auto i =0 ; i<6; i++)
    {
    //   my_vec2.push_back(i);
       // std::cout << my_vec2.capacity() << "\n" ;

    }

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
    for(auto el : test_set)
    {
       // std::cout << el << " " << std::endl;
    }

    // 2. method count
    auto exists = test_set.count(99);
    // std::cout << exists << std::endl;
    // 3. method find
    auto it = test_set.find(30);

    //==----------------------------------------==//
    //                 STD::map                   //
    //==----------------------------------------==//
    // 1. member access, [], at
    std::map< unsigned int, std::string > id_list;
    id_list[12345] = "CAT";  
    //std::cout << "set" << id_list.at(12345) << std::endl;
    
    // 2. method insert
    id_list.insert(std::pair<unsigned int, std::string>(12345, "CAT"));
    id_list.insert(std::pair<unsigned int, std::string>(23456, "CAT"));
    id_list.insert(std::pair<unsigned int, std::string>(55555, "DOG"));
    id_list.insert(std::pair<unsigned int, std::string>(76543, "FISH"));
    id_list.erase(55555);
    
    //structure binding avalable in C++17
    //uses  const auto& [ keys, values]
    for (const auto& [ keys, values] : id_list)
        //std::cout << keys << " " << values << std::endl;

    // 3. method find and erase
    //auto it = id_list.find(12345);

    id_list.erase(55555);
    
    

    //==----------------------------------------==//
    //                 STD::list                  //
    //==----------------------------------------==//   
    std::list<int> list ;  
    
    list.push_back(1); // -> // 
    list.push_back(2);          //10 -> 1 -> 2 -> 12
    list.push_back(12);         //obj 
    list.push_front(10);
 //  std::cout << "!========================" << "\n" ; 
   // method insert
   auto itr = std::find(list.begin(), list.end(), 2);
   list.insert(itr, 77); // 


    for (const auto& val : list)
       std::cout << val << std::endl;
       //std::cout << *list.begin() << std::endl;
    return 0;
   // std::cout << "!========================" << "\n" ; 
}








