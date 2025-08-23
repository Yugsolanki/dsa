#include <iostream>
#include <stack>
#include <vector>
using namespace std;

vector<int> findPGE(vector<int> &arr)
{
    int n = arr.size();
    vector<int> pge(n);
    stack<int> st;

    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && arr[i] > arr[st.top()])
        {
            st.pop();
        }

        pge[i] = st.empty() ? -1 : st.top();
        st.push(i);
    }

    return pge;
}

vector<int> findNGE(vector<int> &arr)
{
    int n = arr.size();
    vector<int> nge(n);
    stack<int> st;

    for (int i = n - 1; i >= 0; i--)
    {
        while (!st.empty() && arr[i] >= arr[st.top()])
        {
            st.pop();
        }

        nge[i] = st.empty() ? n : st.top();
        st.push(i);
    }

    return nge;
}

int sumOfSubarrayMax(vector<int> &arr)
{
    int n = arr.size();
    vector<int> pge = findPGE(arr);
    vector<int> nge = findNGE(arr);

    int total = 0;

    for (int i = 0; i < n; i++)
    {
        int left = i - pge[i];
        int right = nge[i] - i;
        total += (left * right * arr[i]);
    }

    return total;
}

int main()
{
    vector<int> arr = {3, 1, 2, 4};
    cout << sumOfSubarrayMax(arr) << endl;

    vector<int> arr2 = {2, 2, 2};
    cout << sumOfSubarrayMax(arr2) << endl;

    return 0;
}