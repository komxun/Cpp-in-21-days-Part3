// Listing 9.8 - Returning multiple values from a function
# include <iostream>
using namespace std;

short Factor(int n, int *pSquared, int *pCubed);

int main()
{
    int number, squared, cubed;
    short error;

    cout << "Enter a number (0 - 20): ";
    cin >> number;

    error = Factor(number, &squared, &cubed);

    if (!error)
    {
        cout << "number : " << number << endl;
        cout << "square : " << squared << endl;
        cout << "cubed : " << cubed << endl;
    }
    else
    {
        cout << "Error encountered!!" << endl;
    }
    return 0;
}

short Factor(int n, int *pSquared, int *pCubed)
{
    short err = 0;
    if (n > 20)
    {
        err = 1;
    }
    else
    {
        *pSquared = n*n;  // output value 1
        *pCubed = n*n*n;  // output value 2
        err = 0;          // default return value
    }
    return err;
}