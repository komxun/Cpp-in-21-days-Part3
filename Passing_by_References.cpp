// Listing 9.7 - Demonstrates passing by reference using reference (P.266)
#include <iostream>

using namespace std;
void swap(int &rx, int &ry);  // the arguments will be references
                             // important to declare function prototype!
int main()
{
    int x = 5, y = 10;
    cout << "Main. Before swap, x = " << x << " y = " << y << endl;
    swap(x, y);;
    cout << "Main. After swap, x = " << x << " y = " << y  << endl;

    return 0;
}

void swap(int &rx, int &ry)  // create references to the input x and y
{
    int temp;
    cout << "Swap. Before swap, rx = " << rx << " ry = " << ry << endl;

    temp = rx;
    rx = ry;
    ry = temp;

    cout << "Swap. After swap, rx = " << rx << " ry = " << ry << endl; 
}