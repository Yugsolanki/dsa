#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool jumpGame(vector<int> &arr)
{
    int maxIndex = 0;

    for (int i = 0; i < arr.size(); i++)
    {
        if (maxIndex < i)
            return false;

        maxIndex = max(maxIndex, i + arr[i]);
    }

    return true;
}

int main()
{
    vector<int> arr = {1, 2, 4, 1, 1, 0, 2, 5};
    cout << jumpGame(arr) << endl;

    arr = {1, 2, 3, 1, 1, 0, 2, 5};
    cout << jumpGame(arr) << endl;

    return 0;
}