#include "mbed.h"
#include <cstdio>
#include <cstring>

class Rectangle {
    private:
    float length; 
    float width;

    public:
// constructor to initialize length and width 
    Rectangle (float l, float w) {
        length = l;
        width = w;
    }
// calculate area
    float Area() {
        return length * width;
    }

// calculate perimeter
    float Perimeter() {
        return 2 * (length + width);
    }
};




// main() runs in its own thread in the OS
int main()
{
    printf("Program Starting...\n");
// create rectangle object 
    Rectangle rec1(6,4);

// output area and perimeter 
    printf("Rectangle Area: %f\n", rec1.Area());
    printf("Rectangle Perimeter: %.2f\n", rec1.Perimeter());
}

