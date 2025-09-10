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

int partition(int low, int high, vector<int> &arr)
{
	int pivot = arr[low];
	int i = low;
	int j = high;

	while (i < j) {
		while (arr[i] <= pivot && i < high)
		{
			i++;
		}

		while (arr[j] > pivot && j > low)
		{
			j--;
		}

		if (i < j)
			swap(arr[i], arr[j]);
	}

	swap(arr[low], arr[j]);
	return j;
}

void quickSort(int low, int high, vector<int> &arr)
{
	if (low < high) {
		int partitionIdx = partition(low, high, arr);
		quickSort(low, partitionIdx-1, arr);
		quickSort(partitionIdx+1, high, arr);
	}
}

int main()
{
	vector<int> arr = {2,3,4,1,5,6,3,0,2,2,2,2,0,4,3,6};
	quickSort(0, arr.size()-1, arr);
	printArray(arr);
	return 0;
}