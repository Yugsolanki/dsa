#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int MinimumPlatformsNeeded(vector<int> &arr, vector<int> &dep)
{
    sort(arr.begin(), arr.end());
    sort(dep.begin(), dep.end());

    int maxPlatformNeeded = 1;
    int platformNeeded = 1;
    int i = 1, j = 0;

    while (i < arr.size() && j < dep.size())
    {
        if (arr[i] <= dep[j])
        {
            platformNeeded++;
            i++;
        }
        else
        {
            platformNeeded--;
            j++;
        }

        maxPlatformNeeded = max(maxPlatformNeeded, platformNeeded);
    }

    return maxPlatformNeeded;
}

int main()
{
    vector<int> arr = {900, 945, 955, 1100, 1500, 1800};
    vector<int> dep = {920, 1200, 1130, 1150, 1900, 2000};

    cout << MinimumPlatformsNeeded(arr, dep) << endl;

    return 0;
}