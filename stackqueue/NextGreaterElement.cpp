#include <iostream>
#include <stack>
#include <vector>
using namespace std;

vector<int> nextGreaterElement(vector<int> &nums)
{
    int n = nums.size();
    vector<int> ans(n, -1);

    stack<int> st;

    // For the last element
    st.push(nums[n - 1]);
    // Since all the elements are already pre-assigned to -1 no need to add it to ans

    for (int i = n - 2; i >= 0; i--)
    {
        // If top elements is the next greater element
        if (st.top() > nums[i])
        {
            ans[i] = st.top();
            st.push(nums[i]);
        }

        else
        {
            // pop until you reach bigger element then current one in stack or empty
            while (!st.empty() && st.top() <= nums[i])
            {
                st.pop();
            }
            // if empty meaning all element in stack are smaller than current one
            // so push the current one in and return -1
            if (st.empty())
            {
                st.push(nums[i]);
            }
            // if we find greater element in stack after poping smaller ones
            // then we push it to ans and add current to stack
            else
            {
                ans[i] = st.top();
                st.push(nums[i]);
            }
        }
    }

    return ans;
}

void display(vector<int> nums)
{
    for (int i : nums)
    {
        cout << i << " ";
    }
    cout << endl;
}

int main()
{
    vector<int> nums = {1, 11, 2, 10};
    display(nextGreaterElement(nums));

    nums = {4, 12, 5, 3, 1, 2, 5, 3, 1, 2, 4, 6};
    display(nextGreaterElement(nums));

    return 0;
}