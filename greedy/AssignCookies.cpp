#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int assignCookies(vector<int> &greed, vector<int> &sizes)
{
    sort(greed.begin(), greed.end());
    sort(sizes.begin(), sizes.end());

    int l = 0;
    int r = 0;

    while (r < greed.size() && l < sizes.size())
    {
        if (greed[r] <= sizes[l])
            r++;
        l++;
    }

    return r;
}

int main()
{
    vector<int> greed = {1, 2, 3};
    vector<int> sizes = {1, 1};
    cout << assignCookies(greed, sizes) << endl;
    return 0;
}