// Listing 10.9 - Returning a Temporary Object (P.306)
#include <iostream>
using namespace std;

class Counter
{
    public:
        Counter();
        ~Counter() {}
        int GetItsVal() const {return itsVal;}
        void SetItsVal(int x) {itsVal = x;}
        void Increment() {++itsVal;}
        Counter operator++ ();  // an operator returning a temporary object
    private:
        int itsVal;
};

Counter::Counter():
itsVal(0)
{}

Counter Counter::operator++()
{
    ++itsVal;
    Counter temp;           // Create a temporary object
    temp.SetItsVal(itsVal); // assign the incremented value to this object
    return temp;            // Return the temporary object
}

int main()
{
    Counter i;
    cout << "The value of i is " << i.GetItsVal() << endl;
    i.Increment();
    cout << "The value of i is " << i.GetItsVal() << endl;
    ++i;
    cout << "The value of i is " << i.GetItsVal() << endl;
    Counter a = ++i;
    cout << "The value of a: " << a.GetItsVal();
    cout << " and i: " << i.GetItsVal() << endl;
    return 0;
}