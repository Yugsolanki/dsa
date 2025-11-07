#include <iostream>
#include <vector>
#include <string>
using namespace std;

int substringsAllThree(string s)
{
    int lastseen[3] = {-1, -1, -1};
    int count = 0;

    for (int i = 0; i < s.length(); i++)
    {
        lastseen[s[i] - 'a'] = i;

        if (lastseen[0] != -1 && lastseen[1] != -1 && lastseen[1] != -1)
        {
            count = count + (1 + min(lastseen[0], min(lastseen[1], lastseen[2])));
        }
    }

    return count;
}

int main()
{
    string s = "bbacba";
    cout << substringsAllThree(s) << endl;
}