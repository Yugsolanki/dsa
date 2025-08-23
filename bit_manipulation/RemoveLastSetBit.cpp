#include <iostream>
using namespace std;

int removeLastSetBit(int n)
{
    return (n & (n - 1));
}

int main()
{
    cout << removeLastSetBit(12) << endl; // 1100 :- 1000 (8)
    cout << removeLastSetBit(16) << endl; // 10000 :- 0
    cout << removeLastSetBit(40) << endl; // 101000 :- 100000 (32)
    return 0;
}