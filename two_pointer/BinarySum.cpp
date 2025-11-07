#include <iostream>
#include <vector>
using namespace std;

int binarySum(vector<int> arr, int goal)
{
    if (goal < 0)
        return 0;

    int l = 0, r = 0;
    int sum = 0;
    int count = 0;

    while (r < arr.size())
    {
        sum += arr[r];

        while (sum > goal)
        {
            sum -= arr[l];
            l++;
        }

        count += (r - l + 1);
        r++;
    }

    return count;
}

int main()
{
    vector<int> arr1 = {1, 0, 1, 0, 1};
    int k = 2;
    cout << binarySum(arr1, k) - binarySum(arr1, k - 1) << endl;

    vector<int> arr2 = {1, 0, 0, 1, 1, 0};
    k = 2;
    cout << binarySum(arr2, k) - binarySum(arr2, k - 1) << endl;
}