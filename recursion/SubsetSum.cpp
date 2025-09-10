#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void printArray(vector<int> &arr)
{
    for (int i : arr)
    {
        cout << i << " ";
    }
    cout << endl;
}

void subsetSum(int i, int sum, vector<int> &ans, vector<int> &arr)
{
    if (i >= arr.size())
    {
        ans.push_back(sum);
        return;
    }

    subsetSum(i + 1, sum + arr[i], ans, arr);
    subsetSum(i + 1, sum, ans, arr);
}

int main()
{
    vector<int> arr = {3, 1, 2};
    vector<int> ans;

    subsetSum(0, 0, ans, arr);

    // sort it
    sort(ans.begin(), ans.end());

    printArray(ans);

    return 0;
}