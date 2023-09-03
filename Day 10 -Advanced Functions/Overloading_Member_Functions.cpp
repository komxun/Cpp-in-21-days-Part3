// Listing 10.1 - Overloading class member functions (P.290)
#include <iostream>

// Rectnable class declaration
class Rectangle
{
    public:
        Rectangle(int width, int height); // constructor
        ~Rectangle() {};                  // destructor
        // overloaded class function DrawShape
        void DrawShape() const;
        void DrawShape(int aWidth, int aHeight) const;
    private:
        int itsWidth;
        int itsHeight;
};

//Constructor 
Rectangle::Rectangle(int width, int height)
{
    itsWidth = width;
    itsHeight = height;
}

// Overloaded DrawShape - take no values
void Rectangle::DrawShape() const
{
    DrawShape(itsWidth, itsHeight);  // Draw based on current class member values
}

// Overloaded Drawshape - take 2 values
void Rectangle::DrawShape(int width, int height) const
{
    for (int i=0; i<height; i++)
    {
        for (int j=0; j<width; j++)
        {
            std::cout << "*";
        }
        std::cout << std::endl;
    }
}

int main()
{
    // Start timer
    clock_t tic, toc;
    tic = clock();

    // initialize a rectangle to 30, 5
    Rectangle theRect(30,5);
    std::cout << "DrawShape(): " << std::endl;
    theRect.DrawShape();
    std::cout << "DrawShape(40,2): " << std::endl;
    theRect.DrawShape(40,2);
    
    // Stop timer
    toc = clock();
    double timeused = (double) (toc - tic)/(CLOCKS_PER_SEC);
    std::cout << "time used = " <<  timeused << " s." << std::endl;

    return 0;
}