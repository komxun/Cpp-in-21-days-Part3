// Listing 8.8 - Using the "this" pointer (P.244)
#include <iostream>
class Rectangle
{
    public:
        Rectangle();
        ~Rectangle();
        void SetLength(int length){this->itsLength = length;} // using 'this' pointer
        int GetLength() const {return this->itsLength;}       // using 'this' pointer
        void SetWidth(int width){itsWidth = width;}
        int GetWidth() const {return itsWidth;}
    private:
        int itsLength;
        int itsWidth;
};

// Custom constructor
Rectangle::Rectangle()
{
    itsWidth = 5;
    itsLength = 10;
}

// Destructor
Rectangle::~Rectangle()
{}


int main()
{
    using namespace std;
    Rectangle theRect;
    cout << "theRect is " << theRect.GetLength() << " feet long." << endl;
    cout << "theRect is " << theRect.GetWidth() << " feet wide." << endl;
    theRect.SetLength(20);
    theRect.SetWidth(10);
    cout << "theRect is " << theRect.GetLength() << " feet long." << endl;
    cout << "theRect is " << theRect.GetWidth() << " feet wide." << endl;
    return 0;
}