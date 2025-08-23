#include <iostream>
using namespace std;

int countSetBits(int n)
{
    int count = 0;
    while (n != 0)
    {
        n = n & (n - 1);
        count++;
    }
    return count;
}

// Number of flips required to convert a number
int flipToConvert(int start, int goal)
{
    int res_xor = start ^ goal;
    return countSetBits(res_xor);
}

int main()
{
    cout << flipToConvert(10, 7) << endl;
    cout << flipToConvert(3, 4) << endl;
    return 0;
}