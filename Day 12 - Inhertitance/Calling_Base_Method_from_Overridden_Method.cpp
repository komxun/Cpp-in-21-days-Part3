// Listing 12.7 - Calling a Base Method from a Overridden Method
#include <iostream>
using namespace std;

class Mammal
{
    public:
        void Move() const {cout << "Mammal move one step\n";}
        void Move(int distance) const
        {
            cout << "Mammal move " << distance << " steps" << endl;
        }
    protected:
        int itsAge;
        int itsWeight;
};

class Dog : public Mammal
{
    public:
        void Move() const;
};

void Dog::Move() const
{
    cout << "In dog move...\n";
    Mammal::Move(3);
}

int main()
{
    Mammal bigAnimal;
    Dog Fido;
    bigAnimal.Move(2);
    Fido.Mammal::Move(6);
    return 0;
}