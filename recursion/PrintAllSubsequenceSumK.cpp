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

// Print only one subsequence that sum upto k
bool printSubsequencesSumK(int i, vector<int> &temp, int sum, vector<int> &arr, int k)
{
    // Base condition: If index goes out of bounds
    if (i >= arr.size())
    {
        // Check if the current sum is equal to k
        if (sum == k)
        {
            printArray(temp); // Print the subsequence
            return true;
        }

        return false;
    }

    // Case where element is present
    temp.push_back(arr[i]);
    if (printSubsequencesSumK(i + 1, temp, sum + arr[i], arr, k) == true)
        return true;

    // Case where element is excluded
    temp.pop_back();
    if (printSubsequencesSumK(i + 1, temp, sum, arr, k) == true)
        return true;

    return false;
}

int main()
{
    vector<int> arr = {1, 2, 1, 4, 6, 3, 6, 2, 1, 3, 5, 6, 4};
    vector<int> temp;
    printSubsequencesSumK(0, temp, 0, arr, 4);
}