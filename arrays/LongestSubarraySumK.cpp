#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// * Works with positives and negatives in array (not when array has 0 and only positives, this is very slow for that)
int longestSubarraySumK(vector<int> &arr, int k)
{
    unordered_map<int, int> sumMap;
    int len = 0;
    int sum = 0;

    for (int i = 0; i < arr.size(); i++)
    {
        sum += arr[i];
        if (sum == k)
        {
            len = max(len, i + 1);
        }

        int rem = sum - k;
        if (sumMap.find(rem) != sumMap.end())
        {
            len = max(len, i - sumMap[rem]);
        }

        // Store the first occurrence of the sum
        // This always overwrites the previous occurrence of sum. However, for the longest subarray, we need to store the first occurrence of each prefix sum, because it will give the longest possible subarray when encountered again.
        // for cases like [1,2,3,0,0,0,2] and K = 5;
        if (sumMap.find(sum) == sumMap.end())
        {
            sumMap[sum] = i;
        }
    }

    return len;
}

// Most optimal (but dosn't work with negative numbers)
int longestSubarraySumKOptimal(vector<int> &arr, int k)
{
    int left = 0, right = 0;
    int maxi = 0;
    int sum = 0;

    while (right < arr.size())
    {
        sum += arr[right];

        while (sum > k && left <= right)
        {
            sum -= arr[left];
            left++;
        }

        if (sum == k)
        {
            maxi = max(maxi, right - left + 1);
        }

        right++;
    }

    return maxi;
}

int main()
{
    vector<int> arr = {1, 2, 3, 1, 1, 1, 1, 4, 2, 3};
    cout << longestSubarraySumKOptimal(arr, 3) << endl;
}