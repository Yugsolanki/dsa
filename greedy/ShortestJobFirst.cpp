#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int shortestJobFirst(vector<int> &arr)
{
    sort(arr.begin(), arr.end());

    int time = 0, waitTime = 0;

    for (int i = 0; i < arr.size(); i++)
    {
        waitTime += time;
        time += arr[i];
    }

    return waitTime / arr.size();
}

int main()
{
    vector<int> arr = {4, 3, 7, 1, 2};
    cout << "Average waiting time: " << shortestJobFirst(arr) << endl;
    return 0;
}