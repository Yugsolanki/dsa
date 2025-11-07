#include <iostream>
#include <vector>
using namespace std;

vector<int> unionOfSortedArray(vector<int> &arr1, vector<int> &arr2)
{
    int i = 0, j = 0;
    vector<int> temp;

    while (i < arr1.size() && j < arr2.size())
    {
        if (arr1[i] < arr2[j])
        {
            if (temp.size() == 0 || arr1[i] != temp.back())
                temp.push_back(arr1[i]);
            i++;
        }
        else
        {
            if (temp.size() == 0 || arr2[j] != temp.back())
                temp.push_back(arr2[j]);
            j++;
        }
    }

    while (i < arr1.size())
    {
        if (arr1[i] != temp.back())
            temp.push_back(arr1[i]);
        i++;
    }

    while (j < arr2.size())
    {
        if (arr2[j] != temp.back())
            temp.push_back(arr2[j]);
        j++;
    }

    return temp;
}

int main()
{
    vector<int> arr1 = {1, 1, 2, 3, 4, 5};
    vector<int> arr2 = {1, 2, 3, 4, 4, 5, 6};

    vector<int> res = unionOfSortedArray(arr1, arr2);

    for (auto i : res)
    {
        cout << i << " ";
    }
    cout << endl;
}