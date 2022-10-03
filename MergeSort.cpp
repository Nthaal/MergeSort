#include <iostream>
using namespace std;

void MergeSort(int arr[], int leftPose, int rightPose, int mid)
{
	int FirstHalf = mid - leftPose + 1;
	int SecondHalf = rightPose - mid;

	int* leftArr = new int[FirstHalf];
	int* rightArr = new int[SecondHalf];

	int leftArrIndex = 0;
	int rightArrIndex = 0;
	int mergeArrIndex = leftPose;

	for (int i = 0; i < FirstHalf; i++) leftArr[i] = arr[leftPose + i];
	for (int i = 0; i < SecondHalf; i++) rightArr[i] = arr[mid + 1 + i];

	while (leftArrIndex < FirstHalf && rightArrIndex < SecondHalf)
	{
		if (leftArr[leftArrIndex] <= rightArr[rightArrIndex])
		{
			arr[mergeArrIndex] = leftArr[leftArrIndex];
			leftArrIndex++;
		}
		else
		{
			arr[mergeArrIndex] = rightArr[rightArrIndex];
			rightArrIndex++;
		}
		mergeArrIndex++;
	}

	while (leftArrIndex < FirstHalf)
	{
		arr[mergeArrIndex] = leftArr[leftArrIndex];
		leftArrIndex++;
		mergeArrIndex++;
	}

	while (rightArrIndex < SecondHalf)
	{
		arr[mergeArrIndex] = rightArr[rightArrIndex];
		rightArrIndex++;
		mergeArrIndex++;
	}

	delete[] leftArr;
	delete[] rightArr;
}

void Merge(int arr[], int leftPose, int rightPose)
{
	if (leftPose >= rightPose) return;

	int mid = leftPose + (rightPose - leftPose) / 2;
	Merge(arr, leftPose, mid);
	Merge(arr, mid + 1, rightPose);
	MergeSort(arr, leftPose, rightPose, mid);
}

int main()
{
	int arr[] = { 14, 11, 56, 1, 16, 166, 24, 62 };
	int arrSize = sizeof(arr) / sizeof(arr[0]);

	for (int i = 0; i < arrSize; i++) cout << arr[i] << " ";
	
	Merge(arr, 0, arrSize - 1);

	cout << "\n";
	for (int i = 0; i < arrSize; i++) cout << arr[i] << " ";

	return 0;
}