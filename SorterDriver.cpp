// SorterDriver.cpp
// contains main for SortImpls.h
// assumes command line input in the form: Sorter.exe SortType ArraySize
// example command line input: Sorter.exe MergeSort 1000
#include <iostream>
#include <vector>
#include <string>
#include <windows.h>
#include "SortImpls.h"
using namespace std;

const string BUBBLE_SORT = "BubbleSort";
const string INSERT_SORT = "InsertSort";
const string QUICK_SORT = "QuickSort";
const string MERGE_SORT = "MergeSort";
const string ITERATIVE_MERGE_SORT = "IterativeMergeSort";

void PrinArray(const vector<int> &array, string name);
void InitArray(vector<int> &array, int randMax);

int main(int argc, char* argv[])
{
	cout << "SORTER\t\tby: Sam Hoover UWB CSS342" << endl << endl;
	if (argc != 3)
	{
		cout << "Usage: Sorter SORT_TYPE ARRAY_SIZE" << endl;
		cout << "Example: Sorter MergeSort 1000";
		return -1;
	}

	string sort_name = string(argv[1]);
	int size = atoi(argv[2]);

	if (size <= 0) 
	{
		cerr << "array size must be positive" << endl;
		return -1;
	}

	srand(1);
	vector<int> items(size);
	InitArray(items, size);
	cout << "Sort employed: " << sort_name << endl;
	
	cout << "initial:" << endl;
	PrinArray(items, string("items"));
	cout << endl;
	int begin = GetTickCount();

	if(sort_name == BUBBLE_SORT) 
	{
		BubbleSort(items, 0, size - 1);
	} 
	else if(sort_name == INSERT_SORT) 
	{
		InsertSort(items, 0, size - 1);
	}
	else if(sort_name == QUICK_SORT) 
	{
		QuickSort(items, 0, size - 1);
	} 
	else if(sort_name == MERGE_SORT) 
	{
		MergeSort(items, 0, size - 1);
	} 
	else if (sort_name == ITERATIVE_MERGE_SORT) 
	{
		IterativeMergeSort(items, 0, size - 1);
	} 
	else 
	{
		cout << "Usage: Sorter SORT_TYPE ARRAY_SIZE" << endl;
		cout << "Example: Sorter MergeSort 1000";
		return(-1);
	}

	int end = GetTickCount();

	cout << "sorted:" << endl;
	PrinArray(items, string("item"));

	int elapsed_secs = end - begin;
	cout << endl << "Time (ms): " << elapsed_secs << endl << endl;
	
	cout << "any key to exit." << endl;
	cin.get();

	return 0;
}
// array initialization with random numbers
void InitArray(vector<int> &array, int randMax)
{
	int size = array.size();
	for (int i = 0; i < size;)
	{
		int tmp = (randMax == -1) ? rand() : rand() % randMax;
		bool hit = false;

		for (int j = 0; j < i; j++)
		{
			if (array[j] == tmp)
			{
				hit = true;
				break;
			}
		}

		if (hit)
		{
			continue;
		}
		array[i] = tmp;
		i++;
	}
}

// Function to Print Array
void PrinArray(const vector<int> &array, string name)
{
	int size = array.size();
	for (int i = 0; i < size; i++) 
	{
		cout << name << "[" << i << "] = " << array[i] << endl;
	}
}
