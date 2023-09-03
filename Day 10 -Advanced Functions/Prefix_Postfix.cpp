// Listing 10.12 - Prefix and Postfix operator overloading
#include <iostream>
using namespace std;

class Counter
{
    public:
        Counter();
        ~Counter(){}
        int GetItsVal()const {return itsVal;}
        void SetItsVal(int x) {itsVal = x;}
        const Counter& operator++();    // prefix
        const Counter operator++ (int); // postfix
    private:
        int itsVal;
};

Counter::Counter():
itsVal(0)
{}

// prefix
const Counter& Counter::operator++()
{
    ++itsVal;
    return *this;
}

// postfix
const Counter Counter::operator++(int theFlag)
{
    Counter temp(*this);
    ++itsVal;
    return temp;
}

int main()
{
    Counter i;
    cout << "The value of i is " << i.GetItsVal() << endl;
    i++;
    cout << "The value of i is " << i.GetItsVal() << endl;
    ++i;
    cout << "The value of i is " << i.GetItsVal() << endl;
    Counter a = ++i;
    cout << "The value of a: " << a.GetItsVal();
    cout << " and i: " << i.GetItsVal() << endl;
    a = i++;
    cout << "The value of a: " << a.GetItsVal();
    cout << " and i: " << i.GetItsVal() << endl;
    return 0;
}
