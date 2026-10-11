import std;
using namespace std;

class Date
{

private:
    // These are private
    int y, m, d; // year, month, day

public:
    // Constructor
    Date(int y, int m, int d);

    // Member functions
    void add_day(int n);
    int month();
    int day();
    int year();
};


// Date constructor
Date::Date(int y, int m, int d)
    : y{y}, m{m}, d{d}
{
}

// Add a number of days to the date
void Date::add_day(int n)
{
    d += n;
}

// Access the month
int Date::month()
{
    return m;
}

// Access the day
int Date::day()
{
    return d;
}

// Access the year
int Date::year()
{
    return y;
}

// friend
friend void get_date_info(const Date& date)
{
    std::print("{} / {} / {}\n", date.year(), date.month(), date.day());
}


int main()
{
    Date today{2026, 10, 1};

    print("Year: {}\n", today.year());
    print("Month: {}\n", today.month());
    print("Day: {}\n", today.day());

    today.add_day(5);

    print("After adding 5 days:\n", today.year(), today.month(), today.day());
    print("{} / {} / {}\n", today.year(), today.month(), today.day());
    get_date_info(get_date_info(today));

    return 0;
}