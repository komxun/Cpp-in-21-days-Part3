// Listing 10.3 - Overloading the Constructor (P.295)
#include <iostream>
using namespace std;

class Rectangle
{
    public:
        Rectangle();   // Default constructor
        Rectangle(int width, int length);  // Overloaded constructor
        ~Rectangle() {}
        int GetWidth() const {return itsWidth;}
        int GetLength() const {return itsLength;}
    private:
        int itsWidth;
        int itsLength;
};

// Definition of Default constructor
Rectangle::Rectangle()
{
    itsWidth = 5;
    itsLength = 10;
}
// Definition of overloaded constructor
Rectangle::Rectangle(int width, int length)
{
    itsWidth = width;
    itsLength = length;
}

int main()
{
    Rectangle Rect1;  // use default constructor
    cout << "Rect1 width: " << Rect1.GetWidth() << endl;
    cout << "Rect1 length: " << Rect1.GetLength() << endl;

    int aWidth, aLength;
    cout << "Enter a width: ";
    cin >> aWidth;
    cout << endl << "Enter a length: ";
    cin >> aLength;

    Rectangle Rect2(aWidth, aLength); // use overloaded constructor
    cout << "\nRect2 width: "  << Rect2.GetWidth() << endl;
    cout << "Rect2 length: " << Rect2.GetLength() << endl;
    return 0;
}