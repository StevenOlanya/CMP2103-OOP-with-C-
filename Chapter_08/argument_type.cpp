// Argument type

import std;
using namespace std;

enum class Month
{
    jan = 1,
    feb,
    mar,
    apr,
    may,
    jun,
    jul,
    aug,
    sep,
    oct,
    nov,
    dec
};

int to_int(Month m)
{
    return static_cast<int>(m);
}

Month operator++(Month &m)
{
    m = (m == Month::dec)
            ? Month::jan
            : Month{to_int(m) + 1};

    return m;
}

Month operator+(Month &m, int n)
{
    int month = to_int(m);

    month = (month + n) % 12;

    return Month{month};
}

// simple Date (use Month type)
class Date
{
public:
    // Date(int y, int m, int d); // check for valid date and initialize
    Date(int y, Month m, int d); // check for valid date and initialize
    // . . .

    int get_year() const;
    int get_month() const;
    int get_day() const;

private:
    // private data members
    int y;   // year
    Month m; // month
    int d;   // day
};

// Date::Date(int y, int m, int d)
//     : y{y}, m{m}, d{d}
// {
// }

Date::Date(int y, Month m, int d)
    : y{y}, m{m}, d{d}
{
}

// Memeber functions
int Date::get_year() const
{
    return y;
}

int Date::get_month() const
{

    // return m;
    return to_int(m);
}

int Date::get_day() const
{
    return d;
}

int main()
{
    // Date dx5{1998, 11, 30};
    Date dx5{1998, Month::nov, 30};

    // // ++m;

    // print("Month before incrementing: {}\n", to_int(m)); // 12

    // // ++m;
    // m = m + 5;
    // print("Month after adding n days: {}\n", to_int(m)); // 1

    print("{} / {} / {}\n",
          dx5.get_year(),
          dx5.get_month(),
          dx5.get_day());
}

// Try out
// Write an overriding operaator that subtracts a number of months from a Month object.
// The operator should take a Month object and an integer as parameters,
// and return a new Month object that represents the month that is n months before the original month.
// If the result is less than 1, it should wrap around to the end of the year (i.e., December).