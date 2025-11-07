#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
using namespace std;

int LongestSubstringWithoutRepeating(string str)
{
    unordered_map<char, int> mp;
    int l = 0, r = 0;
    int count = 0;

    while (r < str.size() && l < str.size())
    {
        if (mp.find(str[r]) == mp.end())
        {
            mp[str[r]] = r;
            count = max(count, r - l + 1);
            r++;
        }
        else
        {
            int temp = l;
            l = mp[str[l]] + 1;
            mp.erase(str[temp]);
        }
    }

    return count;
}

int main()
{
    cout << LongestSubstringWithoutRepeating("abcabcbb") << endl;
    return 0;
}