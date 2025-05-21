#include <iostream>
#include <memory>

class AbstractInterface
{
    protected:
        AbstractInterface() =default;
        AbstractInterface(const AbstractInterface& other) = default;
        AbstractInterface& operator=(const AbstractInterface& other) = default;
        AbstractInterface( AbstractInterface&& other) = default;
        AbstractInterface& operator=( AbstractInterface&& other) = default;
    public:
        virtual void someFunctionality() = 0;
        virtual ~AbstractInterface() = default;
};

/* Interface for internal implementation that Bridge uses. */
class ImplementationInterface
{
    protected:
        ImplementationInterface(const ImplementationInterface& other) = default;
        ImplementationInterface& operator=(const ImplementationInterface& other) = default;
        ImplementationInterface( ImplementationInterface&& other) = default;
        ImplementationInterface& operator=( ImplementationInterface&& other) = default;
    public:
        ImplementationInterface() = default;
        virtual void anotherFunctionality() = 0;
        virtual ~ImplementationInterface() = default;
};

/* The Bridge */
class Bridge : public AbstractInterface
{
    private:
        std::shared_ptr<ImplementationInterface> implementation;
    protected:
        Bridge() = default;
        const std::shared_ptr<ImplementationInterface> getImplementation(){ return implementation;};

    public:
        explicit Bridge(const std::shared_ptr<ImplementationInterface>& backend):implementation(backend){}
        void setImplementation(const std::shared_ptr<ImplementationInterface>& new_implementation)
        {
            if(new_implementation!=implementation)
            {
                implementation = new_implementation;
            }
                
        }
};

/* Different special cases of the interface. */

class UseCase1 : public Bridge
{
    //using Bridge::Bridge;
    public:
        explicit UseCase1(const std::shared_ptr<ImplementationInterface>& backend):Bridge(backend){};

        void someFunctionality() override
        {
            std::cout << "UseCase1 on ";
            getImplementation()->anotherFunctionality();
        }
};

class UseCase2 : public Bridge
{
    //using Bridge::Bridge;
    public:
        explicit UseCase2(const std::shared_ptr<ImplementationInterface>& backend):Bridge(backend){};

        void someFunctionality() override
        {
            std::cout << "UseCase2 on ";
            getImplementation()->anotherFunctionality();
        }
};

/* Different background implementations. */

class Windows : public ImplementationInterface
{
    public:
        void anotherFunctionality() override
        {
            std::cout << "Windows :-! \n";
        }
};

class Linux : public ImplementationInterface
{
    public:
        void anotherFunctionality() override
        {
            std::cout << "Linux! :-) \n";
        }
};

int main()
{
    auto osWindows = std::make_shared<Windows>();
    auto osLinux = std::make_shared<Linux>();
    
    /* First case */
    {
    UseCase1 useCase(osWindows);

    useCase.someFunctionality();

    useCase.setImplementation(osLinux);
    useCase.someFunctionality();
    }

    /* Second case */
    {
    UseCase2 useCase(osWindows);
    useCase.someFunctionality();

    useCase.setImplementation(osLinux);
    useCase.someFunctionality();
    }


    return 0;
}
