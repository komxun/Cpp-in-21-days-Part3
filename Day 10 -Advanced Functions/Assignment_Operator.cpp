// Listing 10.15 - An Assignmnet Operator (P.318)
#include <iostream>
using namespace std;

class Cat
{
    public:
        Cat();          // default constructor
        int GetAge() const {return *pItsAge;}
        int GetWeight() const {return *pItsWeight;}
        void SetAge(int age) {*pItsAge = age;}
        Cat & operator= (const Cat &);   // return a reference of an object
    private:
        int *pItsAge;
        int *pItsWeight;
};

Cat::Cat()
{
    // Initialize pointer - allocate memory in the heap
    pItsAge = new int;
    pItsWeight = new int;
    *pItsAge = 5;
    *pItsWeight = 9;
}

Cat & Cat::operator= (const Cat & rhs)
{
    if (this == &rhs)   // remember that pointer returns an address
    {
        return *this;   // return the current object
    }
    *pItsAge = rhs.GetAge();
    *pItsWeight = rhs.GetWeight();
    return *this;
}

int main()
{
    Cat Frisky;
    cout << "Frisky's age = " << Frisky.GetAge() << endl;
    cout << "Setting Frisky to 6 ... " << endl;
    Frisky.SetAge(6);
    Cat Whiskers;
    cout << "Whisker's age = " << Whiskers.GetAge() << endl;
    cout << "Setting Whisker's age = Frisky's age ... " << endl;
    Whiskers = Frisky;
    cout << "Whisker's age = " << Whiskers.GetAge() << endl;
    return 0;
}