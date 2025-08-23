#include <iostream>
using namespace std;

// Check if the number is power of 2
bool checkPowerOf2(int n)
{
    if ((n & (n - 1)) == 0)
        return true;

    return false;
}

int main()
{
    cout << checkPowerOf2(12) << endl;
    cout << checkPowerOf2(16) << endl;
    cout << checkPowerOf2(32) << endl;
    cout << checkPowerOf2(17) << endl;
    return 0;
}