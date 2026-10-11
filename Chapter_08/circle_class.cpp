#include <iostream>
#include <numbers>

class Circle
{
private:
    double radius;

public:
    // Construct a circle object
    Circle(double radius = 1)
        : radius{radius}
    {
    }

    double getPerimeter()
    {
        return 2 * radius * std::numbers::pi;
    }

    double getArea()
    {
        return radius * radius * std::numbers::pi;
    }

    void setRadius(double radius)
    {
        this->radius = radius; //this pint
    }
};

int main()
{
    Circle circle(5);

    std::cout << "Area: " << circle.getArea() << '\n';
    std::cout << "Perimeter: " << circle.getPerimeter() << '\n';

    circle.setRadius(10);

    std::cout << "New area: " << circle.getArea() << '\n';
    std::cout << "New perimeter: " << circle.getPerimeter() << '\n';

    return 0;
}