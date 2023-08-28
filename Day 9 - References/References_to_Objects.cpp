// Listing 9.4 - References to class objects (P.261)

#include <iostream>

class SimpleCat
{
    public:
        SimpleCat(int age, int weight);
        ~SimpleCat() {};
        int GetAge() {return itsAge;}
        int GetWeight() {return itsWeight;}
    private:
        int itsAge;
        int itsWeight;
};

SimpleCat::SimpleCat(int age, int weight)
{
    itsAge = age;
    itsWeight = weight;
}

int main()
{
    SimpleCat Frisky(5,8);
    SimpleCat & rCat = Frisky;  // Create a reference to Frisky

    std::cout << "Frisky is: ";
    std::cout << Frisky.GetAge() << " years old." << std::endl;
    std::cout << "And Frisky weighs: ";
    std::cout << rCat.GetWeight() << " pounds." << std::endl;

    return 0;
}