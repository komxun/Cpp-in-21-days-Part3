// Listing 8.6 - Accessing data members of objects on the heap (P.240)
// using the -> operator

#include <iostream>

class SimpleCat
{
    public:
        SimpleCat() {itsAge = 2;}  // Custom constructor (default age = 2)
        ~SimpleCat() {}            // Destructor
        int GetAge() const {return itsAge;}
        void SetAge(int age) {itsAge = age;}
    private:
        int itsAge;
};

int main()
{
    using namespace std;
    SimpleCat * pFrisky = new SimpleCat;   // Allocate memory for SimpleCat on Heap
    cout << "Frisky is " << pFrisky -> GetAge() << " years old." << endl;
    pFrisky -> SetAge(5);  // the indirection (->) operator is used to access the member data and funcitons
    cout << "Frisky is " << pFrisky -> GetAge() << " years old." << endl;
    delete pFrisky;
    return 0;
}