#include <iostream>
#include <vector>
using namespace std;

int maximumConsecutiveOnes(vector<int> &arr)
{
    int maxi = 0;
    int count = 0;

    for (int i : arr)
    {
        if (i == 1)
        {
            count++;
            maxi = max(maxi, count);
        }
        else
        {
            count = 0;
        }
    }

    return maxi;
}

int main()
{
    vector<int> arr = {1, 1, 0, 1, 1, 1, 0, 0, 1};
    cout << maximumConsecutiveOnes(arr) << endl;
}