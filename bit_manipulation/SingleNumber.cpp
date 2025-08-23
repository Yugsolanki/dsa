#include <iostream>
#include <vector>
using namespace std;

int singleNumber(vector<int> &arr)
{
    int res = 0;
    for (int i : arr)
    {
        res = res ^ i;
    }
    return res;
}

int main()
{
    vector<int> arr = {4, 1, 2, 1, 2};
    cout << singleNumber(arr) << endl;
    return 0;
}