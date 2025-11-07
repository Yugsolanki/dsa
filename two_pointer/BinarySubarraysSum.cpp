#include <vector>
#include <iostream>
using namespace std;

int binarySubarraysSum(vector<int> &arr, int goal)
{
    int l = 0, r = 0;
    int runningSum = 0;
    int count = 0;

    while (l <= r)
    {
        if (r < arr.size())
        {
            runningSum += arr[r];
            r++;
        }

        while (runningSum > goal)
        {
            runningSum -= arr[l];
            l++;
        }

        if (runningSum == goal)
        {
            count++;
        }
    }

    return count;
}

int main()
{
    vector<int> arr = {1, 0, 1, 0, 1};
    cout << binarySubarraysSum(arr, 2) << endl;

    return 0;
}