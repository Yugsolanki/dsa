#include <iostream>
using namespace std;

void leftRotateByOnePlace(int arr[], int n)
{
    int temp = arr[0];

    for (int i = 1; i < n; i++)
    {
        arr[i - 1] = arr[i];
    }

    arr[n - 1] = temp;
}

int main()
{
    int arr[] = {1, 2, 3, 5, 6};
    // int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    leftRotateByOnePlace(arr, n);

    for (auto i : arr)
    {
        cout << i << " ";
    }
    cout << endl;
}