#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

// This version can also return indexes if wanted
bool twoSumProblem(vector<int> &arr, int target)
{
    unordered_map<int, int> map;

    for (int i = 0; i < arr.size(); i++)
    {
        if (map.find(target - arr[i]) != map.end())
        {
            return true;
        }
        map[arr[i]] = i;
    }

    return false;
}

// this version cannot return indexes
int twoSumProblemOptimal(vector<int> &arr, int target)
{
    int left = 0, right = arr.size() - 1;
    // int sum = 0;

    sort(arr.begin(), arr.end());

    while (left < right)
    {
        int sum = arr[left] + arr[right];

        if (sum < target)
            left++;
        else if (sum > target)
            right--;
        else
            return true;
    }

    return false;
}

int main()
{
    vector<int> arr = {2, 6, 5, 8, 11};
    cout << twoSumProblemOptimal(arr, 14) << endl;
}