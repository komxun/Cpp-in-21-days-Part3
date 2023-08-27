// Listing 9.1 - Demonstrating the use of references (P.256)

#include <iostream>
int main()
{
    using namespace std;
    int intOne;
    int &rSomeRef = intOne;  // Create a reference, targeting intOne

    intOne = 5;
    cout << "intOne = " << intOne << endl;
    cout << "rSomeRef = " << rSomeRef << endl;

    rSomeRef = 7;
    cout << "intOne = " << intOne << endl;
    cout << "rSomeRef = " << rSomeRef << endl;

    return 0;
}