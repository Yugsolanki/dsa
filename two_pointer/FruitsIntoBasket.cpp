#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int fruitsIntoBasket(vector<int> arr)
{
    int l = 0;
    unordered_map<int, int> basket;
    int count = 0;

    for (int r = 0; r < arr.size(); r++)
    {
        basket[arr[r]]++;

        while (basket.size() > 2)
        {
            basket[arr[l]]--;
            if (basket[arr[l]] == 0)
            {
                basket.erase(arr[l]);
            }
            l++;
        }

        count = max(count, r - l + 1);
    }

    return count;
}
// O(2N)

int fruitsIntoBasket2(vector<int> arr)
{
    int l = 0, r = 0;
    unordered_map<int, int> basket;
    int count = 0;

    while (r < arr.size())
    {
        basket[arr[r]]++;

        if (basket.size() > 2)
        {
            basket[arr[l]]--;
            if (basket[arr[l]] == 0)
            {
                basket.erase(arr[l]);
            }
            l++;
        }

        count = max(count, r - l + 1);
        r++;
    }
    return count;
}
// O(N)

int main()
{
    // Basic test — simple repeating pattern
    vector<int> arr1 = {1, 2, 3, 2, 2};
    cout << fruitsIntoBasket(arr1) << endl; // Expected: 4 (subarray [2,3,2,2])

    // All same fruit — only one type
    vector<int> arr2 = {1, 1, 1, 1, 1};
    cout << fruitsIntoBasket(arr2) << endl; // Expected: 5 (all trees can be picked)

    // Alternating fruits — exactly two types
    vector<int> arr3 = {1, 2, 1, 2, 1, 2};
    cout << fruitsIntoBasket(arr3) << endl; // Expected: 6 (entire array valid)

    // Three consecutive fruit types
    vector<int> arr4 = {1, 2, 3, 4, 5};
    cout << fruitsIntoBasket(arr4) << endl; // Expected: 2 (any pair of adjacent fruits)

    // Complex mix — multiple switches
    vector<int> arr5 = {1, 2, 1, 2, 3, 2, 2, 1};
    cout << fruitsIntoBasket(arr5) << endl; // Expected: 5 (subarray [2,1,2,3,2])

    // Single fruit tree
    vector<int> arr6 = {1,2,1};
    cout << fruitsIntoBasket(arr6) << endl; // Expected: 1

    // Two fruit trees — both different
    vector<int> arr7 = {5, 6};
    cout << fruitsIntoBasket(arr7) << endl; // Expected: 2

    // Two fruit trees — both same
    vector<int> arr8 = {9, 9};
    cout << fruitsIntoBasket(arr8) << endl; // Expected: 2

    // Large alternating section followed by new type
    vector<int> arr9 = {1, 2, 1, 2, 1, 2, 3};
    cout << fruitsIntoBasket(arr9) << endl; // Expected: 6 (before hitting 3)

    // Random distribution
    vector<int> arr10 = {3, 3, 3, 1, 2, 1, 1, 2, 3, 3, 4};
    cout << fruitsIntoBasket(arr10) << endl; // Expected: 5 (subarray [1,2,1,1,2])

    vector<int> arr11 = {1, 2, 1, 3, 4, 3, 5, 1};
    cout << fruitsIntoBasket(arr11) << endl; // 4

    vector<int> arr12 = {1, 0, 1, 4, 1, 4, 1, 2, 3};
    cout << fruitsIntoBasket(arr12) << endl; // 5

    return 0;
}
