#include <iostream>
using namespace std;

// version where the function is parameterized
void sum_upto_n_parameterized(int i, int sum)
{
    if (i < 1)
    {
        cout << sum << endl;
        return;
    }
    sum_upto_n_parameterized(i - 1, sum + i);
}

// where the function itself returns the sum
int sum_upto_n(int n)
{
    if (n < 1)
        return 0;
    return n + sum_upto_n(n - 1);
}

int main()
{
    sum_upto_n_parameterized(5, 0);

    cout << sum_upto_n(5) << endl;

    return 0;
}