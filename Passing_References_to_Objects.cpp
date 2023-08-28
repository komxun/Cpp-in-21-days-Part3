// Listing 9.12 - Passing references to objects (P.278)
#include <iostream>
using namespace std;

class SimpleCat
{
    public:
        SimpleCat();            // constructor
        SimpleCat(SimpleCat&);  // copy constructor
        ~SimpleCat();            // destructor
        int GetAge() const {return itsAge;}
        void SetAge(int age) {itsAge = age;}
    private:
        int itsAge;

};

SimpleCat::SimpleCat()
{
    cout << "SimpleCat constructor..." << endl;
    itsAge = 1;
}

SimpleCat::SimpleCat(SimpleCat&)
{
    cout << "SimpleCat copy constructor..." << endl;
}

SimpleCat::~SimpleCat()
{
    cout << "SimpleCat destructor..." << endl;
}

// Function prototype
const SimpleCat & FunctionTwo(const SimpleCat &theCat);
// Return a reference of an object
// Argument is a reference of an object

int main()
{
    cout << "Making a cat..." << endl;
    SimpleCat Frisky;
    cout << "Frisky is " << Frisky.GetAge() << " years old" << endl;
    int age = 5;
    Frisky.SetAge(age);
    cout << "Frisky is " << Frisky.GetAge() << " years old" << endl;
    FunctionTwo(Frisky);
    cout << "Frisky is " << Frisky.GetAge() << " years old" << endl;
    return 0;
}

const SimpleCat & FunctionTwo(const SimpleCat &theCat)
{
    cout << "FunctionTwo. Returning ... "<< endl;
    cout << "Frisky is now " << theCat.GetAge();
    cout << " years old" << endl;
    // theCat.SetAge(8);  // Not allowed since const!
    return theCat;
}