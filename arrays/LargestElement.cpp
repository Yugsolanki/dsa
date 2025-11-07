#include <iostream>
#include <vector>
using namespace std;

int largestElement(int arr[], int n)
{
    int largest = 0;

    for (int i = 0; i < n; i++)
    {
        largest = arr[i] > largest ? arr[i] : largest;
    }

    return largest;
}

int main()
{
    int arr[] = {1, 3, 5, 2, 3, 5, 7, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << largestElement(arr, n) << endl;
}