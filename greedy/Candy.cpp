#include <iostream>
#include <vector>
using namespace std;

int candy(vector<int> ratings)
{
    int n = ratings.size();

    vector<int> left(n);
    vector<int> right(n);
    int count = 0;

    left[0] = 1;
    for (int i = 1; i < n; i++)
    {
        left[i] = ratings[i - 1] < ratings[i] ? left[i - 1] + 1 : 1;
    }

    right[n - 1] = 1;
    for (int i = n - 2; i >= 0; i--)
    {
        right[i] = ratings[i + 1] < ratings[i] ? right[i + 1] + 1 : 1;
    }

    for (int i = 0; i < n; i++)
    {
        count += max(left[i], right[i]);
    }

    return count;
}

// Time Complexity: O(3N)
// Space Complexity: O(2N)

// Same as previous but with optimized space complexity
int candyOptimized(vector<int> ratings)
{
    int n = ratings.size();

    vector<int> left(n);

    left[0] = 1;
    for (int i = 1; i < n; i++)
    {
        left[i] = ratings[i - 1] < ratings[i] ? left[i - 1] + 1 : 1;
    }

    int rightPrev = 1;
    int count = max(rightPrev, left[n - 1]);

    for (int i = n - 2; i >= 0; i--)
    {
        int temp = ratings[i + 1] < ratings[i] ? rightPrev + 1 : 1;
        rightPrev = temp;
        count += max(left[i], temp);
    }

    return count;
}

// Time Complexity: O(2N)
// Space Complexity: O(N)

// Most optimized Solution
int candyMostOptimized(vector<int> ratings)
{
    int n = ratings.size();
    int sum = 1;
    int i = 1;

    while (i < n)
    {
        if (ratings[i] == ratings[i - 1])
        {
            sum++;
            i++;
            continue;
        }

        int peak = 1;
        while (i < n && ratings[i] > ratings[i - 1])
        {
            peak++;
            sum += peak;
            i++;
        }

        int down = 1;
        while (i < n && ratings[i] < ratings[i - 1])
        {
            down++;
            sum += down;
            i++;
        }

        if (down > peak)
            sum += down - peak;
    }

    return sum;
}

int main()
{
    vector<int> arr = {1, 0, 2};
    cout << candyOptimized(arr) << endl;
    return 0;
}