#include <iostream>
#include <iomanip>

using namespace std;

class Rectangle {
private:
    double width;
    double length;

public:
    // Default constructor: a 1 x 1 rectangle
    Rectangle() : width(1.0), length(1.0) {}

    // Parameterized constructor: reuses the setters so validation applies
    Rectangle(double w, double l) : width(1.0), length(1.0) {
        setWidth(w);
        setLength(l);
    }

    // Getters 
    double getWidth() const { return width; }
    double getLength() const { return length; }

    // Setters (reject non-positive values)
    bool setWidth(double w) {
        if (w <= 0) {
            return false;
        }
        width = w;
        return true;
    }

    bool setLength(double l) {
        if (l <= 0) {
            return false;
        }
        length = l;
        return true;
    }

    // Area = length * width
    double calculateArea() const {
        return length * width;
    }

    // Perimeter = 2 * (length + width)
    double calculatePerimeter() const {
        return 2 * (length + width);
    }
};

// Helper to print a rectangle's details
void display(const string& name, const Rectangle& r) {
    cout << name << ":\n";
    cout << "  Width     = " << r.getWidth() << "\n";
    cout << "  Length    = " << r.getLength() << "\n";
    cout << "  Area      = " << r.calculateArea() << "\n";
    cout << "  Perimeter = " << r.calculatePerimeter() << "\n\n";
}

int main() {
    cout << fixed << setprecision(2);

    // Example 1: default constructor
    cout << " Example 1: Default rectangle \n";
    Rectangle rect1;
    display("rect1", rect1);

    // Example 2: parameterized constructor
    cout << " Example 2: Rectangle created with dimensions \n";
    Rectangle rect2(5.0, 8.0);
    display("rect2", rect2);

    // Example 3: using setters on an existing object
    cout << " Example 3: Using setters \n";
    Rectangle rect3;
    rect3.setWidth(4.5);
    rect3.setLength(10.2);
    display("rect3", rect3);

    // Example 4: modifying dimensions after creation
    cout << " Example 4: Changing dimensions  \n";
    cout << "rect2 before: " << rect2.getWidth() << " x " << rect2.getLength()
         << ", area = " << rect2.calculateArea() << "\n";
    rect2.setWidth(6.0);
    rect2.setLength(9.0);
    cout << "rect2 after:  " << rect2.getWidth() << " x " << rect2.getLength()
         << ", area = " << rect2.calculateArea() << "\n\n";

    // Example 5: invalid input is rejected
    cout << " Example 5: Invalid input \n";
    if (!rect3.setWidth(-3.0)) {
        cout << "setWidth(-3.0) rejected; width is still "
             << rect3.getWidth() << "\n";
    }
    if (!rect3.setLength(0)) {
        cout << "setLength(0) rejected; length is still "
             << rect3.getLength() << "\n\n";
    }

    // Example 6: a square is a rectangle with equal sides
    cout << " Example 6: Square (width = length)  \n";
    Rectangle square(7.0, 7.0);
    display("square", square);

    return 0;
}
