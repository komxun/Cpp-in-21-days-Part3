// Listing 12.4 - Overloading constructors in derived classes (P.381)
#include <iostream>
using namespace std;

enum BREED {GOLDEN, CAIRN, DANDIE, SHETLAND, DOBERMAN, LAB};

class Mammal
{
    public:
        Mammal();           // Default constructor
        Mammal(int age);    // Custom constructor
        ~Mammal();          // Destructor
        
        //Accessors
        int GetAge() const {return itsAge;}
        void SetAge(int x) {itsAge = x;}
        int GetWeight() const {return itsWeight;}
        void SetWeight(int x) {itsWeight = x;}
        
        //Other methods
        void Speak() const{cout << "Mammal sound!" << endl;}
        void Sleep() const {cout << "shhh. I'm sleeping." << endl;}
    protected:
        int itsAge;
        int itsWeight;
};

class Dog : public Mammal
{
    public:
        Dog();          // Default constructor
        Dog(int age);               // Overloaded constructor 1
        Dog(int age, int weight);   // Overloaded constructor 2
        Dog(int age, BREED breed);  // Overloaded constructor 3
        Dog(int age, int weight, BREED breed); // Overloaded constructor 4
        ~Dog();

        // Accessors
        BREED GetBreed() const {return itsBreed;}
        void SetBreed(BREED x) {itsBreed = x;}

        // Other methods
        void WagTail() const {cout << "Tail wagging..."  << endl;}
        void BegForFood() const {cout << "Begging for food..." << endl;}
    private:
        BREED itsBreed;
};

Mammal::Mammal():
itsAge(1), itsWeight(5)
{
    cout << "Mammal() constructor..." << endl;
}

Mammal::Mammal(int age):
itsAge(age), itsWeight(5)
{
    cout << "Mammal(int) constructor..." << endl;
}

Mammal::~Mammal()
{
    cout << "Mammal destructor..." << endl;
}

Dog::Dog():
Mammal(),   // call the mammal constructor
itsBreed(GOLDEN)
{
    cout << "Dog() constructor..." << endl;
}

Dog::Dog(int age):
Mammal(age), itsBreed(GOLDEN)
{
    cout << "Dog(int) constructor..." << endl;
}

Dog::Dog(int age, int weight):
Mammal(age), itsBreed(GOLDEN) 
{
    itsWeight = weight; // since weight is not defined in any Mammal constructors
    cout << "Dog(int, int) constructor..." << endl;
}

Dog::Dog(int age, int weight, BREED breed):
Mammal(age), itsBreed(breed)
{
    itsWeight = weight;
    cout << "Dog(int, int, BREED) constructor..." << endl;
}

Dog::Dog(int age, BREED breed):
Mammal(age), itsBreed(breed)
{
    cout << "Dog(int, BREED) constructor..." << endl;
}

Dog::~Dog()
{
    cout << "Dog destructor..." << endl;
}

int main()
{
    Dog Fido;
    Dog rover(5);
    Dog buster(6,8);
    Dog yorkie(3,GOLDEN);
    Dog dobbie (4,20,DOBERMAN);
    Fido.Speak();
    rover.WagTail();
    cout << "Yorkie is " << yorkie.GetAge() << " years old" << endl;
    cout << "Dobbie's weight is " << dobbie.GetWeight() << " pounds" << endl;
    return 0;
}