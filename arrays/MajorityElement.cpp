#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int majorityElement(vector<int> &arr)
{
    int count = 0;
    int element = 0;

    for (int i = 0; i < arr.size(); i++)
    {
        if (count == 0)
        {
            count++;
            element = arr[i];
        }
        else if (arr[i] == element)
            count++;
        else
            count--;
    }

    if (count > 0)
        return element;

    return -1;
}

int main()
{
    vector<int> arr = {2, 2, 3, 3, 1, 2, 2};
    cout << majorityElement(arr) << endl;
}