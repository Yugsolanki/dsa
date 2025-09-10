#include <vector>
#include <iostream>
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

void findSubset2(int ind, vector<int> &temp, vector<vector<int>> &ans, vector<int> &arr)
{
    ans.push_back(temp);

    for (int i = ind; i < arr.size(); i++)
    {
        // Check if previous element was same as the current element
        if (i != ind && arr[i] == arr[i - 1])
            continue;

        temp.push_back(arr[i]);
        findSubset2(i + 1, temp, ans, arr);
        temp.pop_back();
    }
}

int main()
{
    vector<int> arr = {1, 2, 2, 2, 3, 3};

    sort(arr.begin(), arr.end());

    vector<int> temp;
    vector<vector<int>> ans;

    findSubset2(0, temp, ans, arr);

    printArrayOfArray(ans);

    return 0;
}