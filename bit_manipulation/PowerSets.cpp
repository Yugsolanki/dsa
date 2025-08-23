#include "utilities.h"

// Print all subsets
vector<vector<int>> PowerSets(vector<int> &arr)
{
    int subsets = 1 << arr.size(); // 2^n
    vector<vector<int>> ans;

    for (int i = 0; i < subsets; i++)
    {
        vector<int> tempList;
        for (int j = 0; j < arr.size(); j++)
        {
            if (i & (1 << j))
                tempList.push_back(arr[j]);
        }
        ans.push_back(tempList);
    }

    return ans;
}

int main()
{
    vector<int> arr = {1, 2, 3};
    vector<vector<int>> res = PowerSets(arr);
    print2DVector(res);
    return 0;
}