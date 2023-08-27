// Listing 8.9 - Demonstrates a stray pointer (P.246)
// Avoid runing this code - it could lock up the computer!!!

typedef unsigned short int USHORT;
#include <iostream>

int main()
{
    USHORT * pInt = new USHORT;
    *pInt = 10;
    std::cout << "*pInt = " << *pInt << std::endl;
    delete pInt;

    long *pLong = new long;
    *pLong = 90000;
    std::cout << "*pLong = " << *pLong << std::endl;

    *pInt = 20;     // Uh oh, this was deleted !

    std::cout << "*pInt = " << *pInt << std::endl;
    std::cout << "*pLong = " << *pLong << std::endl;
    delete pLong;
    return 0;
}