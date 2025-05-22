#include <iostream>
#include <string>
#include <memory>


class Mediator;

class Colleage
{
public:
    virtual ~Colleage();
    virtual void SetMediator(std::shared_ptr<Mediator>);
    virtual void SendMsg(std::string) = 0;
    virtual void GetMsg(std::string) = 0;
protected:
    Colleage(std::shared_ptr<Mediator>);
    std::shared_ptr<Mediator> _mediator;
private:
    
};

class ConcreteColleageA : public Colleage
{
public:
    ~ConcreteColleageA();
    ConcreteColleageA(std::shared_ptr<Mediator>);
    virtual void SendMsg(std::string msg);
    virtual void GetMsg(std::string);
protected:
private:
};

class ConcreteColleageB : public Colleage
{
public:
    ~ConcreteColleageB();
    ConcreteColleageB(std::shared_ptr<Mediator>);
    virtual void SendMsg(std::string msg);
    virtual void GetMsg(std::string);
protected:
private:
};

class Mediator
{
public:
    virtual ~Mediator();
    virtual void SendMsg(std::string, std::unique_ptr<Colleage>) = 0;
protected:
    Mediator();
private:
};

class ConcreteMediator : public Mediator
{
public:
    ConcreteMediator();
    ~ConcreteMediator();
    void SetColleageA(std::unique_ptr<Colleage>);
    void SetColleageB(std::unique_ptr<Colleage>);
    virtual void SendMsg(std::string msg, std::unique_ptr<Colleage> coleague);
protected:
private:
    std::unique_ptr<Colleage> m_ColleageA;
    std::unique_ptr<Colleage> m_ColleageB;
};


Colleage::Colleage(std::shared_ptr<Mediator> pMediator)
{
    this->_mediator = pMediator;
}

Colleage::~Colleage()
{}

void Colleage::SetMediator(std::shared_ptr<Mediator> pMediator)
{
    this->_mediator = pMediator;
}

ConcreteColleageA::ConcreteColleageA(std::shared_ptr<Mediator> pMediator) : Colleage(pMediator)
{
}

ConcreteColleageA::~ConcreteColleageA()
{
}

void ConcreteColleageA::SendMsg(std::string msg)
{
    this->_mediator->SendMsg(msg, std::make_unique<Colleage>(*this));
}

void ConcreteColleageA::GetMsg(std::string msg)
{
    std::cout <<"ConcreteColleageA Receive:"<< msg << "\n";
}

ConcreteColleageB::ConcreteColleageB(std::shared_ptr<Mediator> pMediator) : Colleage(pMediator)
{
}

ConcreteColleageB::~ConcreteColleageB()
{
}

void ConcreteColleageB::SendMsg(std::string msg)
{
    this->_mediator->SendMsg(msg,std::make_unique<Colleage>(*this));
}

void ConcreteColleageB::GetMsg(std::string msg)
{
    std::cout <<"ConcreteColleageB Receive:" <<msg << "\n";
}

Mediator::Mediator()
{}

Mediator::~Mediator()
{}

ConcreteMediator::ConcreteMediator()
{}

ConcreteMediator::~ConcreteMediator()
{}

void ConcreteMediator::SetColleageA(std::unique_ptr<Colleage> p)
{
    this->m_ColleageA =std::move(p) ;
}

void ConcreteMediator::SetColleageB(std::unique_ptr<Colleage> p)
{
    this->m_ColleageB = std::move(p);
}

void ConcreteMediator::SendMsg(std::string msg,std::unique_ptr<Colleage> p)
{
    if(p == this->m_ColleageA)
    {
        this->m_ColleageB->GetMsg(msg);
    }
    else if(p == this->m_ColleageB)
    {
        this->m_ColleageA->GetMsg(msg);
    }
}

int main()
{
    ConcreteMediator* pMediator = new ConcreteMediator();

    auto p1 = std::make_shared<ConcreteColleageA>(pMediator);
    auto p2 = std::make_shared<ConcreteColleageB>(pMediator);

    pMediator->SetColleageA(p1);
    pMediator->SetColleageB(p2);

    p1->SendMsg("xxx");
    p2->SendMsg("ooo");
    return 0;
}