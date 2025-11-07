#include <iostream>
#include <vector>
using namespace std;

int longestOnes(vector<int> &nums, int k)
{
    int l = 0;
    int zeros = 0;
    int ones = 0;

    for (int r = 0; r < nums.size(); r++)
    {
        if (nums[r] == 0)
            zeros++;

        while (zeros > k)
        {
            if (nums[l] == 0)
                zeros--;
            l++;
        }

        ones = max(ones, r - l + 1);
    }

    return ones;
}

int main()
{
    vector<int> arr = {1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0};
    cout << longestOnes(arr, 2) << endl;
}