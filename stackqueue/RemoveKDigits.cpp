#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <algorithm>
using namespace std;

string removeKDigits(string arr, int k)
{
    int n = arr.size();
    stack<int> st;

    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && k > 0 && (st.top() - '0') > (arr[i] - '0'))
        {
            st.pop();
            k--;
        }
        st.push(arr[i]);
    }

    // If removed less elements than desired
    // than remove some elements from top to complete quouta
    while (k > 0)
    {
        st.pop();
        k--;
    }

    // if we poped everything then return 0 mate
    if (st.empty())
        return "0";

    // convert stack to string
    string res = "";
    while (!st.empty())
    {
        res += st.top();
        st.pop();
    }

    // string might be 00100 so we need to string initial zeros
    while (res.size() != 0 && res.back() == '0')
    {
        res.pop_back();
    }

    // reverse the string
    reverse(res.begin(), res.end());

    return res.size() == 0 ? "0" : res;
}

int main()
{
    string str = "1432219";
    cout << removeKDigits(str, 3) << endl;
    return 0;
}