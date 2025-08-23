#include <iostream>
#include <stack>
#include <vector>
using namespace std;

vector<int> previousSmallerElement(vector<int> &nums)
{
    int n = nums.size();
    vector<int> ans(n, -1);

    stack<int> st;

    // first element is always the smallest
    st.push(nums[0]);

    for (int i = 1; i < n; i++)
    {
        if (st.top() < nums[i])
        {
            ans[i] = st.top();
            st.push(nums[i]);
        }
        else
        {
            while (!st.empty() && st.top() > nums[i])
            {
                st.pop();
            }
            ans[i] = st.empty() ? -1 : st.top();
            st.push(nums[i]);
        }
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
    vector<int> nums = {5, 7, 9, 6, 7, 4, 5, 1, 3, 7};
    display(nums);
    display(previousSmallerElement(nums));

    cout << "-----------------------------------------------------------------------------------------------------" << endl;

    nums = {4, 12, 5, 3, 1, 2, 5, 3, 1, 2, 4, 6};
    display(nums);
    display(previousSmallerElement(nums));

    return 0;
}