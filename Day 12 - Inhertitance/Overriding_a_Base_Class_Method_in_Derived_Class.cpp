// Listing 12.5 - Overriding a Base Class Method in a Derived Class (P.386)
#include <iostream>
using std::cout;

enum BREED {GOLDEN, CAIRN, DANDIE, SHETLAND, DOBERMAN, LAB};

class Mammal
{
    public:
        Mammal() {cout << "Mammal constructor...\n";}
        ~Mammal(){cout << "Mammal destructor...\n";}
        void Speak() const {cout << "Mammal sound!\n";}
        void Sleep() const {cout << "shhh. I'm sleeping \n";}
    protected:
        int itsAge;
        int itsWeight;
};

class Dog : public Mammal
{
    public:
        Dog() {cout << "Dog constructor...\n";}
        ~Dog() {cout << "Dog destructor...\n";}
        void WagTail() const {cout << "Tail wagging...\n";}
        void BegForFood() const {cout << "Begging for food...\n";}
        void Speak() const {cout << "Woof!\n";} // Overiding a base class method
    private:
        BREED itsBreed;
};

int main()
{
    Mammal bigAnimal;
    Dog Fido;
    bigAnimal.Speak();
    Fido.Speak();
    return 0;
}