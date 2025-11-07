#include <iostream>
#include <vector>
using namespace std;

vector<int> spiralTraversal(vector<vector<int>> &arr)
{
    int n = arr.size();
    int m = arr[0].size();

    int left = 0, right = m - 1;
    int top = 0, bottom = n - 1;

    vector<int> res;

    while (left <= right && top <= bottom)
    {

        for (int i = left; i <= right; i++)
        {
            res.push_back(arr[top][i]);
        }
        top++;

        for (int i = top; i <= bottom; i++)
        {
            res.push_back(arr[i][right]);
        }
        right--;

        if (top <= bottom)
        {
            for (int i = right; i >= left; i--)
            {
                res.push_back(arr[bottom][i]);
            }
            bottom--;
        }

        if (left <= right)
        {
            for (int i = bottom; i >= top; i--)
            {
                res.push_back(arr[i][left]);
            }
            left++;
        }
    }

    return res;
}

// TC: O(n*m)
// SC: O(n*m)

int main()
{
    vector<vector<int>> arr = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}};

    vector<int> res = spiralTraversal(arr);

    for (int i : res)
    {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}