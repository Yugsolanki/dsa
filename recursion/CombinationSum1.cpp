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

// Repetition is allowed
void combinationSum(int i, int sum, vector<int> &temp, vector<int> &arr, int target)
{
	if (i == arr.size())
	{
		if (target == sum)
		{
			printArray(temp);
		}
		return;
	}

	// Where we include the same element
	// for example the sum = 5 and target is 7 and the arr[i] = 3 then we already know
	// 5+3 will be 8 which will be more than target therefore we are checking if
	// target - sum (7-5 = 2) is less than or equal to arr[i] (3)
	if (arr[i] <= target - sum)
	{
		temp.push_back(arr[i]);
		combinationSum(i, sum + arr[i], temp, arr, target);
		temp.pop_back(); // having it here cuz i'm also pushing here inside scope, only when condition match.
	}

	// Where we not include the same element rather we increment i
	combinationSum(i + 1, sum, temp, arr, target);
}

int main()
{
	vector<int> arr = {2, 3, 6, 7};
	vector<int> temp;
	combinationSum(0, 0, temp, arr, 7);
	return 0;
}