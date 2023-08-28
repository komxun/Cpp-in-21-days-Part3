// Listing 9.5 - Demonstrate passing by value (P.263)
#include <iostream>

using namespace std;
void swap(int x, int y);

int main()
{
    int x = 5, y = 10;

    cout << "Main. Before swap, x = " << x << " y = " << y << endl;
    swap(x,y);
    cout << "Main. After swap, x = " << x << " y = " << y << endl;
    return 0;
}

void swap(int x, int y)
{
    int temp = x;
    cout << "Swap. Before swap, x = " << x << " y = " << y <<endl;
    x = y;
    y = temp;
    cout << "Swap. After swap, x = " << x << " y = " << y << endl;

    // This doesn't change the actual value of x and y since these are
    // the local copies of them and they are thrown away after
    // the function returned.
}