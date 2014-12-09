// SortImpls.h		
// contains the declarations and definitions for BubbleSort, InsertSort,
// QuickSort, MergeSort, IterativeMergeSort, and their helper functions.

#ifndef SORTIMPLS_H
#define SORTIMPLS_H
#include <iostream>
#include <vector>
using namespace std;

void BubbleSort(vector<int> &arr, int first, int last);
void InsertSort(vector<int> &arr, int first, int last);
void QuickSort(vector<int> &arr, int first, int last);
int SortFirstMiddleLast(vector<int> &arr, int first, int last);
int Partition(vector<int> &arr, int first, int pivot, int last);
void MergeSort(vector<int> &arr, int first, int last);
void Merge(vector<int> &arr, int first, int middle, int last);
void IterativeMergeSort(vector<int> &arr, int first, int last);
void SwapValues(int &val1, int &val2);

void BubbleSort(vector<int> &arr, int first, int last) 
{
	int length = last + 1;
	for(int i = first; i < length; i++) 
	{
		for(int j = (first + 1); j < length; j++) 
		{
			if(arr[j] < arr[j - 1]) 
			{
				SwapValues(arr[j], arr[j - 1]);
			}
		}
	}
}

void InsertSort(vector<int> &arr, int first, int last) 
{
	int length = last + 1;
	for(int i = first; i < length; i++) 
	{
		int temp = arr[i];
		int j = i;
		while(j > first && arr[j - 1] > temp) 
		{
			arr[j] = arr[j - 1];
			j--;
		}
		arr[j] = temp;
	}
}

void QuickSort(vector<int> &arr, int first, int last) 
{
	if(last > first) 
	{
		if(last - first < 4) 
		{
			InsertSort(arr, first, last);
		} 
		else 
		{
			int pivot = SortFirstMiddleLast(arr, first, last);
			pivot = Partition(arr, first, pivot, last);
			QuickSort(arr, first, pivot - 1);
			QuickSort(arr, pivot + 1, last);
		}
	}
}

int SortFirstMiddleLast(vector<int> &arr, int first, int last) 
{
	int middle = (first + last) / 2;

	if(arr[middle] < arr[first]) 
	{
		SwapValues(arr[first], arr[middle]);
	}
	if(arr[last] < arr[middle]) 
	{
		SwapValues(arr[last], arr[middle]);
	}
	if(arr[middle] < arr[first]) 
	{
		SwapValues(arr[first], arr[middle]);
	}
	return(middle);
}

int Partition(vector<int> &arr, int first, int pivot, int last) 
{
	int pivotValue = arr[pivot];
	int savedSpot = first;

	SwapValues(arr[pivot], arr[last]);
	for(int i = first; i < last; i++) 
	{
		if(arr[i] <= pivotValue) 
		{
			SwapValues(arr[i], arr[savedSpot]);
			savedSpot++;
		}
	}
	SwapValues(arr[savedSpot], arr[last]);
	return(savedSpot);
}

void MergeSort(vector<int> &arr, int first, int last) 
{
	if(first < last) 
	{
		int middle = (first + last) / 2;
		MergeSort(arr, first, middle);
		MergeSort(arr, middle + 1, last);
		Merge(arr, first, middle, last);
	}
}

void Merge(vector<int> &arr, int first, int middle, int last) 
{
	int *tempArray = new int[last];
	int first1 = first;
	int last1 = middle;
	int first2 = middle + 1;
	int last2 = last;
	int index = first1;

	while(first1 <= last1 && first2 <= last2) 
	{
		if(arr[first1] <= arr[first2]) 
		{
			tempArray[index] = arr[first1];
			first1++;
		} 
		else 
		{
			tempArray[index] = arr[first2];
			first2++;
		}
		index++;
	}

	while(first1 <= last1) 
	{
		tempArray[index] = arr[first1];
		first1++;
		index++;
	}

	while(first2 <= last2) 
	{
		tempArray[index] = arr[first2];
		first2++;
		index++;
	}

	for(index = first; index <= last; index++) 
	{
		arr[index] = tempArray[index];
	}
}

void IterativeMergeSort(vector<int> &arr, int first, int last) 
{
	if(first < last) 
	{
		int *temp = new int[last + 1];
		int arrLength = (last - first) + 1;
		int arrEnd = last + 1;
		int subArrSize = 1;
		int first1, first2, last1, last2;
		int index1, index2, tempIndex;
	
		for(tempIndex = 0; tempIndex < first; tempIndex++) 
		{
			temp[tempIndex] = arr[tempIndex];
		}

		while(subArrSize < arrLength) 
		{
			first1 = first;
			tempIndex = first;
			while((first1 + subArrSize) < arrEnd) 
			{
				first2 = first1 + subArrSize;
				last1 = first2 - 1;
				last2 = ((first2 + subArrSize - 1) < arrEnd) ? (first2 + subArrSize - 1) : (arrEnd - 1);

				for(index1 = first1, index2 = first2; index1 <= last1 && index2 <= last2; tempIndex++) 
				{
					if(arr[index1] <= arr[index2]) 
					{
						temp[tempIndex] = arr[index1++];
					} 
					else 
					{
						temp[tempIndex] = arr[index2++];
					}
				}

				while(index1 <= last1) 
				{
					temp[tempIndex++] = arr[index1++];
				}

				while(index2 <= last2) 
				{
					temp[tempIndex++] = arr[index2++];
				}

				first1 = last2 + 1;
			}

			for(index1 = first1; tempIndex < arrEnd; index1++)
			{
				temp[tempIndex++] = arr[index1];
			}

			for(int i = first; i < arrEnd; i++) 
			{
				arr[i] = temp[i];
			}

			subArrSize *= 2;
		}	
	}
}

void SwapValues(int &val1, int &val2) 
{
	int temp = val2;
	val2 = val1;
	val1 = temp;
}

#endif