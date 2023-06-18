// Listing 8.2 - Manipulating Data by using Pointers
// (P.228)

#include <iostream>

typedef unsigned short int USHORT; // create synonym

int main()
{
    using namespace std;

    USHORT myAge;       // a Variable
    USHORT *pAge = 0;   // a Pointer

    myAge = 5;
    cout << "myAge: " << myAge << endl;
    
    pAge = &myAge;     // assign myAge's address to pAge
    cout << "*pAge: " << *pAge; // dereference (get a vallue from)

    cout << "\n\nSetting *pAge = 7...\n";
    *pAge = 7;          // dereference and set myAge to 7

    cout << "*pAge: " << *pAge << endl;
    cout << "myAge: " << myAge << endl;

    cout << "\nSetting myAge = 9..." << endl;
    myAge = 9;

    cout << "myAge: " << myAge << endl;
    cout << "*pAge: " << *pAge << endl;

    return 0; 
}
