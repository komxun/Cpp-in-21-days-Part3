// Listing 10.8 - Overloading operator++ (P.304)
#include <iostream>
using namespace std;

class Counter
{
    public:
        Counter();
        ~Counter(){}
        int GetItsVal() const {return itsVal;}
        void SetItsVal(int x) {itsVal = x;}
        void Increment() {++itsVal;}
        void operator++() {++itsVal;} // returns void
    private:
        int itsVal;
};

Counter::Counter():
itsVal(0)  // Initialization
{}

int main()
{
    Counter i;
    cout << "The value of i is " << i.GetItsVal() << endl;
    i.Increment();
    cout << "The value of i is " << i.GetItsVal() << endl;
    ++i;  // valid since that operator is already defined to a class
    cout << "The value of i is " << i.GetItsVal() << endl;
    return 0; 
}