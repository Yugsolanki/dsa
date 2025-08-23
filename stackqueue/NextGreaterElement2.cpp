#include <iostream>
#include <stack>
#include <vector>
using namespace std;

vector<int> nextGreaterElement(vector<int> &nums)
{
    int n = nums.size();
    vector<int> ans(n, -1);

    stack<int> st;

    for (int i = 2 * n - 1; i >= 0; i--)
    {
        // handling the double array part
        while (!st.empty() && nums[i % n] >= st.top())
        {
            st.pop();
        }

        // dealing with normal array now
        if (i < n)
        {
            ans[i] = st.empty() ? -1 : st.top();
        }

        st.push(nums[i % n]);
    }

    return ans;
}

void display(vector<int> nums)
{
    for (int i : nums)
    {
        cout << i << "\t";
    }
    cout << endl;
}

int main()
{
    vector<int> nums = {2, 10, 12, 1, 11};
    display(nums);
    display(nextGreaterElement(nums));

    cout << "-----------------------------------------------------------------------------------------------" << endl;

    nums = {4, 12, 5, 3, 1, 2, 5, 3, 1, 2, 4, 6};
    display(nums);
    display(nextGreaterElement(nums));

    return 0;
}