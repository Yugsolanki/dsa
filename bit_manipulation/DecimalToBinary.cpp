#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string decimalToBinary(int n)
{
    string res = "";
    while (n != 0)
    {
        if (n % 2 == 1)
            res += "1";
        else
            res += "0";
        n = n / 2;
    }

    reverse(res.begin(), res.end());

    return res;
}

int main()
{
    cout << decimalToBinary(15) << endl;
    cout << decimalToBinary(134) << endl;
    cout << decimalToBinary(55) << endl;
    return 0;
}