// Listing 8.1 - Demonstrating the Address-of Operator (P.223)
// and addresses of local variables

# include <iostream>

int main()
{
    using namespace std;
    unsigned short shortVar = 5;
    unsigned long  longvar = 65535;
    long sVar = -65535;

    cout << "shortVar: " << shortVar;
    cout << "\tAddress of shortVar: ";
    cout << &shortVar << endl;

    cout << "longVar: " << longvar;
    cout << "\tAddress of longVar: ";
    cout << &longvar << endl;

    cout << "sVar: " << sVar;
    cout << "\tAdress of sVar: ";
    cout << &sVar << endl;

    return 0; 
}