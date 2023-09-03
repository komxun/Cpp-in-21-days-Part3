// Listing 10.5 - Copy constructor (P.299)
#include <iostream>
using namespace std;

class Cat
{
    public:
        Cat();             // default constructor
        Cat(const Cat &);  // copy constructor
        ~Cat();           // destructor
        int GetAge() const {return *pItsAge;}
        int GetWeight() const {return *pItsWeight;}
        void SetAge(int age) {*pItsAge = age;}
    private:
        int *pItsAge;
        int *pItsWeight;

};
// Definition of a default constructor
Cat::Cat()
{
    pItsAge = new int;
    pItsWeight = new int;
    *pItsAge = 5;
    *pItsWeight = 9;
}

// Definition of a copy constructor
Cat::Cat(const Cat & rhs)
{
    pItsAge = new int;
    pItsWeight = new int;
    *pItsAge = rhs.GetAge();         // public access
    *pItsWeight = *(rhs.pItsWeight); // private access
}

// Destructor
Cat::~Cat()
{
    delete pItsAge;     // Delete the allocated memory 
    delete pItsWeight;  // (Note that the pointer is still there!)
    pItsAge = 0;     // point it to null (0)
    pItsWeight = 0;
}

int main()
{
    Cat Frisky;
    cout << "Frisky's age = " << Frisky.GetAge() << " years old" << endl;
    cout << "Setting Frisky's age to 6..." << endl;
    Frisky.SetAge(6);

    cout << "Creating Boots from Frisky" << endl;
    Cat Boots(Frisky);
    cout << "Frisky's age = " << Frisky.GetAge() << " years old" << endl;
    cout << "Boot's age = " << Boots.GetAge() << " years old" << endl;
    cout << "Setting Frisky's age to 7..." << endl;
    Frisky.SetAge(7);

    cout << "Frisky's age = " << Frisky.GetAge() << " years old" << endl;
    cout << "Boot's age = " << Boots.GetAge() << " years old" << endl;
    return 0;
}

 