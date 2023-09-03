// Listing 10.7 - Adding an Increment Operator (P.303)
#include <iostream>
using namespace std;

class Counter
{
    public:
        Counter();   // Default constructor
        ~Counter(){} // destructor
        int GetItsVal() const {return itsVal;}
        void SetItsVal(int x) {itsVal = x;}
        void Incremenet() {++itsVal;}
    private:
        int itsVal;
};
// Definition of constructor
Counter::Counter():
itsVal(0) // initialization
{}

int main()
{
    Counter i;
    cout << "The value of i is " << i.GetItsVal() << endl;
    i.Incremenet();
    cout << "The value of i is " << i.GetItsVal() << endl;
    return 0;
}