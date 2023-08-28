// Listing 9.11 - Passing pointers to objects (P.275)
#include <iostream>
using namespace std;

class SimpleCat
{
    public:
        SimpleCat();            // Constructor
        SimpleCat(SimpleCat&);  // Copy constructor
        ~SimpleCat();           // Destructor

        int GetAge() const {return itsAge;}
        void SetAge(int age) {itsAge = age;}
    private:
        int itsAge;
};

SimpleCat::SimpleCat()
{
    cout << "SimpleCat Constructor..." << endl;
    itsAge = 1;
}

SimpleCat::SimpleCat(SimpleCat&)
{
    cout << "SimpleCat Copy Constructor..." << endl;
}

SimpleCat::~SimpleCat()
{
    cout << "SimpleCat Destructor..." << endl;
}

// Function Prototype
const SimpleCat * const FunctionTwo(const SimpleCat * const ptheCat);
// Output is a constant pointer to a constant object
// An argument is a constant pointer to a constant object
// E.g. consider           int * Function(int * pPointer)
// Now make const    const int * const Function(const int * const pPointer)

int main()
{
    cout << "Making a cat..." << endl;
    SimpleCat Frisky;
    cout << "Frisky is " << Frisky.GetAge() << " years old." << endl;
    int age = 5;
    Frisky.SetAge(age);
    cout << "Frisky is " << Frisky.GetAge() << " years old." << endl;

    cout << "Calling FunctionTwo..." << endl;
    FunctionTwo(&Frisky);
    cout << "Frisky is " << Frisky.GetAge() << " years old." << endl;
    return 0;
}

const SimpleCat * const FunctionTwo(const SimpleCat * const pTheCat)
{
    cout << "FunctionTwo. Returning ... " << endl;
    cout << "Frisky is now " << pTheCat->GetAge() << " years old" << endl;
    // theCat-> SetAge(8);  // Not allowed since const!!
    return pTheCat;
}