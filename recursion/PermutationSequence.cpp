#include <iostream>
#include <vector>
#include <string>
using namespace std;

string getPermutation(int n, int k)
{
    int fact = 1;
    vector<int> arr;

    // for number starting with 1 we have 3! possibilties of {2,3,4}
    // and 3! is basically 6, so fact stores that when we have 4,17 as input

    for (int i = 1; i < n; i++)
    {
        fact = fact * i;
        arr.push_back(i);
    }
    arr.push_back(n);

    string ans = "";

    k = k - 1;

    while (true)
    {
        ans = ans + to_string(arr[k / fact]); // 16/6 == 2 (starting with element at positon 2 i.e. 3)
        arr.erase(arr.begin() + k / fact); // remove it from the arr

        if (arr.size() == 0) // if array empty then close
        {
            break;
        }

        k = k % fact; // for {1,2,4} we need to find 16%6 = 4th sequence
        fact = fact / arr.size();
    }

    return ans;
}

int main()
{
    cout << getPermutation(4, 17) << endl;
    return 0;
}