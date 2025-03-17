#include  <iostream>

class Singelton
{
public:

    static Singelton& get_instance()
    {
        return handle;
    }
     void show_secter_number() const
    {
        std::cout << secret_number << "\n";
    }
    // Limiting posibillity for copying
    Singelton(const Singelton& obj) = delete;
    Singelton& operator=(const Singelton& other) = delete;
    
private:
    // Instance 
    static Singelton handle;
    int secret_number{42}; // Yes we are deliberatly using magic number [cppcoreguidelines-avoid-magic-numbers,readability-magic-numbers]
    
    // Obj handling
    constexpr Singelton() = default;
    constexpr Singelton( Singelton&& other) = default;
    Singelton& operator=( Singelton&& other) = default;
    ~Singelton() = default;
};

Singelton Singelton::handle;


int main()
{
    Singelton::get_instance().show_secter_number();

    // This will be caught by sonar: https://rules.sonarsource.com/cpp/RSPEC-5350/
    auto& coppy = Singelton::get_instance();
    coppy.show_secter_number();


    return 0;
}

