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

void permutation(vector<int> &temp, vector<bool> map, vector<vector<int>> &ans, vector<int> &arr)
{
    if (temp.size() == arr.size())
    {
        ans.push_back(temp);
        return;
    }

    for (int i = 0; i < arr.size(); i++)
    {
        if (map[i] == true)
            continue;

        temp.push_back(arr[i]);
        map[i] = true;

        permutation(temp, map, ans, arr);

        temp.pop_back();
        map[i] = false;
    }
}

// Time Complexity : O(n! * n)
// Space Complexity : O(2n)

// Another Approach
void swap(int i, int j, vector<int> &arr)
{
    int t = arr[i];
    arr[i] = arr[j];
    arr[j] = t;
}

void permutation_another(int ind, vector<vector<int>> &ans, vector<int> &arr)
{
    if (ind >= arr.size())
    {
        ans.push_back(arr);
        return;
    }

    for (int i = ind; i < arr.size(); i++)
    {
        swap(i, ind, arr);
        permutation_another(ind + 1, ans, arr);
        swap(i, ind, arr);
    }
}

int main()
{
    vector<int> arr = {1, 2, 3};

    vector<int> temp;
    vector<bool> map(arr.size(), false);
    vector<vector<int>> ans;

    permutation_another(0, ans, arr);

    printArrayOfArray(ans);

    return 0;
}