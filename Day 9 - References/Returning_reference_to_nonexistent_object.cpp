// Listing 9.13 - Returning a Reference to a Nonexistent Object
// which no longer exist  (P.282)
#include <iostream>

class SimpleCat
{
    public:
        SimpleCat(int age, int weight); // constructor
        ~SimpleCat() {}                 // destructor        
        int GetAge(){return itsAge;}
        int GetWeight(){return itsWeight;}
    private:
        int itsAge;
        int itsWeight;
};

SimpleCat::SimpleCat(int age, int weight)
{
    itsAge = age;
    itsWeight = weight;
}

SimpleCat &TheFunction();  // Function prototype
                           // returning a reference of an object
int main()
{
    SimpleCat &rCat = TheFunction();
    int age = rCat.GetAge();
    std::cout << "rCat is " << age << " years old!" << std::endl;
    return 0;     
}

SimpleCat & TheFunction()
{
    SimpleCat Frisky(5,9);   // Create a SimpleCat object
    return Frisky;   // this returns the local object by reference
}                    // BUT the local object is destroyed in the end of funciton
                     // So the reference is an alias to a NONEXISTENT object (ERROR!)