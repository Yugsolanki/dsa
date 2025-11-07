#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <set>
#include "utilities.h"
using namespace std;

vector<vector<int>> fourSumProblem(vector<int> &arr, int target)
{
    if (arr.size() < 4)
    {
        return {};
    }

    set<vector<int>> res;

    for (int i = 0; i < arr.size() - 2; i++)
    {
        for (int j = i + 1; j < arr.size() - 1; j++)
        {
            set<int> numSet;

            for (int k = j + 1; k < arr.size(); k++)
            {
                long long sum = arr[i] + arr[j];
                sum += arr[k];             // doing all at one place causes interger overflow on leetcode
                int fourth = target - sum; // same logic: dont do all at one place to save lines of code

                if (numSet.find(fourth) != numSet.end() && sum + fourth == target)
                {
                    vector<int> temp = {arr[i], arr[j], arr[k], fourth};
                    sort(temp.begin(), temp.end());
                    res.insert(temp);
                }
                numSet.insert(arr[k]);
            }
        }
    }

    vector<vector<int>> ans(res.begin(), res.end());
    return ans;
}
// TC: O(N^3) * O(logM)
// SC: O(N) + O(no. of unique triplets * 2)

vector<vector<int>> fourSumProblemOptimal(vector<int> &arr, int target)
{
    sort(arr.begin(), arr.end());
    vector<vector<int>> ans;

    for (int i = 0; i < arr.size() - 3; i++)
    {
        // if same as previous element then skip
        if (i > 0 && arr[i] == arr[i - 1])
            continue;

        for (int j = i + 1; j < arr.size() - 2; j++)
        {
            // if same as previous element then skip
            if (j > i + 1 && arr[j] == arr[j - 1])
                continue;

            int k = j + 1;
            int l = arr.size() - 1;

            while (k < l)
            {
                long long sum = arr[i] + arr[j] + arr[k] + arr[l];

                if (sum < target)
                    k++;
                else if (sum > target)
                    l--;
                else
                {
                    ans.push_back({arr[i], arr[j], arr[k], arr[l]});
                    k++;
                    l--;

                    while (k < l && arr[k] == arr[k - 1])
                        k++;
                    while (k < l && arr[l] == arr[l + 1])
                        l--;
                }
            }
        }
    }

    return ans;
}
// TC: O(NlogN) + O(N^2)

int main()
{
    vector<int> arr = {1, 2, -1, -2, 2, 0, -1};
    vector<vector<int>> res = fourSumProblemOptimal(arr, 0);

    print2DVector(res);
}