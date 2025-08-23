#include <iostream>
using namespace std;

int settingIthBit(int n, int i)
{
    return n | (1 << i);
}

int main()
{
    cout << settingIthBit(9, 2) << endl; // 13
    return 0;
}