#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void moveZerosToEnd(vector<int> &arr)
{
    int left = 0, right = 0;

    while (right < arr.size())
    {
        if (arr[right] != 0)
        {
            arr[left] = arr[right];
            left++;
        }
        right++;
    }

    while (left < arr.size())
    {
        arr[left] = 0;
        left++;
    }
}

int main()
{
    vector<int> arr = {1, 0, 2, 0, 0, 2, 3, 4, 0, 6, 0, 0};

    moveZerosToEnd(arr);

    for (auto i : arr)
    {
        cout << i << " ";
    }
    cout << endl;
}