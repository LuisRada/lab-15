#include <iostream>
#define PI 3.1416


int area(int side) {
    return side * side;
}


int area(int length, int width) {
    return length * width;
}


double area(double radius) {
    return PI * radius * radius;
}

int main() {
    std::cout << "Area of square (side=4): " << area(4) << std::endl;
    std::cout << "Area of rectangle (length=5, width=3): " << area(5, 3) << std::endl;
    std::cout << "Area of circle (radius=2.5): " << area(2.5) << std::endl;

    return 0;
}