#include <iostream>
using namespace std;

int clearingBit(int n, int i)
{
    return (n & ~(1 << i));
}

int main()
{
    cout << clearingBit(13, 2) << endl; // 1101 :- 1001 - (9)
    return 0;
}