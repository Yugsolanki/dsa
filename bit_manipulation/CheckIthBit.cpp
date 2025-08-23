#include <iostream>
using namespace std;

bool checkIthBit(int n, int i)
{
    if ((n & (1 << i)) != 0)
        return true;

    return false;
}

bool checkIthBit2(int n, int i)
{
    if (((n >> i) & 1) == 1)
        return true;

    return false;
}

int main()
{
    cout << checkIthBit(13, 1) << endl;  // 1101
    cout << checkIthBit2(13, 1) << endl; // 1101
    return 0;
}