#include <iostream>
#include <vector>
using namespace std;

void printArray(vector<int> &arr)
{
    for (int i : arr)
    {
        cout << i << " ";
    }
    cout << endl;
}

// Print all subsequences the sum upto k
int countSubsequencesSumK(int i, vector<int> &temp, int sum, vector<int> &arr, int k)
{
    // Base condition: If index goes out of bounds
    if (i >= arr.size())
    {
        // Check if the current sum is equal to k
        if (sum == k)
        {
            printArray(temp); // Print the subsequence
            return 1;
        }
        return 0;
    }

    // Case where element is present
    temp.push_back(arr[i]);
    int l = countSubsequencesSumK(i + 1, temp, sum + arr[i], arr, k);

    // Case where element is excluded
    temp.pop_back();
    int r = countSubsequencesSumK(i + 1, temp, sum, arr, k);

    return l + r;
}

int main()
{
    vector<int> arr = {1, 2, 1, 4, 6, 3, 6, 2, 1, 3, 5, 6, 4};
    vector<int> temp;
    cout << countSubsequencesSumK(0, temp, 0, arr, 4) << endl; // 15
    return 0;
}