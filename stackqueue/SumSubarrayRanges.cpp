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

int sumOfSubarrayMin(vector<int> &arr)
{
    vector<int> pse = findPSE(arr);
    vector<int> nse = findNSE(arr);

    int total = 0;
    int n = arr.size();

    for (int i = 0; i < n; i++)
    {
        int left = i - pse[i];
        int right = nse[i] - i;
        total += (right * left * arr[i]);
    }

    return total;
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
        total += left * right * arr[i];
    }

    return total;
}

int main()
{
    vector<int> arr = {1, 4, 3, 2};

    int sumMin = sumOfSubarrayMin(arr);
    int sumMax = sumOfSubarrayMax(arr);

    int result = sumMax - sumMin;
    cout << result << endl;

    return 0;
}