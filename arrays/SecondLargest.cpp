#include <iostream>
using namespace std;

int secondLargest(int arr[], int n)
{
    int largest = arr[0];
    int secLargest = -1;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] > largest)
        {
            secLargest = largest;
            largest = arr[i];
        }
        else if (arr[i] > secLargest && arr[i] < largest)
        {
            secLargest = arr[i];
        }
    }

    return secLargest;
}

int main()
{
    // int arr[] = {12, 35, 1, 10, 34, 1};
    int arr[] = {10, 10, 10};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << secondLargest(arr, n) << endl;
}