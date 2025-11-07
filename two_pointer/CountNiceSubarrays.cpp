#include <iostream>
#include <vector>
using namespace std;

int countNiceSubarrays(vector<int> arr, int k)
{
    if (k < 0)
        return 0;

    int l = 0, r = 0;
    int oddCount = 0;
    int count = 0;

    while (r < arr.size())
    {
        oddCount = arr[r] % 2 != 0 ? oddCount + 1 : oddCount;

        while (oddCount > k)
        {
            if (arr[l] % 2 != 0)
                oddCount--;
            l++;
        }

        count += (r - l + 1);
        r++;
    }

    return count;
}

int main()
{
    vector<int> arr1 = {1, 1, 2, 1, 1};
    int k = 3;
    cout << countNiceSubarrays(arr1, k) - countNiceSubarrays(arr1, k - 1) << endl;

    vector<int> arr2 = {1, 1, 2, 3, 1, 4, 5, 2};
    k = 2;
    cout << countNiceSubarrays(arr2, k) - countNiceSubarrays(arr2, k - 1) << endl;
}