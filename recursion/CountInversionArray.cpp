#include <iostream>
#include <vector>
using namespace std;

int inversionCount(vector<int> &arr)
{
    int count = 0;

    for (int i = 0; i < arr.size() - 1; i++)
    {
        for (int j = i + 1; j < arr.size(); j++)
        {
            if (arr[i] > arr[j])
                count++;
        }
    }

    return count;
}

// Time Complexity : O(n^2)

// * Another Approach

// int count = 0;

int inversionCountOptimizedUtil(int low, int mid, int high, vector<int> &arr)
{
    int count = 0;

    int left = low;
    int right = mid + 1;
    vector<int> temp;

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
            count += (mid - left + 1);
            right++;
        }
    }

    while (left <= mid)
    {
        temp.push_back(arr[left]);
        left++;
    }

    while (right <= high)
    {
        temp.push_back(arr[right]);
        right++;
    }

    for (int i = low; i <= high; i++)
    {
        arr[i] = temp[i - low];
    }

    return count;
}

int inversionCountOptimized(int low, int high, vector<int> &arr)
{
    int count = 0;

    if (low >= high)
        return count;

    int mid = (low + high) / 2;

    count += inversionCountOptimized(low, mid, arr);
    count += inversionCountOptimized(mid + 1, high, arr);
    count += inversionCountOptimizedUtil(low, mid, high, arr);

    return count;
}

int main()
{
    vector<int> arr = {2, 4, 1, 3, 5};
    cout << inversionCount(arr) << endl;

    // inversionCountOptimized(0, arr.size() - 1, arr);
    cout << inversionCountOptimized(0, arr.size() - 1, arr) << endl;

    return 0;
}