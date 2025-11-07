#include <iostream>
#include <vector>
using namespace std;

int bestBuySellStocks(vector<int> &arr)
{
    int mini = arr[0], profit = 0;

    for (int i = 0; i < arr.size(); i++)
    {
        int cost = arr[i] - mini;
        profit = max(profit, cost);
        mini = min(mini, arr[i]);
    }

    return profit;
}

int main()
{
    vector<int> arr = {7, 1, 5, 3, 6, 4};
    cout << bestBuySellStocks(arr) << endl;
}