// Listing 12.1 - Simple inheritance (P.374)
#include <iostream>
using namespace std;

enum BREED{GOLDEN, CAIRN, DANDIE, SHETLAND, DOBERMAN, LAB};

class Mammal
{
    public:
        Mammal();  // constructor
        ~Mammal(); // destructor

        // Accessors
        int GetAge() const;
        void SetAge(int);
        int GetWeight() const;
        void SetWeight() const;

        // Other methods
        void Speak() const;
        void Sleep() const;
    protected:          // visible to this class and to classes that derive from this class
        int itsAge;
        int itsWeight;
};

class Dog : public Mammal   // The Dog class inherits from Mammal
{
    public:
        Dog();  // constructor
        ~Dog(); // destructor
        
        // Accessors
        BREED GetBreed() const;
        void SetBreed(BREED);
        
        // Other methods
        WagTail();
        BegForFood();
    protected:
        BREED itsBreed;
};

