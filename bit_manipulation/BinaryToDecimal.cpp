#include <iostream>
#include <string>
using namespace std;

int binaryToDecimal(string n)
{
    int len = n.length();
    int powerOf2 = 1;
    int num = 0;

    for (int i = len - 1; i >= 0; i--)
    {
        if (n[i] == '1')
            num += powerOf2;
        powerOf2 *= 2;
    }

    return num;
}

int main()
{
    cout << binaryToDecimal("1101") << endl;
    cout << binaryToDecimal("10000110") << endl;
    cout << binaryToDecimal("110111") << endl;
    cout << (~15) << endl;
    return 0;
}