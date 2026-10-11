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

int main()
{
    Month m = Month::nov;

    // ++m;

    print("Month before incrementing: {}\n", to_int(m)); // 12

    // ++m;
    m = m + 5;
    print("Month after adding n days: {}\n", to_int(m)); // 1
}

// Try out
// Write an overriding operaator that subtracts a number of months from a Month object.
// The operator should take a Month object and an integer as parameters,
// and return a new Month object that represents the month that is n months before the original month.
// If the result is less than 1, it should wrap around to the end of the year (i.e., December).