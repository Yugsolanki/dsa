#include <iostream>
#include <math.h>
using namespace std;

int divide(int dividend, int divisor)
{
    if (dividend == divisor)
        return 1;

    bool sign = true; // true means positive
    if ((dividend >= 0 && divisor < 0) ||
        (dividend < 0 && divisor > 0))
        sign = false;

    int n = abs(dividend);
    int d = abs(divisor);
    int ans = 0;

    while (n >= d)
    {
        int count = 0;
        while (n >= (d << (count + 1))) // d * 2^(count+1)
        {
            count++;
        }
        ans += (1 << count);
        n = n - (d * (1 << count));
    }

    if (ans >= pow(2, 31) && sign == true)
        return INT_MAX;
    else if (ans >= pow(2, 31) && sign == false)
        return INT_MIN;

    return sign ? ans : (-1 * ans);
}

int main()
{
    cout << divide(22, 3) << endl;
    cout << divide(15, 3) << endl;
    cout << divide(77, 12) << endl;
    return 0;
}