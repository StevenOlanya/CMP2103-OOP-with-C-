#include <iostream>

// User defined type
// Understant the concept of operator overloading

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

    month = (month - 1 + n) % 12 + 1;

    return Month{month};
}

int main()
{
    Month m = Month::nov;

    ++m;

    std::cout << to_int(m) << '\n'; // 12

    ++m;
    m = m + 1;
    std::cout << to_int(m) << '\n'; // 1
}