#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Each number appears thrice
int singleNumber(vector<int> &arr)
{
    int result = 0;
    for (int i = 0; i < 31; i++)
    {
        int count = 0;
        for (int j = 0; j < arr.size(); j++)
        {
            if (arr[j] & (1 << i))
                count++;
        }

        if (count % 3 == 1)
            result = result | (1 << i); // set that bit
    }

    return result;
}

// Time Complexity : O(n * 32)
// Space Complexity : O(1)

int singleNumber2(vector<int> &arr)
{
    sort(arr.begin(), arr.end());

    for (int i = 1; i < arr.size(); i += 3)
    {
        if (arr[i] != arr[i - 1])
            return arr[i - 1];
    }

    return arr[arr.size() - 1];
}

// Time Complexity : O(n * log n + n/3)
// Space Complexity : O(1)

int singleNumber3(vector<int> &arr)
{
    int ones = 0, twos = 0;

    for (int i = 0; i < arr.size(); i++)
    {
        ones = (arr[i] ^ ones) & (~twos);
        twos = (arr[i] ^ twos) & (~ones);
    }
    return ones;
}

// Time Complexity : O(n)
// Space Complexity : O(1)

int main()
{
    vector<int> arr = {2, 2, 1, 3, 3, 2, 3};
    cout << singleNumber3(arr) << endl;
    return 0;
}