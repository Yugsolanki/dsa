#include <iostream>
#include <vector>
using namespace std;

void printArray(vector<int> &arr)
{
    for (int i : arr)
    {
        cout << i << " ";
    }
    cout << endl;
}

void reverse(int l, int r, vector<int> &arr)
{
    if (l >= r)
        return;

    // swap
    arr[l] = arr[l] ^ arr[r];
    arr[r] = arr[l] ^ arr[r];
    arr[l] = arr[l] ^ arr[r];

    reverse(l + 1, r - 1, arr);
}

void reverse2(int i, vector<int> &arr)
{
    int n = arr.size();
    if (i >= n / 2)
        return;

    // swap
    arr[i] = arr[i] ^ arr[n - i - 1];
    arr[n - i - 1] = arr[i] ^ arr[n - i - 1];
    arr[i] = arr[i] ^ arr[n - i - 1];

    reverse2(i + 1, arr);
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5};
    reverse(0, arr.size() - 1, arr);
    printArray(arr);

    vector<int> arr2 = {1, 2, 3, 4, 5};
    reverse2(0, arr2);
    printArray(arr2);
}