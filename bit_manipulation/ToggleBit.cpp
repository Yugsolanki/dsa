#include <iostream>
using namespace std;

int toggleBit(int n, int i)
{
    return n ^ (1 << i);
}

int main()
{
    cout << toggleBit(13, 2) << endl; // 1101 :- 1001 - 9
    cout << toggleBit(13, 1) << endl; // 1101 :- 1111 - 15
    return 0;
}