// Listing 10.13 - Add function (P.313)
#include <iostream>
using namespace std;

class Counter
{
    public:
        Counter();
        Counter(int intialVal);  // custom constructor
        ~Counter(){}             // destructor
        int GetItsVal() const {return itsVal;}
        void SetItsVal(int x) {itsVal = x;}
        Counter Add(const Counter &);   // takes in the reference of object
    private:
        int itsVal;
};

Counter::Counter(int initalVal):
itsVal(initalVal)
{}

Counter::Counter():
itsVal(0)
{}

Counter Counter::Add(const Counter &rhs)
{
    return Counter(itsVal + rhs.GetItsVal());
}

int main()
{
    Counter varOne(2), varTwo(4), varThree;
    varThree = varOne.Add(varTwo);
    cout << "varOne = " << varOne.GetItsVal() << endl;
    cout << "varTwo = " << varTwo.GetItsVal() << endl;
    cout << "varThree = " << varThree.GetItsVal() << endl;
    return 0;
}