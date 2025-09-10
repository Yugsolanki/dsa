#include <iostream>
#include <vector>
using namespace std;

void printArrayOfArray(vector<vector<int>> &arr)
{
    for (auto i : arr)
    {
        for (int j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
    cout << endl;
}

bool isSafe(int row, int col, vector<vector<int>> &arr)
{
    int n = arr.size();

    // * Check row before
    int i = row;
    int j = col;
    while (j >= 0)
    {
        if (arr[i][j] == 1)
            return false;
        j--;
    }

    // * Check upper diagonal
    i = row;
    j = col;
    while (i >= 0 && j >= 0)
    {
        if (arr[i][j] == 1)
            return false;
        i--;
        j--;
    }

    // * Check lower diagonal
    i = row;
    j = col;
    while (i < arr.size() && j >= 0)
    {
        if (arr[i][j] == 1)
            return false;
        i++;
        j--;
    }

    return true;
}

void NQueens(int col, vector<vector<int>> &arr)
{
    if (col == arr.size())
    {
        printArrayOfArray(arr);
        return;
    }

    for (int i = 0; i < arr.size(); i++)
    {
        if (isSafe(i, col, arr))
        {
            arr[i][col] = 1;
            NQueens(col + 1, arr);
            arr[i][col] = 0;
        }
    }
}

int main()
{
    vector<vector<int>> arr = {
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0}};

    NQueens(0, arr);

    return 0;
}