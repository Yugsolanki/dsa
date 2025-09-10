#include <iostream>
#include <vector>
using namespace std;

void printArrayOfArray(vector<vector<char>> &arr)
{
    for (auto i : arr)
    {
        for (char j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
    cout << endl;
}

bool isSafe(int row, int col, int c, vector<vector<char>> &board)
{
    for (int i = 0; i < 9; i++)
    {
        // check row
        if (board[i][col] == c)
            return false;

        // check col
        if (board[row][i] == c)
            return false;

        // row formula = 3 * (row / 3) + i / 3
        // Explanation: row/3 gives us the block number in vertical direction
        // multiplying by 3 gives us the starting row of that block
        // i/3 gives us the offset in the block in vertical direction
        // adding both gives us the correct row in the block
        // row = 5, col = 7
        // i = 0 -> (3 * (5/3) + 0/3) -> (3 * 1 + 0) -> 3
        // col formula = 3 * (col / 3) + i % 3
        // Explanation: col/3 gives us the block number in horizontal direction
        // multiplying by 3 gives us the starting col of that block
        // i%3 gives us the offset in the block in horizontal direction
        // adding both gives us the correct col in the block
        // i = 0 -> (3 * (7/3) + 0%3) -> (3 * 2 + 0) -> 6
        if (board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == c)
            return false;
    }
    return true;
}

bool Sudoko(vector<vector<char>> &board)
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (board[i][j] == '.')
            {
                for (char c = '1'; c <= '9'; c++)
                {
                    if (isSafe(i, j, c, board))
                    {
                        board[i][j] = c; // it's safe so fill it up baby

                        if (Sudoko(board) == true)
                            return true;
                        else
                            board[i][j] = '.';
                    }
                }

                // this will hit when no number is found to be placed in the cell
                // all the numbers are tried and none of them worked
                // meaning the previous placements were wrong
                // so we need to backtrack
                return false;
            }
        }
    }

    return true;
}

int main()
{
    vector<vector<char>> arr(9, vector<char>(9, '.'));
    Sudoko(arr);
    printArrayOfArray(arr);
    return 0;
}