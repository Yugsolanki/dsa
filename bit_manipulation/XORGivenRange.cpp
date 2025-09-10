#include <iostream>
#include <vector>
using namespace std;

// Given an number N find XOR of 1 - N
int XORGivenRange(int N)
{
    int mod = N % 4;

    if (mod == 1)
        return 1;
    else if (mod == 2)
        return N + 1;
    else if (mod == 3)
        return 0;

    return N;
}

// Give L and R find XOR L - R
int XORBetweenRange(int L, int R)
{
    return XORGivenRange(L - 1) ^ XORGivenRange(R);
}

int main()
{
    for (int i = 1; i < 9; i++)
    {
        cout << XORGivenRange(i) << endl;
        if (i % 4 == 0)
            cout << endl;
    }

    cout << endl
         << "XOR Between Range" << endl;
    cout << XORBetweenRange(4, 17) << endl;
    cout << XORBetweenRange(5, 10) << endl;
    cout << XORBetweenRange(2, 8) << endl;
    return 0;
}