import std;
using namespace std;

// Read number into a vector
vector<int> readVardNumber();
int getPrefix(vector<int> number, int k);
bool prefixMatched(vector<int>);
int getSize(vector<int> number);
int sumOfOddPlace(vector<int> number);
int getDigit(int number);
int sumOfDoubleEvenPlace(vector<int> number);
bool isValid(vector<int> number);

// Return true if sum of (sum of doubles) and (sum of odds) is divisible by 10 and prefixMatch is true
bool isValid(vector<int> number)
{
    if (((sumOfDoubleEvenPlace(number) + sumOfOddPlace(number)) % 10 == 0) && prefixMatched(number) && 13 <= getSize(number) && getSize(number) <= 16)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int sumOfDoubleEvenPlace(vector<int> number)
{
    int sum = 0;
    // Start at position, i = 0 and incrment through with steps of 2
    for (int i = 0; i < number.size() - 1; i += 2)
    {
        int digit = number[i];
        // Double even number
        digit = digit * 2;

        // // if it is a double digit
        // if (digit >= 10)
        // {
        //     digit = digit / 10 + digit % 10;
        // }

        // else
        // {
        //     // Pass
        // }
        sum += getDigit(digit);
    }
    return sum;
}

// Return this number if it is a single digit, otherwise, return the sum of the two digits
int getDigit(int number)
{
    if (number < 10)
    {
        return number;
    }
    else
    {
        return number / 10 + number % 10;
    }
}

//Return sum of odd place digits in number\
int sumOfOddPlace(long long number);
int sumOfOddPlace(vector<int> number)
{
    int sum = 0;
    for (int i = 0; i < number.size(); i += 2)
    {
        sum += number[i];
    }
    return sum;
}

//Return the number of digits in d\
int getSize(long long d);
int getSize(vector<int> number)
{
    return number.size();
}

//Return true if the digit d is a prefix for number\
bool prefixMatched(long long number, int d);
bool prefixMatched(vector<int> number)
{
    if ((getPrefix(number, 1)) == 4 || (getPrefix(number, 1)) == 5 || (getPrefix(number, 2)) == 37 || (getPrefix(number, 1)) == 6)
    {
        return true;
    }

    else
    {
        return false;
    }
}

vector<int> readCardNumber()
{
    // long long number = 0;
    // cout << "Enter number: \n";
    // cin >> number;
    // cout << number << "\n";

    // vector<long long> card_digits;

    // while (number > 0)
    // {
    //     card_digits.push_back(number % 10);
    //     number /= 10;
    // }

    // reverse(card_digits.begin(), card_digits.end());
    // return card_digits;

    std::string number;

    std::cout << "Enter number: \n";
    std::cin >> number;

    std::vector<int> card_digits;

    for (char digit : number)
    {
        card_digits.push_back(digit - '0');
    }

    return card_digits;
}

//Return the first k number of digits from number. If the number of digits in number is less than k, return number.\
int getPrefix(std:vector<int> number, int k);
int getPrefix(std::vector<int> number, int k)
{
    int k_prefix = 0;

    int length = std::min(k, static_cast<int>(number.size()));

    for (int i = 0; i < length; i++)
    {
        k_prefix = k_prefix * 10 + number[i];
    }

    return k_prefix;
}

int main()
{
    vector<int> number = readCardNumber();
    cout << "Prefix: " << getPrefix(number, 2) << "\n";
    cout << "Matched: " << prefixMatched(number) << "\n";
    cout << "Size: " << getSize(number) << "\n";
    cout << "Sum of Odd Numbers " << sumOfOddPlace(number) << "\n";
    // cout << "Single number: " << getDigit(number) << "\n";
    cout << "Sum of double even numbers: " << sumOfDoubleEvenPlace(number) << "\n";
    cout << "Valid: " << isValid(number) << "\n";
}

// Valid examples
// 4242424242424242
