#include <vector>
#include <iostream>
#include <string>
using namespace std;

// recursion
bool validParanthesis(int openingCount, int ind, string str)
{
    if (openingCount < 0)
    {
        return false;
    }

    if (ind == str.length())
    {
        return openingCount == 0;
    }

    if (str[ind] == '(')
    {
        return validParanthesis(openingCount + 1, ind + 1, str);
    }
    else if (str[ind] == ')')
    {
        return validParanthesis(openingCount - 1, ind + 1, str);
    }
    return validParanthesis(openingCount + 1, ind + 1, str) || validParanthesis(openingCount - 1, ind + 1, str) || validParanthesis(openingCount, ind + 1, str);
}

// Time Complexity: O(3^n) (can be optimized with dynamic programming)
// Space Complexity: O(n)

bool validParanthesisOptimized(string str)
{
    int min = 0, max = 0;

    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == '(')
        {
            min++;
            max++;
        }
        else if (str[i] == ')')
        {
            min--;
            max--;
        }
        else
        {
            min--;
            max++;
        }

        if (min < 0)
            min = 0;
        if (max < 0)
            return false;
    }

    return min == 0;
}

int main()
{
    string str = "(*()";
    cout << validParanthesis(0, 0, str) << endl;

    string str2 = "(**(";
    cout << validParanthesisOptimized(str2) << endl;

    return 0;
}