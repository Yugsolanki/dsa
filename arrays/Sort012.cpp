#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// * Approach 1:
void sortZeroOneTwo1(vector<int> &arr)
{
    sort(arr.begin(), arr.end());
}

// * Approach 2:
void sortZeroOneTwo2(vector<int> &arr)
{
    int zeros = 0, ones = 0, twos = 0;

    for (int i : arr)
    {
        if (i == 0)
            zeros++;
        else if (i == 1)
            ones++;
        else
            twos++;
    }

    for (int i = 0; i < zeros; i++)
    {
        arr[i] = 0;
    }

    for (int i = zeros; i < (zeros + ones); i++)
    {
        arr[i] = 1;
    }

    for (int i = (zeros + ones); i < arr.size(); i++)
    {
        arr[i] = 2;
    }
}

// * Approach 3:
void sortZeroOneTwo3(vector<int> &arr)
{
    int low = 0, mid = 0, high = arr.size() - 1;

    while (mid <= high)
    {
        if (arr[mid] == 0)
        {
            swap(arr[low], arr[mid]);
            low++;
            mid++;
        }
        else if (arr[mid] == 1)
        {
            mid++;
        }
        else
        {
            swap(arr[mid], arr[high]);
            high--;
        }
    }
}

int main()
{
    vector<int> arr = {0, 1, 2, 0, 1, 2, 1, 2, 0, 0, 0, 1};

    sortZeroOneTwo3(arr);

    for (int i : arr)
    {
        cout << i << " ";
    }
    cout << endl;
}