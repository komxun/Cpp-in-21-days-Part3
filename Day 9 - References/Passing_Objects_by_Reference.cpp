// Listing 9.10 - Passing pointers to objects (P.272)
#include <iostream>
using namespace std;

class SimpleCat
{
    public:
        SimpleCat();            // Constructor
        SimpleCat(SimpleCat&);  // Copy constructor
        ~SimpleCat();           // Destructor
};

SimpleCat::SimpleCat()
{
    cout << "SimpleCat Constructor..." << endl;
}

SimpleCat::SimpleCat(SimpleCat&)
{
    cout << "SimpleCat Copy Constructor..." << endl;
}

SimpleCat::~SimpleCat()
{
    cout << "SimpleCat Destructor..." << endl;
}

// Function Prototypes
SimpleCat FunctionOne(SimpleCat theCat);
SimpleCat* FunctionTwo(SimpleCat *ptheCat);

int main()
{
    cout << "Making a cat..." << endl;
    SimpleCat Frisky;
    cout << "Calling FunctionOne..." << endl;
    FunctionOne(Frisky);
    cout << "Calling FunctionTwo..." << endl;
    FunctionTwo(&Frisky);
    return 0;
}

// FunctionOne, passes by value
SimpleCat FunctionOne(SimpleCat theCat)
{
    cout << "FunctionOne. Returning..." << endl;
    return theCat;
}

// FunctionTwo, passes by reference
SimpleCat* FunctionTwo(SimpleCat *pTheCat)
{
    cout << "FunctionTwo. Returning..." << endl;
    return pTheCat;
}

