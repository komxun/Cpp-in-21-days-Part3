// Listing 8.10 - Using Pointers to const Objects (P.249)
#include <iostream>

class Rectangle
{
    public:
        Rectangle();
        ~Rectangle();
        void SetLength(int length) {itsLength = length;}
        int GetLength() const {return itsLength;}
        void SetWidth(int width) {itsWidth = width;}
        int GetWidth() const {return itsWidth;}
    private:
        int itsLength;
        int itsWidth;
};

// Custom Constructor
Rectangle::Rectangle()
{
    itsWidth = 5;
    itsLength = 10;
}

Rectangle::~Rectangle()
{}

int main()
{
    using namespace std;
    Rectangle *pRect = new Rectangle;
    const Rectangle *pConstRect = new Rectangle; // the rectangle is constant and can't change its value
    Rectangle * const pConstPtr = new Rectangle; // the pointer is constant and can't point to anything else

    cout << "pRect width = " << pRect -> GetWidth() << " ft." << endl;
    cout << "pConstRect width = " << pConstRect -> GetWidth() << " ft." << endl;
    cout << "pConstPtr width = " << pConstPtr -> GetWidth() << " ft." << endl;

    pRect -> SetWidth(10);
    // pConstRect -> SetWidth(10);
    pConstPtr -> SetWidth(10);
    cout << endl;

    cout << "pRect width = " << pRect -> GetWidth() << " ft." << endl;
    cout << "pConstRect width = " << pConstRect -> GetWidth() << " ft." << endl;
    cout << "pConstPtr width = " << pConstPtr -> GetWidth() << " ft." << endl;


    return 0;
}