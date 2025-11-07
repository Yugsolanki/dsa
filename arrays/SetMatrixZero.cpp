#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> setMatrixZero(vector<vector<int>> &arr)
{
    int n = arr.size();
    int m = arr[0].size();

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (arr[i][j] == 0)
            {
                // mark row -1
                int k = 0;
                while (k < m)
                {
                    if (arr[i][k] != 0)
                        arr[i][k] = -1;
                    k++;
                }

                // mark entier column -1
                k = 0;
                while (k < n)
                {
                    if (arr[k][j] != 0)
                        arr[k][j] = -1;
                    k++;
                }
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (arr[i][j] == -1)
            {
                arr[i][j] = 0;
            }
        }
    }

    return arr;
}
// TC: O(n*m)*(n*m) + O(n*m)
// SC: O(1)

vector<vector<int>> setMatrixZeroOptimal(vector<vector<int>> &arr)
{
    int n = arr.size();
    int m = arr[0].size();
    int col0 = 1;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (arr[i][j] == 0)
            {
                arr[i][0] = 0; // mark row

                if (j == 0)
                    col0 = 0;
                else
                    arr[0][j] = 0; // mark column
            }
        }
    }

    // Marking all not first row and column
    for (int i = n - 1; i >= 1; i--)
    {
        for (int j = m - 1; j >= 1; j--)
        {
            // for row
            if (arr[i][0] == 0)
            {
                arr[i][j] = 0;
            }

            // for column
            if (arr[0][j] == 0)
            {
                arr[i][j] = 0;
            }
        }
    }

    // Now marking first row
    for (int i = m - 1; i >= 0; i--)
    {
        if (arr[0][0] == 0)
            arr[0][i] = 0;
    }

    // Now marking first column
    for (int i = 0; i < n; i++)
    {
        if (col0 == 0)
            arr[i][0] = 0;
    }

    return arr;
}

int main()
{
    vector<vector<int>> arr = {
        {1, 1, 1, 1},
        {1, 0, 1, 1},
        {1, 1, 0, 1},
        {0, 1, 1, 1}};

    vector<vector<int>> res = setMatrixZeroOptimal(arr);

    for (auto a : res)
    {
        for (int i : a)
        {
            cout << i << " ";
        }
        cout << endl;
    }
    cout << endl;

    return 0;
}