#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int characterReplacement(string s, int k)
{
        int l = 0;
        int maxf = 0;
        int result = 0;
        unordered_map<char, int> mp;

        for (int r = 0; r < s.size(); r++)
        {
            mp[s[r]]++;
            // Update maxf to be the maximum frequency of any character in the current window
            maxf = max(maxf, mp[s[r]]);

            while ((r - l + 1) - maxf > k)
            {
                mp[s[l]]--;
                if (mp[s[l]] == 0)
                    mp.erase(s[l]);
                l++;
            }

            result = max(result, r - l + 1);
        }

        return result;
}

int main()
{
    string s = "ABBB";
    int k = 2;
    cout << characterReplacement(s, k) << endl;
    return 0;
}