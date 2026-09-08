// (Population projection) UBoS projects population based on the
// following assumptions:
// One birth every 7 seconds
// One death every 13 seconds
// One new immigrant every 45 seconds
// Write a program to display the population for each of the next five years. Assume the current population is 312032486 and one year has 365 days.

#include <iostream>
using namespace std;

int main()
{
    

//define te constants for total population and number of days in a year
constexpr long long population = 312032486;
constexpr long long year = 365;
constexpr long long birth_per_sec =7;
constexpr long long death_per_sec =13;
constexpr long long imigrants =45;
constexpr long long Years_to_Project = 5;


//calculate seconds per year
long long sec_per_day = (24 *60*60);
long long Seconds_per_Year = sec_per_day*year;


//population increase per Year
long long birthsPerYear = Seconds_per_Year/birth_per_sec;

//population decrease
long long DeathsPerYear = Seconds_per_Year/death_per_sec;

//immigrants

long long    ImmigrantsPerYear = Seconds_per_Year/imigrants;

//net increase in population per year
long long netIncrease = birthsPerYear - DeathsPerYear + ImmigrantsPerYear;

//for each year, calculate and display the projected population
for (int i = 1; i <= Years_to_Project; ++i) {
    long long projectedPopulation = population + (netIncrease * i);
    std::cout << "Population after Year " << i << ": " << projectedPopulation << '\n';
}   


	return 0;
}


