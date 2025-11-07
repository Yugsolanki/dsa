#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// * Question 1: Return element at row=4, col=3

// calcutes nCr
int combinationCalculator(int n, int r)
{
    int res = 1;

    for (int i = 0; i < r; i++)
    {
        res = res * (n - i);
        res = res / (i + 1);
    }

    return res;
}
// TC: O(r)
// SC: O(1)

int getElementPascalTriangle(int r, int c)
{
    return combinationCalculator(r - 1, c - 1);
}
// TC: O(r)
// SC: O(1)

// * Question 2: Print Nth row of pascal triangle
void printNthRow(int n)
{
    int res = 1;
    cout << res << " ";

    for (int i = 1; i < n; i++)
    {
        res = (res * (n - i)) / i;
        cout << res << " ";
    }

    cout << endl;
}

// * Question 3: Print the entire Pascals triangle
vector<vector<int>> PascalsTriangle(int n)
{
    vector<vector<int>> triangle;

    for (int i = 1; i <= n; i++)
    {
        int res = 1;

        vector<int> temp;
        temp.push_back(res);

        for (int j = 1; j < i; j++)
        {
            res = (res * (i - j)) / j;
            temp.push_back(res);
        }

        triangle.push_back(temp);
    }

    return triangle;
}

int main()
{
    vector<int> arr = {1, 2, 3, -3, 1, 1, 1, 4, 2, -3};

    cout << getElementPascalTriangle(4, 2) << endl;

    printNthRow(6);

    cout << "----------------------------" << endl;

    vector<vector<int>> triangle = PascalsTriangle(6);

    for (vector<int> row : triangle)
    {
        for (int i : row)
        {
            cout << i << " ";
        }
        cout << endl;
    }
    cout << endl;
}