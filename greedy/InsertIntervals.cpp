#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> insertIntervals(vector<vector<int>> &intervals, vector<int> newInterval)
{
    vector<vector<int>> result;
    int startTime = 0, endTime = 0;

    int i = 0;

    // add all intervals that end before newInterval starts
    while (i < intervals.size() && intervals[i][1] < newInterval[0])
    {
        result.push_back(intervals[i]);
        i++;
    }

    // merge all overlapping intervals to one considering newInterval
    while (i < intervals.size() && intervals[i][0] <= newInterval[1])
    {
        newInterval[0] = min(newInterval[0], intervals[i][0]);
        newInterval[1] = max(newInterval[1], intervals[i][1]);
        i++;
    }

    // add the union of intervals we got
    result.push_back(newInterval);

    // add all the rest
    while (i < intervals.size())
    {
        result.push_back(intervals[i]);
        i++;
    }

    return result;
}

int main()
{
    vector<vector<int>> intervals = {
        {1, 2},
        {3, 4},
        {5, 7},
        {8, 10},
        {12, 16}};
    vector<int> newInterval = {5, 8};

    vector<vector<int>> mergedIntervals = insertIntervals(intervals, newInterval);

    for (const auto &interval : mergedIntervals)
    {
        cout << "[" << interval[0] << ", " << interval[1] << "] ";
    }
    cout << endl;

    return 0;
}