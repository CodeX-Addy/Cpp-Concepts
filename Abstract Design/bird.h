#if !defined(BIRD_H)
#define BIRD_H

class Bird{
    public:
    virtual void fly() = 0;
    virtual void eat() = 0;
};

class Sparrow : public Bird{
    public:
    void fly(){
        std::cout << "Sparrow is flying" << std::endl;
    }
    void eat(){
        std::cout << "Sparrow is eating" << std::endl;
    }
    
};

class Eagle : public Bird{
    public:
    void fly(){
        std::cout << "Eagle is flying" << std::endl;
    }
    void eat(){
        std::cout << "Eagle is eating" << std::endl;
    }
};



#endif