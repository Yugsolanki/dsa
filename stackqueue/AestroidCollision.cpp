#include <iostream>
#include <list>
#include <vector>
using namespace std;

void aestroidCollision(vector<int> arr)
{
    vector<int> ans;

    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] > 0)
        {
            ans.push_back(arr[i]);
        }
        else
        {
            while (!ans.empty() && ans.back() > 0 && ans.back() < abs(arr[i]))
            {
                ans.pop_back();
            }

            if (!ans.empty() && ans.back() == abs(arr[i]))
                ans.pop_back();
            else if (ans.empty() || ans.back() < 0)
                ans.push_back(arr[i]);
        }
    }

    for (int i : ans)
    {
        cout << i << " ";
    }
    cout << endl;
}

int main()
{
    vector<int> arr = {4, 7, 1, 1, 2, -3, -7, 17, 15, -16};
    aestroidCollision(arr);
    return 0;
}