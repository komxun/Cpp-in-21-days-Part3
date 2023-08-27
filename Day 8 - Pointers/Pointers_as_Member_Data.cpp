// Listing 8.7 - Pointers as data members (P.241)
// accessed with -> operator

#include <iostream>

class SimpleCat
{
    public:
        SimpleCat();
        ~SimpleCat();
        int GetAge() const {return *pItsAge;}
        void SetAge(int age) {*pItsAge = age;}
        int GetWeight() const {return *pItsWeight;}
        void SetWeight(int weight) {*pItsWeight = weight;}
    private:
        int * pItsAge;      // pointer
        int * pItsWeight;   // pointer
};

// Custom Constructor
SimpleCat::SimpleCat()
{
    pItsAge = new int(2);  // allocate memory on Heap and assign a value
    pItsWeight = new int(5);
}

SimpleCat::~SimpleCat()
{
    delete pItsAge; // free the Heap memory allocated by pointer 
    delete pItsWeight;
}

int main()
{
    using namespace std;
    SimpleCat *pFrisky = new SimpleCat;
    cout << "Frisky is " << pFrisky -> GetAge() << " years old." << endl;
    pFrisky -> SetAge(5);
    cout << "Frisky is " << pFrisky-> GetAge() << " years old." << endl;
    delete pFrisky; // This calls a destructor
    return 0;
}