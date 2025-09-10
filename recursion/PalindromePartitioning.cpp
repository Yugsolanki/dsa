#include <iostream>
#include <vector>
#include <string>
using namespace std;

void printArrayOfArray(vector<vector<string>> &arr)
{
    for (auto i : arr)
    {
        for (auto j : i)
        {
            cout << j << " | ";
        }
        cout << endl;
    }
    cout << endl;
}

bool isPalindrome(int start, int end, string s)
{
    int i = start;
    int j = end;

    while (i <= j)
    {
        if (s[i] != s[j])
            return false;
        i++;
        j--;
    }

    return true;
}

void palindromePartitioning(int ind, string s, vector<string> &temp, vector<vector<string>> &ans)
{
    if (ind >= s.size())
    {
        ans.push_back(temp);
        return;
    }

    for (int i = ind; i < s.size(); i++)
    {
        if (isPalindrome(ind, i, s))
        {
            temp.push_back(s.substr(ind, i - ind + 1));
            palindromePartitioning(i + 1, s, temp, ans);
            temp.pop_back();
        }
    }
}

int main()
{
    string s = "aabb";

    vector<string> temp;
    vector<vector<string>> ans;

    palindromePartitioning(0, s, temp, ans);

    printArrayOfArray(ans);

    return 0;
}