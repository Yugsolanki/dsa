#include <iostream>
#include <stack>
#include <vector>
using namespace std;

vector<int> findPSE(vector<int> &arr)
{
    int n = arr.size();
    vector<int> pse(n);
    stack<int> st;

    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && arr[i] < arr[st.top()])
        {
            st.pop();
        }
        pse[i] = st.empty() ? -1 : st.top();
        st.push(i);
    }

    return pse;
}

vector<int> findNSE(vector<int> &arr)
{
    int n = arr.size();
    vector<int> nse(n);
    stack<int> st;

    for (int i = n - 1; i >= 0; i--)
    {
        while (!st.empty() && arr[i] <= arr[st.top()])
        {
            st.pop();
        }
        nse[i] = st.empty() ? n : st.top();
        st.push(i);
    }

    return nse;
}

int largestRectangleHistogram(vector<int> &arr)
{
    int n = arr.size();
    vector<int> pse = findPSE(arr);
    vector<int> nse = findNSE(arr);
    int result = 0;

    for (int i = 0; i < n; i++)
    {
        int area = arr[i] * (nse[i] - pse[i] - 1);
        result = max(result, area);
    }

    return result;
}

// Time Complexity : O(5N)
// Space Complexity : O(4N)

int largestRectangleHistogramOptimized(vector<int> &arr)
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

int main()
{
    vector<int> arr = {2, 1, 5, 6, 2, 3};
    cout << largestRectangleHistogramOptimized(arr) << endl;

    return 0;
}