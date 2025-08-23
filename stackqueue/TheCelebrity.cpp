#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int celebrity(vector<vector<int>> &mat)
{
    int n = mat.size();
    vector<int> knowMe(n);
    vector<int> iKnow(n);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (mat[i][j] == 1)
            {
                knowMe[j]++;
                iKnow[i]++;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (knowMe[i] == n - 1 && iKnow[i] == 0)
        {
            return i;
        }
    }

    return -1;
}

// Time Complexity : O(N*N) + O(N)
// Space Complexity : O(2N)

int celebrityOptimized(vector<vector<int>> &mat)
{
    int n = mat.size();
    int top = 0, down = n - 1;

    while (top < down)
    {
        if (mat[top][down] == 1)
        {
            top++;
        }
        else if (mat[down][top] == 1)
        {
            down--;
        }
        // meaning both are 0 both don't know each other
        else
        {
            top--;
            down--;
        }
    }

    if (top > down)
        return -1;

    for (int i = 0; i < n; i++)
    {
        // avoid diagonal
        if (i == top)
            continue;
        
        if (mat[top][i] == 0 && mat[i][top] == 1)
            continue;
        else
            return -1;
    }

    return top;
}

// Time Complexity : O(2N)
// Space Complexity : O(1)

int main()
{
    vector<vector<int>> mat = {
        {0, 1, 1, 0},
        {0, 0, 0, 0},
        {0, 1, 0, 0},
        {1, 1, 0, 0}};

    cout << celebrityOptimized(mat) << endl;

    return 0;
}