#include <iostream>
#include <vector>
using namespace std;

int jumpGame2(vector<int> &arr)
{
    int jumps = 0;
    int l = 0, r = 0;

    while (r < arr.size())
    {
        int farthest = 0;

        for (int i = l; i <= r; i++)
        {
            farthest = max(farthest, i + arr[i]);
        }
        l = r + 1;
        r = farthest;
        jumps++;
    }

    return jumps;
}

int main()
{
    vector<int> arr = {7, 0, 9, 6, 9, 6, 1, 7, 9, 0, 1, 2, 9, 0, 3};
    cout << jumpGame2(arr) << endl;
    return 0;
}