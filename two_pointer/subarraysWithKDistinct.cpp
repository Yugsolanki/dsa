#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int subarraysWithKDistinct(vector<int> arr, int k)
{
    if (k < 0)
        return 0;

    int l = 0, r = 0;
    int count = 0;
    unordered_map<int, int> mpp;

    while (r < arr.size())
    {
        mpp[arr[r]]++;

        while (mpp.size() > k)
        {
            mpp[arr[l]]--;

            if (mpp[arr[l]] == 0)
                mpp.erase(arr[l]);

            l++;
        }

        count += (r - l + 1);
        r++;
    }

    return count;
}

int main()
{
    vector<int> arr1 = {1, 2, 1, 3, 4};
    int k = 3;
    cout << subarraysWithKDistinct(arr1, k) - subarraysWithKDistinct(arr1, k - 1) << endl;

    // vector<int> arr2 = {1, 1, 2, 3, 1, 4, 5, 2};
    // k = 2;
    // cout << subarraysWithKDistinct(arr2, k) - subarraysWithKDistinct(arr2, k - 1) << endl;
}