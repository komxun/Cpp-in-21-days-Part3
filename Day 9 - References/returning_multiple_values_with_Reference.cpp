// Listing 9.9 - Returning multiple values from a function using references (P.270)
#include <iostream>
using namespace std;

enum ERR_CODE{SUCCESS, ERROR};
ERR_CODE Factor(int, int &, int &);  // argument 2 and 3 are references

int main()
{
    int number, squared, cubed;
    ERR_CODE result;

    cout << "Enter a number (0 - 20): ";
    cin >> number;

    result = Factor(number, squared, cubed);

    if (result == SUCCESS)
    {
        cout << "number = " << number << endl;
        cout << "squared = " << squared << endl;
        cout << "cubed = " << cubed << endl;
    }
    else
    {
        cout << "Error encountered!" << endl;
    }
    return 0;
}

ERR_CODE Factor(int num, int &rSquared, int &rCubed)
{
    if (num > 20)
    {
        return ERROR;
    }
    else
    {
        rSquared = num*num;
        rCubed = num*num*num;
    }
    return SUCCESS;

}