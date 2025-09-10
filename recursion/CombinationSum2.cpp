#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


void printArrayOfArray(vector<vector<int>> &arr)
{
    for (auto i : arr)
    {
        for (int j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void combinationSum2(int ind, int target, vector<int> &temp, vector<vector<int>> &ans, vector<int> &arr)
{
    if (target == 0)
    {
        ans.push_back(temp);
        return;
    }

    for (int i = ind; i < arr.size(); i++)
    {
        // check if the element at index i is already considered before
        // in 1,1,1,2,2 if index 0's 1 was already considered then
        // we don't need index 1's 1 to be considered to avoid duplication
        if (i > ind && arr[i] == arr[i - 1])
            continue;
        if (arr[i] > target) // if target is 2 and the current element is 3 we cannot subtract
            break;

        temp.push_back(arr[i]);
        combinationSum2(i + 1, target - arr[i], temp, ans, arr);
        temp.pop_back();
    }
}

int main()
{
    vector<int> arr = {10, 1, 2, 7, 6, 1, 5};
    vector<int> temp;
    vector<vector<int>> ans;
    sort(arr.begin(), arr.end());
    combinationSum2(0, 8, temp, ans, arr);

    printArrayOfArray(ans);

    return 0;
}