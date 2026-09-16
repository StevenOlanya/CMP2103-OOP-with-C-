module;

#include <vector>
#include <fstream>
#include <iostream>


export module check_soduku_solution;

export bool isValidAt(
    int row,
    int col,
    const std::vector<std::vector<int>> &grid)
{
    // Check row
    for (int j = 0; j < 9; ++j)
    {
        if (j != col && grid[row][j] == grid[row][col])
        {
            return false;
        }
    }

    // Check column
    for (int i = 0; i < 9; ++i)
    {
        if (i != row && grid[i][col] == grid[row][col])
        {
            return false;
        }
    }

    // Check 3x3 box
    int boxRow = (row / 3) * 3;
    int boxCol = (col / 3) * 3;

    for (int i = boxRow; i < boxRow + 3; ++i)
    {
        for (int j = boxCol; j < boxCol + 3; ++j)
        {
            if (i != row &&
                j != col &&
                grid[i][j] == grid[row][col])
            {
                return false;
            }
        }
    }

    return true;
}

export bool isValid(
    const std::vector<std::vector<int>> &grid)
{
    for (int i = 0; i < 9; ++i)
    {
        for (int j = 0; j < 9; ++j)
        {
            if (!isValidAt(i, j, grid))
            {
                return false;
            }
        }
    }

    return true;
}

// Read Sudoku solution from a file
export std::vector<std::vector<int>> readASolution()
{
    std::ifstream file("sudoku.txt");

    if (!file)
    {
        std::cerr << "Could not open sudoku.txt" << std::endl;
        return {};
    }

    std::vector<std::vector<int>> grid(9, std::vector<int>(9));

    for (int i = 0; i < 9; ++i)
    {
        for (int j = 0; j < 9; ++j)
        {
            if (!(file >> grid[i][j]))
            {
                std::cerr << "Invalid Sudoku file." << std::endl;
                return {};
            }
        }
    }

    return grid;
}