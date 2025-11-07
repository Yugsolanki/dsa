#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int subarrayWithSumK(vector<int> &arr, int k)
{
    unordered_map<int, int> prefixMap;
    prefixMap[0] = 1;

    int sum = 0;
    int count = 0;

    for (int i = 0; i < arr.size(); i++)
    {
        sum += arr[i];
        int temp = sum - k;
        if (prefixMap.find(temp) != prefixMap.end())
        {
            count += prefixMap[temp];
        }
        prefixMap[sum]++;
    }

    return count;
}

int main()
{
    vector<int> arr = {1, 2, 3, -3, 1, 1, 1, 4, 2, -3};
    cout << subarrayWithSumK(arr, 3) << endl;
}