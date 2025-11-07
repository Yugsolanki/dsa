#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> rotateMatrix90Degree(vector<vector<int>> &arr)
{
    int n = arr.size();
    int m = arr[0].size();

    // Transpose the matrix first
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < m; j++)
        {
            swap(arr[i][j], arr[j][i]);
        }
    }

    for (vector<int> &row : arr)
    {
        reverse(row.begin(), row.end());
    }

    return arr;
}

int main()
{
    vector<vector<int>> arr = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}};

    vector<vector<int>> res = rotateMatrix90Degree(arr);

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