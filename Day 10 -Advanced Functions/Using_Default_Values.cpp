// Listing 10.2 Default Values in member functions (P.292)
#include <iostream>
using namespace std;

class Rectangle
{
    public:
        Rectangle(int width, int height);
        ~Rectangle() {}
        void DrawShape(int w, int h, bool useCurrentVals = false) const;
                        // useCurrentVals = false by default
    private:
        int itsWidth;
        int itsHeight;
};

Rectangle::Rectangle(int width, int  height):
itsWidth(width),        // initialization
itsHeight(height)
{}                      // empty body

// Default values used for 3rd parameter
void Rectangle::DrawShape(int width, int height, bool useCurrentValue) const
{
    int printWidth;
    int printHeight;

    if (useCurrentValue == true)
    {
        printWidth = itsWidth;  // use current class values (ignore input)
        printHeight = itsHeight;
    }
    else
    {
        printWidth = width; // use parameter values
        printHeight = height;
    }
    for (int i=0; i<printHeight; i++)
    {
        for (int j=0; j<printWidth; j++)
        {
            cout << "*";
        }
        cout << endl;
    }

}

// Main Program
int main()
{
    Rectangle theRect(30,5);
    cout << "DrawShape(0,0,true): " << endl;
    theRect.DrawShape(0,0,true);
    cout << "DrawShape(40,2): " << endl;
    theRect.DrawShape(40,2);
    return 0;
}
