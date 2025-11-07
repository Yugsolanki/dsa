#include <iostream>
#include <vector>
#include <string>
using namespace std;

string minWindowsSubstring(string s, string t)
{
    int l = 0, r = 0;
    vector<int> hash(256, 0);
    int minLength = __INT_MAX__;
    int startIndex = -1;
    int count = 0;

    for (int i = 0; i < t.length(); i++)
    {
        hash[t[i]]++;
    }

    while (r < s.length())
    {
        if (hash[s[r]] > 0)
        {
            count++;
        }
        hash[s[r]]--;

        while (count == t.length())
        {
            if ((r - l + 1) < minLength)
            {
                minLength = r - l + 1;
                startIndex = l;
            }
            hash[s[l]]++;

            if (hash[s[l]] > 0)
            {
                count--;
            }

            l++;
        }

        r++;
    }

    return startIndex == -1 ? "" : s.substr(startIndex, minLength);
}

int main()
{
    string s = "ADOBECODEBANC";
    string t = "ABC";
    cout << minWindowsSubstring(s, t) << endl;

    return 0;
}