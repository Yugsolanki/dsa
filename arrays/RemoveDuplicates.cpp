#include <iostream>
using namespace std;

int removeDuplicates(int arr[], int n)
{
    int prev = 0;

    for (int i = 1; i < n; i++)
    {
        if (arr[i] != arr[prev])
        {
            prev++;
            arr[prev] = arr[i];
        }
    }

    return prev + 1;
}

int main()
{
    int arr[] = {1, 2, 2, 3, 3, 5, 6};
    // int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << removeDuplicates(arr, n) << endl;
}