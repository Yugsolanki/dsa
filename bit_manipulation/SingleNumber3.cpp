#include <iostream>
#include <vector>
using namespace std;

vector<int> singleNumber(vector<int> &arr)
{
    int xorAll = 0;
    for (int i : arr)
    {
        xorAll ^= i;
    }

    int rightMost = (xorAll & (xorAll - 1)) ^ xorAll;

    int bucket1 = 0;
    int bucket2 = 0;

    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] & rightMost)
        {
            bucket1 = bucket1 ^ arr[i];
        }
        else
        {
            bucket2 = bucket2 ^ arr[i];
        }
    }

    return {bucket1, bucket2};
}

int main()
{
    vector<int> arr = {2, 4, 2, 6, 3, 7, 7, 3};
    vector<int> res = singleNumber(arr);

    for (int i : res)
    {
        cout << i << " " << endl;
    }
    cout << endl;

    return 0;
}