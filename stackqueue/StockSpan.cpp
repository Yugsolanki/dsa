#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int stockSpan(vector<int> &arr)
{
    int n = arr.size();
    stack<int> st;
    int days = 0;

    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && arr[st.top()] <= arr[i])
        {
            st.pop();
        }

        int pge = st.empty() ? -1 : st.top();
        days = max(days, i - pge);
        st.push(i);
    }

    return days;
}

// Time Complexity : O(2N)
// Space Complexity : O(N)

int main()
{
    vector<int> arr = {7, 2, 1, 3, 3, 1, 8};
    cout << stockSpan(arr) << endl;

    vector<int> arr2 = {2, 2, 0, 0, 0};
    cout << stockSpan(arr2) << endl;

    return 0;
}