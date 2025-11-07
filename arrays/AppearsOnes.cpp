#include <iostream>
#include <vector>
using namespace std;

int appearsOnes(vector<int> &arr)
{
    int sum = 0;
    for (int i : arr)
    {
        sum = sum ^ i;
    }

    return sum;
}
int main()
{
    vector<int> arr = {1, 1, 2, 3, 3, 4, 4};
    cout << appearsOnes(arr) << endl;
}