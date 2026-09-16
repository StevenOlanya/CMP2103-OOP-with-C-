// A program that reads a soduku solution from a file and determines if it is right or not.

#include <iostream>
using namespace std;

import check_soduku_solution;

int main()
{
    vector<vector<int>> grid = readASolution();

    if (isValid(grid))
    {
        cout << "The Sudoku solution is valid." << endl;
    }
    else
    {
        cout << "The Sudoku solution is not valid." << endl;
    }

    return 0;
}