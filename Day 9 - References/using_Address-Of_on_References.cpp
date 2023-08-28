// Listing 9.2 - Demonstrating the use of references (P.256)

#include <iostream>
int main()
{
    using namespace std;
    int intOne;
    int &rSomeRef = intOne;

    intOne = 5;
    cout << "intOne = " << intOne << endl;
    cout << "rSomeRef = " << rSomeRef << endl;

    cout << "&intOne   = " << &intOne << endl;
    cout << "&rSomeRef = " << &rSomeRef << endl;

    return 0;
}