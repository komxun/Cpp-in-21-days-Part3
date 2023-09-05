// Listing 12.3 - Contructors and Destructors called
#include <iostream>
using namespace std;
enum BREED {GOLDEN, CAIRN, DANDIE, SHETLAND, DOBERMAN, LAB};

class Mammal
{
    public:
        Mammal();  // constructor
        ~Mammal(); // destructor
        int GetAge() const {return itsAge;}
        void SetAge(int x) {itsAge = x;}
        int GetWeight() const {return itsWeight;}
        void SetWeight(int x) {itsWeight = x;}
        void Speak() const {cout <<"Mammal sound!" << endl;}
        void Sleep() const {cout << "Shhh. I'm sleeping" << endl;}
    protected:
        int itsAge;
        int itsWeight;
};

class Dog : public Mammal
{
    public:
        Dog();  // constructor
        ~Dog(); // destructor
        BREED GetBreed() const {return itsBreed;}
        void SetBreed(BREED x) {itsBreed = x;}
        void WagTail() const {cout << "Tail Wagging..." << endl;}
        void BegForFood() const {cout << "Begging for food..." << endl;}
    private:
        BREED itsBreed;
};

Mammal::Mammal()
{
    std::cout << "Mammal constructor..." << endl;
}
Mammal::~Mammal()
{
    std::cout << "Mammal destructor..." << endl;
}
Dog::Dog()
{
    std::cout << "Dog constructor..." << endl;
}
Dog::~Dog()
{
    std::cout << "Dog destructor..." << endl;
}
int main()
{
    Dog Fido;
    Fido.Speak();
    Fido.WagTail();
    std::cout << "Fido is " << Fido.GetAge() << " years old" << endl;
    return 0;
}