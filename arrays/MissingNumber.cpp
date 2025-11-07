#include <iostream>
#include <vector>
using namespace std;

int intersectionOfSortedArray(vector<int> &arr)
{
    int n = arr.size();
    int total = (n * (n + 1)) / 2;

    int sum = 0;
    for (int i : arr)
    {
        sum += i;
    }

    return total - sum;
}

int missingNumberOptimal(vector<int> &arr)
{
    int result = 0;
    int n = arr.size();

    for (int i = 0; i < n; i++)
    {
        result = result ^ arr[i] ^ i;
    }
    result = result ^ n; // XOR with the last expected number
    return result;
} 

int main()
{
    vector<int> arr = {1, 0, 3, 4};
    cout << missingNumberOptimal(arr) << endl;
}