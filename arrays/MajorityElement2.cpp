#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Elements appears n/3 times
vector<int> majorityElement2(vector<int> &arr)
{
    int count1 = 0, count2 = 0;
    int item1 = -1, item2 = -1;

    for (int i = 0; i < arr.size(); i++)
    {
        if (count1 == 0 && arr[i] != item2)
        {
            count1++;
            item1 = arr[i];
        }
        else if (count2 == 0 && arr[i] != item1)
        {
            count2++;
            item2 = arr[i];
        }
        else if (item1 == arr[i])
        {
            count1++;
        }
        else if (item2 == arr[i])
        {
            count2++;
        }
        else
        {
            count1--;
            count2--;
        }
    }

    // Now do a manual check
    vector<int> res;
    count1 = 0, count2 = 0;

    for (int i = 0; i < arr.size(); i++)
    {
        count1 = item1 == arr[i] ? count1 + 1 : count1;
        count2 = item2 == arr[i] ? count2 + 1 : count2;
    }

    int min_req = (arr.size() / 3) + 1;
    
    if (count1 >= min_req)
        res.push_back(item1);
    if (count2 >= min_req)
        res.push_back(item2);

    return res;
}

int main()
{
    vector<int> arr = {1, 1, 1, 3, 3, 2, 2, 2};

    vector<int> res = majorityElement2(arr);

    for (int i : res)
    {
        cout << i << " ";
    }
}