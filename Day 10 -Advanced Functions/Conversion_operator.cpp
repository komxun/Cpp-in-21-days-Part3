// Listing 10.18 - Converting from Counter to unsigned short() (P.324)
#include <iostream>
class Counter
{
    public:
        Counter();
        Counter(int val);
        ~Counter(){}
        int GetItsVal() const {return itsVal;}
        void SetItsVal(int x) {itsVal = x;}
        operator unsigned int();   // Conversion operator - no return type
    private:
        int itsVal;
};

Counter::Counter():
itsVal(0)
{}

Counter::Counter(int val):
itsVal(val)
{}

Counter::operator unsigned int()
{
    return (int(itsVal));  
}

int main()
{
    Counter ctr(5);
    int theInt = ctr;
    std::cout << "theInt = " << theInt << std::endl;
    return 0;
}