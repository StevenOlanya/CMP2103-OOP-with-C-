
#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

// Geometry: area of a triangle) Write a program that prompts the user to enter the
// three points (x1, y1), (x2, y2), and (x3, y3) of a triangle and displays its area.
// The formula for computing the area of a triangle is s = (side1 + side2 + side3) / 2
// Area = sqrt(s(s-side1)(s-side2)(s-side3))
// Example: Enter three points for a triangle: 1.5, -3.4, 4.6, 5, 9.5, -3.4 
// The area of the triangle is 33.6



double distance(double x1, double y1, double x2, double y2) {
    double dx = x2 - x1;
    double dy = y2 - y1;
    return sqrt(dx * dx + dy * dy);
}
int main() {
    double x1, y1, x2, y2, x3, y3;

    // Get the three points from the user
    cout << "Enter three points for a triangle: ";
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

    // Step 1: side lengths 

    double side1 = distance(x1, y1, x2, y2);   // between point 1 and point 2
    double side2 = distance(x2, y2, x3, y3);   // between point 2 and point 3
    double side3 = distance(x3, y3, x1, y1);   // between point 3 and point 1
    // --- Step 2: semi-perimeter --
    double s = (side1 + side2 + side3) / 2.0;
    
    // Step 3: Heron's formula 
    double area = sqrt(s * (s - side1) * (s - side2) * (s - side3));
    
    // Display the result 
    cout << fixed << setprecision(1);
    cout << "The area of the triangle is " << area << "\n";
    return 0;
}