#include <iostream>

class ChildStudent {
protected:
TeacherContext *howIlearn;
public:
    virtual bool learn() = 0;
    virtual ~ChildStudent() = default;
};

class ChildStudentTopperImpl : public ChildStudent {

public:
        bool learn() override
        {
            howIlearn = new TeacherContext(new Reading1, new Counting1, new Time1,new Writing1);
            howIlearn->teachChildren();
            return true;  
        };
   ~ChildStudentTopperImpl()
   {
    delete howIlearn;
   }
};

class ChildStudentDummyImpl : public ChildStudent {

public:
        bool learn() override
        {
            howIlearn->teachChildren();
            return false;   
        };
};
//// Teaching methods hierarchies////
class TeachingReading{ //this can be still decoupled
public:
    virtual ~TeachingReading() = default;
    virtual void reading() = 0;
};

class Reading1 : public TeachingReading {
public:
    void reading() override {
        std::cout << "Read at the desk" << std::endl;
    }
};

class TeachingCounting{ //this can be still decoupled
public:
    virtual ~TeachingCounting() = default;

    virtual void counting() = 0;
};

class Counting1 : public TeachingCounting {

public:
    void counting() override {
        std::cout << "Count using fingers" << std::endl;
    }
};

class TeachingTime{ //this can be still decoupled
public:
    virtual ~TeachingTime() = default;

    virtual void getTime() = 0;
};

class Time1 : public TeachingTime {

public:
    void getTime() override {
        std::cout << "Read time from analog clock" << std::endl;
    }
};

class TeachingWriting{ //this can be still decoupled
public:
    virtual ~TeachingWriting() = default;

    virtual void writing() = 0;
};

class Writing1 : public TeachingWriting {

public:
    void writing() override {
        std::cout << "Writing full words" << std::endl;
    }
};

/// How learning works in this world ///
class TeacherContext {
    TeachingReading*  teachingreading;
    TeachingCounting* teachingcounting;
    TeachingTime*     teachingtime;
    TeachingWriting*  teachingwriting;
// Some defaul constructoe if child does not show any preference
public:
    //TeacherContext(TeachingStrategy* teachingStrategy) : teachingStrategy(teachingStrategy) {}
    TeacherContext(TeachingReading* teachingrd,
                   TeachingCounting* teachingct,
                   TeachingTime* teachingtm,
                   TeachingWriting* teachingwr):teachingreading(teachingrd),teachingcounting(teachingct),
                   teachingtime(teachingtm),teachingwriting(teachingwr)
    {
        std::cout << "Setting child teaching style" << std::endl; 
    }
    void teachChildren() {
       learnReading(teachingreading);
       learnCounting(teachingcounting);
       learnTellingTime(teachingtime);
       learnWriting(teachingwriting);
    }

protected:
    void learnReading(TeachingReading* teachingreading)
    {
        teachingreading->reading();
    };
    void learnCounting(TeachingCounting* teachingcounting)
    {
        teachingcounting->counting();
    };
    void learnTellingTime(TeachingTime* teachingtime)
    {
        teachingtime->getTime();
    };
    void learnWriting(TeachingWriting* teachingwriting)
    {
        teachingwriting->writing();
    };

    ~TeacherContext()
    {
        delete teachingreading;
        delete teachingcounting;
        delete teachingtime;
        delete teachingwriting;
    }
};

int main() {
    ChildStudent* childStudent1 = new ChildStudentTopperImpl();
    childStudent1->learn();

    
    ChildStudent* childStudent2 = new ChildStudentDummyImpl();

    delete childStudent1;
    delete childStudent2;
    return 0;
}