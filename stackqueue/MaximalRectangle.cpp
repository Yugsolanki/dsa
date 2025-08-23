#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int largestRectangleHistogram(vector<int> &arr)
{
    int n = arr.size();
    stack<int> st;
    int maxArea = 0;

    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && arr[st.top()] > arr[i])
        {
            int idx = st.top();
            st.pop();

            int nse = i;
            int pse = st.empty() ? -1 : st.top();
            int area = arr[idx] * (nse - pse - 1);
            maxArea = max(maxArea, area);
        }
        st.push(i);
    }

    while (!st.empty())
    {
        int nse = n;
        int idx = st.top();
        st.pop();
        int pse = st.empty() ? -1 : st.top();
        int area = arr[idx] * (nse - pse - 1);
        maxArea = max(maxArea, area);
    }

    return maxArea;
}

int maximalRectangle(vector<vector<int>> &arr)
{
    int m = arr[0].size();
    int n = arr.size();
    vector<vector<int>> prefixArr(n, vector<int>(m, 0));

    for (int j = 0; j < m; j++)
    {
        int sum = 0;

        for (int i = 0; i < n; i++)
        {
            sum += arr[i][j];

            if (arr[i][j] == 0)
                sum = 0;

            prefixArr[i][j] = sum;
        }
    }

    int maxArea = 0;

    for (int i = 0; i < n; i++)
    {
        maxArea = max(maxArea, largestRectangleHistogram(prefixArr[i]));
    }

    return maxArea;
}

int main()
{
    vector<vector<int>> arr = {
        {1, 0, 1, 0, 1},
        {1, 0, 1, 1, 1},
        {1, 1, 1, 1, 1},
        {1, 0, 0, 1, 0}};

    cout << maximalRectangle(arr) << endl;
    return 0;
}