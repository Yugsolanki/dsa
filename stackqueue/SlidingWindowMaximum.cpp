#include <iostream>
#include <vector>
#include <deque>
using namespace std;

vector<int> slidingWindowMaximum(vector<int> &arr, int k)
{
    int n = arr.size();
    deque<int> dq;
    vector<int> res;

    for (int i = 0; i < n; i++)
    {
        if (!dq.empty() && dq.front() <= (i - k))
        {
            dq.pop_front();
        }

        while (!dq.empty() && arr[dq.back()] <= arr[i])
        {
            dq.pop_back();
        }
        dq.push_back(i);

        if (i >= k - 1)
        {
            res.push_back(arr[dq.front()]);
        }
    }

    return res;
}

int main()
{
    vector<int> arr = {1, 3, -1, -3, 5, 3, 7, 1, 6};
    vector<int> res = slidingWindowMaximum(arr, 3);

    for (int i : res)
    {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}