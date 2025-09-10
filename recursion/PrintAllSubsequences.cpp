#include <iostream>
#include <vector>
using namespace std;

void printArray(vector<int> &arr)
{
    for (int i : arr)
    {
        cout << i << " ";
    }
    cout << endl;
}

void printSubsequences(int i, vector<int> &temp, vector<int> &arr)
{
    if (i >= arr.size())
    {
        printArray(temp);
        return;
    }
    // Case where element is present
    temp.push_back(arr[i]);
    printSubsequences(i + 1, temp, arr);

    // Case where element is absent
    temp.pop_back();
    printSubsequences(i + 1, temp, arr);
}

int main()
{
    vector<int> arr = {3, 1, 2};
    vector<int> temp;
    printSubsequences(0, temp, arr);
}