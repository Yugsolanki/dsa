#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <set>
#include "utilities.h"
using namespace std;

vector<vector<int>> threeSumProblem(vector<int> &arr, int target)
{
    set<vector<int>> res;

    for (int i = 0; i < arr.size() - 1; i++)
    {
        set<int> numSet;

        for (int j = i + 1; j < arr.size(); j++)
        {
            int third = target - (arr[i] + arr[j]);

            // check if third in hashmap
            if (numSet.find(third) != numSet.end())
            {
                vector<int> temp = {arr[i], arr[j], third};
                sort(temp.begin(), temp.end());
                res.insert(temp);
            }

            numSet.insert(arr[j]);
        }
    }

    vector<vector<int>> final(res.begin(), res.end());

    return final;
}
// TC: O(N^2) * O(logM)
// SC: O(N) + O(no. of unique triplets)

vector<vector<int>> threeSumProblemOptimal(vector<int> &arr, int target)
{
    sort(arr.begin(), arr.end());
    vector<vector<int>> ans;

    for (int i = 0; i < arr.size() - 2; i++)
    {
        // if same as previous element then skip
        if (i > 0 && arr[i] == arr[i - 1])
            continue;

        int j = i + 1;
        int k = arr.size() - 1;

        while (j < k)
        {
            int sum = arr[i] + arr[j] + arr[k];

            if (sum < 0)
            {
                j++;
            }
            else if (sum > 0)
            {
                k--;
            }
            else
            {
                ans.push_back({arr[i], arr[j], arr[k]});
                j++;
                k--;

                while (j < k && arr[j] == arr[j - 1])
                    j++;
                while (j < k && arr[k] == arr[k + 1])
                    k--;
            }
        }
    }

    return ans;
}
// TC: O(NlogN) + O(N^2)


int main()
{
    vector<int> arr = {-1, 0, 1, 2, -1, 4};
    vector<vector<int>> res = threeSumProblemOptimal(arr, 0);

    print2DVector(res);
}