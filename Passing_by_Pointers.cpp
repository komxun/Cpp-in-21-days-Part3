// Listing 9.6 - Demonstrates passing by reference (P.264)
#include <iostream>

using namespace std;
void swap(int *px, int *py);  // the arguments will be pointers

int main()
{
    int x = 5, y = 10;

    cout << "Main. Before swap, x = " << x << " y = " << y << endl;
    swap(&x, &y);   // The input must be addresses so that pointer can be initialized
    cout << "Main. After swap, x = " << x << " y = " << y << endl;
    return 0;
}

void swap(int *px, int *py) // Create pointer from the input addresses
{
    int temp;
    cout << "Swap. Before swap, *px = " << *px << " *py = " << *py << endl;

    temp = *px;         
    *px = *py;          // This change is occured at the address,
    *py = temp;         // not local variable

    cout << "Swap. After swap, *px = " << *px << " *py = " << *py << endl;

}