// Listing 9.14 - Resolving memory leaks (P.283)
#include <iostream>

class SimpleCat
{
    public:
        SimpleCat(int age, int weight);
        ~SimpleCat() {}
        int GetAge() {return itsAge;}
        int GetWeight() {return itsWeight;}
    private:
        int itsAge;
        int itsWeight;
};

SimpleCat::SimpleCat(int age, int weight)
{
    itsWeight = weight;
    itsAge = age;
}

// Function Prototype
SimpleCat & TheFunction();   // Return a reference to an object

int main()
{
    SimpleCat & rCat = TheFunction();  // Create a reference to an object
    int age = rCat.GetAge();
    std::cout << "rCat is "<< age << " years old!" << std::endl;
    std::cout << "&rCat: "<< &rCat << std::endl;
    // How do you get rid of that memory??
    SimpleCat * pCat = &rCat;  // Create a pointer pointing to an address of reference
    delete pCat;               // Attempting to regain the memory by deleting this pointer
    // Uh oh, rCat now refers to ??
    return 0;
}

SimpleCat &TheFunction()
{
    SimpleCat * pFrisky = new SimpleCat(5,9);  // create a pointer pointing to
                                              // an allocated memory on a FreeStore
    std::cout << "pFrisky: " << pFrisky << std::endl;
    return *pFrisky;
}