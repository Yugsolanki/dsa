#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int subarrayWithXOR_K(vector<int> &arr, int k)
{
    unordered_map<int, int> xorMap;
    xorMap[0] = 1;

    int count = 0;
    int preXor = 0;

    for (int i = 0; i < arr.size(); i++)
    {
        preXor = preXor ^ arr[i];

        if (xorMap.find(k ^ preXor) != xorMap.end())
        {
            count += xorMap[k ^ preXor];
        }

        xorMap[preXor]++;
    }

    return count;
}

int main()
{
    vector<int> arr = {4,2,2,6,4};
    cout << subarrayWithXOR_K(arr, 6) << endl;
}