#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int tappingWater(vector<int> arr)
{
    int n = arr.size();
    int totalWater = 0;

    vector<int> prefixMax(n);
    vector<int> suffixMax(n);

    // Fill prefixMax:
    prefixMax[0] = arr[0];
    for (int i = 1; i < n; i++)
    {
        prefixMax[i] = max(prefixMax[i - 1], arr[i]);
    }

    // Fill suffixMax:
    suffixMax[n - 1] = arr[n - 1];
    for (int i = n - 2; i >= 0; i--)
    {
        suffixMax[i] = max(suffixMax[i + 1], arr[i]);
    }

    // Calculating total water caught
    // Formula: total += min(leftMax, rightMax) - currentHeight
    for (int i = 0; i < n; i++)
    {
        int leftMax = prefixMax[i];
        int rightMax = suffixMax[i];

        if (arr[i] < leftMax && arr[i] < rightMax)
        {
            totalWater += min(leftMax, rightMax) - arr[i];
        }
    }

    return totalWater;
}

// Time Complexity : O(3N)
// Space Complexity : O(2N)

int tappingWaterOptimized(vector<int> &arr)
{
    int n = arr.size();
    int totalWater = 0;

    int left = 0, right = n - 1;

    int leftMax = 0, rightMax = 0;

    while (left < right)
    {

        // if left point to 0 and right point to 1 then maybe water can be stored
        // if leftMax is greater than 0 then
        if (arr[left] < arr[right])
        {
            if (arr[left] >= leftMax)
                leftMax = arr[left];
            else
                totalWater += leftMax == 0 ? 0 : leftMax - arr[left];
            left++;
        }

        // vice versa mate
        else
        {
            if (arr[right] >= rightMax)
                rightMax = arr[right];
            else
                totalWater += rightMax == 0 ? 0 : rightMax - arr[right];
            right--;
        }
    }

    return totalWater;
}

int main()
{
    vector<int> arr = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    cout << tappingWaterOptimized(arr) << endl;

    return 0;
}