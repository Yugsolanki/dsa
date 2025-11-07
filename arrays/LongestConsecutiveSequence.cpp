#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

int longestConsecutiveSequence(vector<int> &arr)
{
    if (arr.empty())
        return 0;

    int longest = 1;
    for (int i = 0; i < arr.size(); i++)
    {
        int x = arr[i];
        int count = 1;

        while (true)
        {
            bool foundNext = false;

            for (int j = 0; j < arr.size(); j++)
            {
                if (arr[j] == x + 1)
                {
                    x++;
                    count++;
                    foundNext = true;
                    break;
                }
            }

            if (!foundNext)
                break;
        }

        longest = max(longest, count);
    }

    return longest;
}
// Time Complexity: O(n^2)
// Space Complexity: O(1)

int longestConsecutiveSequenceBetter(vector<int> &arr)
{
    sort(arr.begin(), arr.end());

    int longest = 1, count = 1, lastSmaller = INT_MIN;

    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] - 1 == lastSmaller)
        {
            count++;
            lastSmaller = arr[i];
        }
        else if (arr[i] - 1 == lastSmaller)
        {
            continue;
        }
        else
        {
            count = 1;
            lastSmaller = arr[i];
        }
        longest = max(longest, count);
    }

    return longest;
}

// TC: O(N * logN) + O(N)
// SC: O(1)

int longestConsecutiveSequenceOptimal(vector<int> &arr)
{
    int longest = 1;
    unordered_set<int> st(arr.begin(), arr.end());

    for (int i : st)
    {
        if (st.find(i - 1) == st.end())
        {
            int count = 1;
            int x = i;

            while (st.find(x + 1) != st.end())
            {
                count++;
                x++;
            }
            longest = max(longest, count);
        }
    }

    return longest;
}

int main()
{
    vector<int> arr = {102, 4, 100, 1, 101, 3, 2, 1, 1};
    cout << longestConsecutiveSequence(arr) << endl;
    cout << longestConsecutiveSequenceBetter(arr) << endl;
    cout << longestConsecutiveSequenceOptimal(arr) << endl;
}