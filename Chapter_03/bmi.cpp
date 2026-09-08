
#include <iostream>
#include <iomanip>
using namespace std;

//TODO
// Write a program that prompts the user to enter a weight in pounds and height in inches and
// then displays the BMI. Note that one pound is 0.45359237 kilograms and one inch is
// 0.0254 meters. Listing 4.6 gives the program.

// Conditions
// Below 18.5 Underweight
// 18.5–24.9 Normal
// 25.0–29.9 Overweight
// Above 30.0 Obese

// Enter weight in pounds:
// Enter Weight in pounds: 146
// Enter height in inches: 70
// BMI is 20.95
// Normal

int main() {
    //  Conversion constants
    constexpr double KG_PER_POUND  = 0.45359237;
    constexpr double METERS_PER_INCH = 0.0254;

    // Get input from the user 
    double weightPounds, heightInches;

    //Prompts user to enter weight in pounds
    cout << "Enter weight in pounds: ";
    cin >> weightPounds;

     //Prompts user to enter height in inches
    cout << "Enter height in inches: ";
    cin >> heightInches;

    // Convert to metric units 
    double weightKg = weightPounds * KG_PER_POUND;
    double heightM  = heightInches * METERS_PER_INCH;

    //  Compute BMI 
    double bmi = weightKg / (heightM * heightM);

    // Display the BMI, rounded to 2 decimal places 
    cout << fixed << setprecision(2);
    cout << "BMI is " << bmi << "\n";

    //  Classify and display the category 
    if (bmi < 18.5) {
        cout << "Underweight\n";
    } else if (bmi < 25.0) {
        cout << "Normal\n";
    } else if (bmi < 30.0) {
        cout << "Overweight\n";
    } else {
        cout << "Obese\n";
    }


    return 0;
}