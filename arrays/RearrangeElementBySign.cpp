#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

vector<int> rearrangeElementBySign(vector<int> &arr)
{
    vector<int> pos;
    vector<int> neg;

    for (int i : arr)
    {
        if (i > 0)
            pos.push_back(i);
        else
            neg.push_back(i);
    }

    for (int i = 0; i < arr.size() / 2; i++)
    {
        arr[2 * i] = pos[i];
        arr[2 * i + 1] = neg[i];
    }

    return arr;
}

// TC: O(2N)
// SC: O(N)

vector<int> rearrangeElementBySignOptimal(vector<int> &arr)
{
    vector<int> res(arr.size());
    int pos = 0, neg = 1;

    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] > 0)
        {
            res[pos] = arr[i];
            pos += 2;
        }
        else
        {
            res[neg] = arr[i];
            neg += 2;
        }
    }

    return res;
}

// TC: O(N)
// SP: O(N)

// * Second Variation (Where number of postives = negatives)
vector<int> rearrangeElementBySignVariation(vector<int> &arr)
{
    vector<int> pos;
    vector<int> neg;

    for (int i : arr)
    {
        if (i > 0)
            pos.push_back(i);
        else
            neg.push_back(i);
    }

    if (pos.size() > neg.size())
    {
        for (int i = 0; i < neg.size(); i++)
        {
            arr[2 * i] = pos[i];
            arr[2 * i + 1] = neg[i];
        }

        int index = neg.size() * 2;
        for (int i = neg.size(); i < pos.size(); i++)
        {
            arr[index] = pos[i];
            index++;
        }
    }
    else
    {
        for (int i = 0; i < pos.size(); i++)
        {
            arr[2 * i] = pos[i];
            arr[2 * i + 1] = neg[i];
        }

        int index = pos.size() * 2;
        for (int i = pos.size(); i < neg.size(); i++)
        {
            arr[index] = neg[i];
            index++;
        }
    }

    return arr;
}

int main()
{
    vector<int> arr = {3, 1, -2, -5, 2, -4};

    vector<int> res = rearrangeElementBySignOptimal(arr);

    for (int i : res)
    {
        cout << i << " ";
    }
    cout << endl;

    // -------------------------------
    // -------------------------------

    vector<int> arr2 = {1, 2, -4, -5, 3, 6};

    vector<int> res2 = rearrangeElementBySignVariation(arr2);

    for (int i : res2)
    {
        cout << i << " ";
    }
    cout << endl;
}