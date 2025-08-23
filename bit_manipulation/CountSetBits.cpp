#include <iostream>
using namespace std;

int countSetBits(int n)
{
    int count = 0;

    while (n > 0)
    {
        count += n & 1;
        n = n >> 1;
    }

    return count;
}

// Time Complexity : O(log n) (where n is the number of bits)

int countSetBits2(int n)
{
    int count = 0;

    while (n != 0)
    {
        n = n & (n - 1);
        count++;
    }

    return count;
}

// Time Complexity : O(s) (where s is the number of set bits) (more efficient)

int main()
{
    cout << countSetBits(13) << endl; // 1101
    cout << countSetBits(83) << endl; // 1010011

    cout << "------------" << endl;

    cout << countSetBits2(13) << endl; // 1101
    cout << countSetBits2(83) << endl; // 1010011

    return 0;
}