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

void merge(int low, int mid, int high, vector<int> &arr)
{
    int left = low;
    int right = mid + 1;
    vector<int> temp;

    // Merge the two halves into a temporary array
    // Compare elements from both halves and insert the smaller one into the temp array
    while (left <= mid && right <= high)
    {
        if (arr[left] <= arr[right])
        {
            temp.push_back(arr[left]);
            left++;
        }
        else
        {
            temp.push_back(arr[right]);
            right++;
        }
    }

    // If there are remaining elements in the left half, add them to temp
    while (left <= mid)
    {
        temp.push_back(arr[left]);
        left++;
    }

    // If there are remaining elements in the right half, add them to temp
    while (right <= high)
    {
        temp.push_back(arr[right]);
        right++;
    }

    // Copy the sorted elements from temp back to the original array
    for (int i = low; i <= high; i++)
    {
        arr[i] = temp[i - low];
    }
}

void mergeSort(int low, int high, vector<int> &arr)
{
    if (low >= high)
        return;

    int mid = (low + high) / 2;
    mergeSort(low, mid, arr);
    mergeSort(mid + 1, high, arr);
    merge(low, mid, high, arr);
}

int main()
{
    vector<int> arr = {2, 4, 5, 2, 5, 6, 3, 7, 8, 4, 6, 3, 2};
    mergeSort(0, arr.size() - 1, arr);
    printArray(arr);
    return 0;
}