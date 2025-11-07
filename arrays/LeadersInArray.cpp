#include <iostream>
#include <vector>
using namespace std;

vector<int> leadersInArray(vector<int> &arr)
{
    vector<int> leaders;

    for (int i = 0; i < arr.size(); i++)
    {
        bool isLeader = true;

        for (int j = i + 1; j < arr.size() && isLeader == true; j++)
        {
            if (arr[j] > arr[i])
                isLeader = false;
        }

        if (isLeader)
            leaders.push_back(arr[i]);
    }

    return leaders;
}
// Time Complexity: O(n^2)
// Space Complexity: O(n)

vector<int> leadersInArrayOptimal(vector<int> &arr)
{
    vector<int> leaders;
    int maxi = INT_MIN;

    for (int i = arr.size() - 1; i >= 0; i--)
    {
        if (arr[i] > maxi)
        {
            maxi = arr[i];
            leaders.push_back(arr[i]);
        }
    }

    return leaders;
}

int main()
{
    vector<int> arr = {10, 22, 12, 3, 0, 6};
    vector<int> res = leadersInArrayOptimal(arr);

    for (int i : res)
    {
        cout << i << " ";
    }
    cout << endl;
}