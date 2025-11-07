#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int maximumSubarraySum(vector<int> &arr)
{
    int sum = 0;
    int maxi = INT_MIN;

    for (int i = 0; i < arr.size(); i++)
    {
        sum += arr[i];
        maxi = max(maxi, sum);

        if (sum < 0)
            sum = 0;
    }

    return maxi > 0 ? maxi : 0;
}

// * Also returns the subarray indices
string maximumSubarraySumIndices(vector<int> &arr)
{
    int sum = 0;
    int maxi = INT_MIN;
    int start = 0, end = 0;

    for (int i = 0; i < arr.size(); i++)
    {
        if (sum == 0)
            start = i;

        sum += arr[i];

        if (sum > maxi)
        {
            maxi = sum;
            end = i;
        }

        if (sum < 0)
            sum = 0;
    }

    return to_string(start) + " " + to_string(end);
}

int main()
{
    vector<int> arr = {-2, -3, 4, -1, -2, 1, 5, -3};
    cout << maximumSubarraySum(arr) << endl;
    cout << maximumSubarraySumIndices(arr) << endl;
}