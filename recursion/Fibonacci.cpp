#include <iostream>
using namespace std;

int fibonacci(int n)
{
    if (n <= 1)
        return n;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main()
{
    cout << fibonacci(4) << endl;
    cout << fibonacci(8) << endl;
    cout << fibonacci(6) << endl;
    return 0;
}