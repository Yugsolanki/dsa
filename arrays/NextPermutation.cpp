#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void nextPermutation(vector<int> &arr)
{
    int n = arr.size();

    int ind = -1;

    // Find the dip
    for (int i = n - 2; i >= 0; i--)
    {
        if (arr[i] < arr[i + 1])
        {
            ind = i;
            break;
        }
    }

    // if there is no dip
    if (ind == -1)
    {
        reverse(arr.begin(), arr.end());
        return;
    }

    // find the smallest element from all the large element of ind
    for (int i = n - 1; i >= 0; i--)
    {
        if (arr[i] > arr[ind])
        {
            swap(arr[i], arr[ind]);
            break;
        }
    }

    // reverse the rest of the array after ind
    reverse(arr.begin() + ind + 1, arr.end());
}

int main()
{
    vector<int> arr = {2,1,5,4,3,0,0};

    nextPermutation(arr);
    
    for (int i : arr)
    {
        cout << i << " ";
    }
    cout << endl;
}