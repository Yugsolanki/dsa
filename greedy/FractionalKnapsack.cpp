#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool comparator(vector<int> a, vector<int> b)
{
    // return true if a should come before b
    // for descending order of value
    return static_cast<double>(a[0] / a[1]) > static_cast<double>(b[0] / b[1]);
}

double fractionalKnapsack(vector<vector<int>> &arr, int weight)
{
    sort(arr.begin(), arr.end(), comparator);

    double totalVal = 0;

    for (int i = 0; i < arr.size() && weight != 0; i++)
    {
        if (arr[i][1] <= weight)
        {
            totalVal += arr[i][0];
            weight -= arr[i][1];
        }
        else
        {
            totalVal += (static_cast<double>(arr[i][0] / arr[i][1])) * weight;
            weight = 0;
        }
    }

    return totalVal;
}

int main()
{
    vector<vector<int>> arr = {
        {100, 20},
        {60, 10},
        {100, 50},
        {200, 50}};

    cout << fractionalKnapsack(arr, 90) << endl;

    return 0;
}