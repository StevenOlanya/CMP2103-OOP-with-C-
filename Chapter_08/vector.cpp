// Operator overloading with vectors
// Read and understand the concept of operator overloading
// Read Chapter 7 to understand the difference between reference and value

import std;
using namespace std;

class Vector
{
    // Private data members
private:
    int x, y;

    // Public member functions
public:
    Vector(int x, int y)
        : x{x}, y{y}
    {
    }

    // Constant member functions promises not to modify the object
    int get_x() const { return x; }
    int get_y() const { return y; }
};

// Overloaded operators
Vector operator+(const Vector &a, const Vector &b)
{
    return Vector{a.get_x() + b.get_x(), a.get_y() + b.get_y()};
}

Vector operator-(const Vector &a, const Vector &b)
{
    return Vector{a.get_x() - b.get_x(), a.get_y() - b.get_y()};
}

// Overloaded operator for equality comparison

void print(const Vector &v)
{
    print("Vector({}, {})\n", v.get_x(), v.get_y());
}

int main()
{
    Vector v1{2, 4};
    Vector v2{5, 3};

    Vector v3 = v1 + v2;

    print(v1 - v2);
}


// Operator overloading with vectors
