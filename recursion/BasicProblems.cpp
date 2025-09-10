#include <iostream>
using namespace std;

// Print a Name n times
void printNameNTimes(int i, int n)
{
    if (i > n)
        return;
    cout << "Yug" << endl;
    printNameNTimes(i + 1, n);
}

// Print a Name n times
void printNameNTimes2(int n)
{
    if (n <= 0)
        return;
    cout << "McRae" << endl;
    printNameNTimes2(n - 1);
}

// Print linearly from 1 to n
void print1_to_N_without_backtracking(int i, int n)
{
    if (i > n)
        return;
    cout << i << endl;
    print1_to_N_without_backtracking(i + 1, n);
}

// Print from N to 1
void printN_to_1_without_backtracking(int n)
{
    if (n < 1)
        return;
    printN_to_1_without_backtracking(n - 1);
    cout << n << endl;
}

// Print linearly from 1 to n (but by backtracking)
void print1_to_N_with_backtracking(int n)
{
    if (n < 1)
        return;
    print1_to_N_with_backtracking(n - 1);
    cout << n << endl;
}

// Print from N to 1 (but by backtracking)
void printN_to_1_with_backtracking(int n)
{
    if (n < 1)
        return;
    cout << n << endl;
    printN_to_1_with_backtracking(n - 1);
}

int main()
{
    printNameNTimes(1, 3);
    printNameNTimes2(3);

    cout << "---------------------" << endl;

    print1_to_N_without_backtracking(1, 5);

    cout << "---------------------" << endl;

    printN_to_1_without_backtracking(5);

    cout << "---------------------" << endl;

    print1_to_N_with_backtracking(5);

    cout << "---------------------" << endl;

    printN_to_1_with_backtracking(5);

    return 0;
}