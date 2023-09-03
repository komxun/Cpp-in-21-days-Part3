// Listing 10.11 - Returning the dereferenced this pointer (P.309)
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
        const Counter& operator++ ();
    private:
        int itsVal;
};
//Constructor
Counter::Counter():
itsVal(0)
{};
const Counter& Counter::operator++()
{
    ++itsVal;
    return *this;  // returning a dereferenced this pointer
}

int main()
{
    Counter i;
    cout << "The value of i is " << i.GetItsVal() << endl;
    i.Increment();
    cout << "The value of i is " << i.GetItsVal() << endl;
    ++i;
    cout << "The valueo f i is " << i.GetItsVal() << endl;
    Counter a = ++i;
    cout << "The value of a: " << a.GetItsVal();
    cout << " and i: " << i.GetItsVal() << endl;
    return 0;
}