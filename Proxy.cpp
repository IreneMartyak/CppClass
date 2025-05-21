#include <iostream>
#include <memory>


class Subject
{
public:
    Subject() = default;
    constexpr Subject(const Subject& other) = default;
    Subject& operator=(const Subject& other) = default;
    constexpr Subject( Subject&& other) = default;
    Subject& operator=( Subject&& other) = default;

	virtual void request() = 0;
	virtual ~Subject() = default;
};

class RealSubject : public Subject
{
public:

	void request() override {
		std::cout << "RealSubject.request()\n";
	}
};

class Proxy : public Subject
{
private:
    int _level = 0;
	std::shared_ptr<Subject> realSubject;
public:
    Proxy()
    {
        realSubject = std::make_shared<RealSubject>();
    }
	// Forward calls to the RealSubject:
	void request() override {
        if(_level > 2)
		{
            realSubject->request();
        }
	}
    bool confirn_security_clerance_update(int level)
    { 
        _level = level; 
        return true;
    }
};

int main() {
	Proxy proxy;
	proxy.request();
    
    //if(proxy.confirn_security_clerance_update(4))
    //{
    //    proxy.request();
    //}
        
    return 0;
}
