#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int nonOverlappingIntervals(vector<vector<int>> &intervals)
{
    sort(intervals.begin(), intervals.end(), [](auto &a, auto &b)
         {
            // a[1] is the end time of first interval
            // b[1] is the end time of second interval
            // Returns true if a should come before b in sorted order
            return a[1] < b[1]; });

    int count = 0;
    int currentEnd = INT_MIN;

    for (int i = 0; i < intervals.size(); i++)
    {
        if (intervals[i][0] >= currentEnd)
        {
            count++;
            currentEnd = intervals[i][1];
        }
    }

    return intervals.size() - count;
}

int main()
{
    vector<vector<int>> intervals = {
        {1, 2},
        {2, 3},
        {3, 4},
        {1, 3},
        {5, 6},
        {5, 7}};
    cout << nonOverlappingIntervals(intervals) << endl;
    return 0;
}