// Listing 9.3 - Reassigning a referencce
// **Reference variables cannot be reassigned**

#include <iostream>

int main()
{
    using namespace std;
    int intOne;
    int &rSomeRef = intOne;
    cout << "intOne =     " << intOne << endl;
    cout << "rSomeRef =   " << rSomeRef << endl;
    cout << "&intOne =    " << &intOne << endl;
    cout << "&rSomeRef =  " << &rSomeRef << endl;

    int intTwo = 8;
    rSomeRef = intTwo;   // Not what you think !!
                         // equivalent to  intOne = intTwo
    cout << "\nintOne =   " << intOne << endl;
    cout << "intTwo =     " << intTwo << endl;
    cout << "rSomeRef =   " << rSomeRef << endl;
    cout << "&intOne =    " << &intOne << endl;
    cout << "&intTwo =    " << &intTwo << endl;
    cout << "&rSomeRef =  " << &rSomeRef << endl;

    return 0;   
}