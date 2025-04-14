#include <iostream>
#include <filesystem>

namespace fs = std::filesystem;

int main()
{
    //New objects
    fs::path p{"foo.temp"}; // object to hold a path
    fs::file_status fs;

    auto path = fs::current_path();

    std::cout << path << "\n"
              << fs::path(".").filename() << '\n'
              << fs::path("..").filename() << '\n'
              << fs::path("/").filename() << '\n' ;
    auto new_path = path.parent_path();
    //new_path.concat("\\secret");

    // Reseting working path
    std::filesystem::current_path(new_path);
    std::cout << new_path << "\n";
    if(fs::exists(new_path))
    {
        std::cout << "This dir exists\n";
    }
    
    if (fs::is_directory(fs::status(path)))
    {
        std::cout << "Directories:\n";
    }
    
    if(std::filesystem::create_directory("secret"))
    {
        //
    };

    
    for (const auto & entry : fs::directory_iterator{new_path})
        std::cout << "\t\t"<< entry.path().filename() << std::endl;
    

    return 0;
}