// ============================================================
// Lab: More Details about Classes
// Course: Object-Oriented Programming (C++)
// Level: 2nd Year Engineering
// Duration: 60 minutes
// ============================================================

#include <iostream>
#include <string>

// ============================================================
// CLASS DEFINITIONS
// ============================================================

class Point {
private:
    double x;
    double y;
public:
    // TODO 1: Constructor with member initializer list (double x, double y)
    Point(double x, double y) : x(0), y(0) {}  // stub — fix initializer

    // TODO 2: const getter for x
    double getX() { return x; }   // stub — add const

    // TODO 3: const getter for y
    double getY() { return y; }   // stub — add const

    // TODO 4: const display()
    void display() const { std::cout << "(?, ?)"; }

    // TODO 5: declare Rectangle as friend class
};


class Rectangle {
private:
    Point topLeft;
    Point bottomRight;
public:
    // TODO 6: constructor with member initializer list
    Rectangle(double x1, double y1, double x2, double y2)
        : topLeft(0,0), bottomRight(0,0) {}  // stub — fix initializer

    // TODO 7: const getWidth()
    double getWidth() const { return 0; }  // stub

    // TODO 8: const getHeight()
    double getHeight() const { return 0; }  // stub

    // TODO 9: const getArea()
    double getArea() const { return 0; }  // stub

    // TODO 10: const display()
    void display() const {}

    // TODO 11: declare isSameSize as friend function
};


// TODO 12: implement isSameSize
bool isSameSize(const Rectangle& r1, const Rectangle& r2) {
    return false;  // stub
}


class ConstDemo {
private:
    int value;
public:
    // TODO 13: constructor with member initializer list
    ConstDemo(int v) : value(0) {}  // stub — fix initializer

    // TODO 14: const getValue()
    int getValue() { return value; }  // stub — add const

    // TODO 15: NON-const doubleValue() — multiplies value by 2
    void doubleValue() {}  // stub

    // TODO 16: const constGetDouble() — returns value * 2 without modifying
    int constGetDouble() { return 0; }  // stub — add const + fix body
};


// ============================================================
// MAIN
// ============================================================
int main() {
    // TODO 17-21: demo code
    std::cout << "Complete the TODOs above!" << std::endl;
    return 0;
}
