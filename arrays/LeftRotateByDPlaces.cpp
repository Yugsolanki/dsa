#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void leftRotateByDPlaces(vector<int> &arr, int d)
{
    int n = arr.size();
    d = d % n;

    int temp[d];
    for (int i = 0; i < d; i++)
    {
        temp[i] = arr[i];
    }

    for (int i = d; i < n; i++)
    {
        arr[i - d] = arr[i];
    }

    for (int i = n - d; i < n; i++)
    {
        arr[i] = temp[i - (n - d)];
    }
}

void leftRotateByDPlacesOptimal(vector<int> &arr, int d)
{
    d = d % arr.size();
    reverse(arr.begin(), arr.begin() + d);
    reverse(arr.begin() + d, arr.end());
    reverse(arr.begin(), arr.end());
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7};

    leftRotateByDPlaces(arr, 3);
    // leftRotateByDPlacesOptimal(arr, 3);

    for (auto i : arr)
    {
        cout << i << " ";
    }
    cout << endl;
}