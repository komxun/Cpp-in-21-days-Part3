// Listing 10.14 - Overload operator plus (+)
#include <iostream>
using namespace std;

class Counter
{
    public:
        Counter();
        Counter(int initialValue);
        ~Counter(){}
        int GetItsVal() const {return itsVal;}
        void SetItsVal(int x) {itsVal = x;}
        Counter operator+ (const Counter &);
    private:
        int itsVal;
};

Counter::Counter(int initialValue):
itsVal(initialValue)
{}

Counter::Counter():
itsVal(0)
{}

Counter Counter::operator+ (const Counter &rhs)
{
    return Counter(itsVal + rhs.GetItsVal());
}

int main()
{
    Counter varOne(2), varTwo(4), varThree;
    varThree = varOne + varTwo;
    cout << "varOne = " << varOne.GetItsVal() << endl;
    cout << "varTwo = " << varTwo.GetItsVal() << endl;
    cout << "varThree = " << varThree.GetItsVal() << endl;
    return 0;
}