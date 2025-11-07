#include <vector>
#include <iostream>
using namespace std;

int maximumPointsCards(vector<int> arr, int k)
{
    int lsum = 0, rsum = 0;

    // calculate lsum
    for (int i = 0; i < k; i++)
    {
        lsum += arr[i];
    }

    // reduce lsum and add to rsum
    int l = k - 1;
    int r = arr.size() - 1;
    int sum = lsum + rsum;

    while ((l >= 0 && r >= 0))
    {
        lsum -= arr[l];
        rsum += arr[r];
        sum = max(sum, lsum + rsum);
        r--;
        l--;
    }

    return sum;
}

int main()
{
    vector<int> arr1 = {1, 2, 3, 4, 5, 6, 1};
    cout << maximumPointsCards(arr1, 3) << endl; // 12

    vector<int> arr2 = {2, 2, 2};
    cout << maximumPointsCards(arr2, 2) << endl; // 4

    vector<int> arr3 = {9, 7, 7, 9, 7, 7, 9};
    cout << maximumPointsCards(arr3, 7) << endl; // 55

    vector<int> arr4 = {1, 79, 80, 1, 1, 1, 200, 1};
    cout << maximumPointsCards(arr4, 3) << endl; // 202
}