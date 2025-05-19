#include  <iostream>

class Singelton
{
private:
    // Instance 
    static Singelton handle;
    int secret_number{42}; // Yes we are deliberatly using magic number [cppcoreguidelines-avoid-magic-numbers,readability-magic-numbers]
    
    // Obj handling
    constexpr Singelton() = default;
    ~Singelton() = default;
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
    constexpr Singelton( Singelton&& other) = delete;
    Singelton& operator=( Singelton&& other) = delete;
    

};

Singelton Singelton::handle;


int main()
{
    Singelton::get_instance().show_secter_number();

    // Singelton can still be tricked to behave not like a corect Singelton
    auto& coppy = Singelton::get_instance();
    coppy.show_secter_number();


    return 0;
}

