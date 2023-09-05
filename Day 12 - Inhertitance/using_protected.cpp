// Listing 12.2 - Using a derived object (P.377)
#include <iostream>
using std::cout;
using std::endl;

enum BREED{GOLDEN, CAIRN, DANDIE, SHETLAND, DOBERMAN, LAB};

class Mammal
{
    public:
        Mammal():itsAge(2), itsWeight(5){}   // Constructor
        ~Mammal(){} // Destructor

        // Accessors
        int GetAge() const {return itsAge;}
        void SetAge(int age){itsAge = age;}
        int GetWeight() const {return itsWeight;}
        void SetWeight(int weight){itsWeight = weight;}

        // Other methods
        void Speak() const {cout << "Mammal sound!" << endl;}
        void Sleep() const {cout << "shhh. I'm sleeping" << endl;}
    protected:
        int itsAge;
        int itsWeight;
};

class Dog : public Mammal
{
    public:
        Dog():itsBreed(GOLDEN){}   // constructor
        ~Dog() {}

        // Accessors
        BREED getBreed() const{return itsBreed;}
        void SetBreed(BREED x) {itsBreed = x;}

        // Other methods
        void WagTail() const {cout << "Tail wagging..." << endl;}
        void BegForFood() const {cout << "Begging for fodd..." << endl;}
    private:
        BREED itsBreed;
};

int main()
{
    Dog Fido;
    Fido.Speak();
    Fido.WagTail();
    cout << "Fido is " << Fido.GetAge() << " years old" << endl;
    return 0;
}