import std;
using namespace std;
// simple Date (many people prefer implementation details last)
class Date
{
public:
    Date(int y, int m, int d); // constructor declaration
    void add_day(int n);       // increase the Date by n days
    int month();
    // ...
private:
    int y, m, d; // year, month, day
};

Date::Date(int yy, int mm, int dd) // constructor
    : y{yy}, m{mm}, d{dd}          // note: member initializers
{
}


// Define member functions outside the class definition
void Date::add_day(int n)
{
    Date.d += 1;
}

// Define member functions outside the class definition
int Date::month() // oops: we forgot Date::
{
    return m; // not the member function, can’t access m
}

int main()
{
    Date today{2026, 5, 5};
    print(today);
}