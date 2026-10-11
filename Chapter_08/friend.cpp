
import std;
using namespace std;

class X
{
    int i;

public:
    X(int value) : i{value} {}

    void m();
    friend int get_value(const X &x);       // pass by const reference
    friend void set_value(X &x, int value); // pass by reference
    friend void print_value(X x);           // make copy of x
};

void X::m()
{
    i++;
}

// Read Chapter 7 to understand the difference between reference and value
int get_value(const X &x)
{
    return x.i; /* get_value(X&) can access X::i */
}

void set_value(X &x, int value)
{
    x.i = value; /* set_value(X&, int) can access X::i */
}

void print_value(X x) // Copies values of x
{
    std::print("Value: {}\n", x.i);
}

int main()
{
    X x{9};
    x.m();        // OK: X::m() is a member of X
    get_value(x); // OK: get_value(X&) is a friend of X

    // print("Access granted {}.\n", get_value()); // OK: get_value(X&) is a friend of X
    print("Accessed value {}.\n", get_value(x));

    // New value for x.i
    set_value(x, 42);
    print("New value set: {}.\n", get_value(x));

    print_value(x);
}