//Listing 8.4 - Allocating and deleting a pointer (P.236)
#include <iostream>
int main()
{
    using namespace std;
    int localVariable = 5;
    int * pLocal = &localVariable;    // initialize pointer pointing at the address of localVaribale
    int * pHeap = new int;            // allocate memory on free store for an int
    *pHeap = 7;                       // Assign a value to the allocated memory
    cout << "localVariable = " << localVariable << endl;
    cout << "*pLocal = " << *pLocal << endl; // dereference the pLocal pointer
    cout << "*pHeap = " << *pHeap << endl;   // dereference the pHeap pointer
   
   // Free the memoery and disassociates the pointer from that memory
    delete pHeap;       // Without these two lines
    pHeap = new int;    // the memory will be leaked !!
   

    *pHeap = 9;
    cout << "*pHeap = " << *pHeap << endl;
    delete pHeap;
    return 0;

    return 0;
}