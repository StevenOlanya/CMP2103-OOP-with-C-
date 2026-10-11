import std;

using namespace std;

class Circle
{
    double radius; // private data member
public:
    Circle(double r); // default constructor
    double getRadius()
    { // public member function to access private data member
        return radius;
    }

    void setRadius(double r)
    { // public member function to modify private data member
        radius = r;
    }
};

Circle::Circle(double r = 1.0) : radius{r} {} // constructor with parameter

int main()
{
    Circle small_circle{};
    // small_circle.setRadius(5.0); // Set the radius using the public member function

    print("Radius of the circle: {}\n", small_circle.getRadius()); // Get the radius using the public member function
}
