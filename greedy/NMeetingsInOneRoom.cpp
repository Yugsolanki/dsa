#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int nMeetingsInOneRoom(vector<int> &start, vector<int> &end)
{
    vector<pair<int, int>> meetings;
    for (int i = 0; i < start.size(); i++)
    {
        meetings.push_back({end[i], start[i]});
    }
    sort(meetings.begin(), meetings.end());

    int count = 0;
    int freetime = -1;

    for (int i = 0; i < meetings.size(); i++)
    {
        if (meetings[i].second > freetime)
        {
            count++;
            freetime = meetings[i].first;
        }
    }

    return count;
}

int main()
{
    vector<int> start = {1, 3, 0, 5, 8, 5};
    vector<int> end = {2, 4, 6, 7, 9, 9};

    cout << nMeetingsInOneRoom(start, end) << endl; // Output: 4
    return 0;
}