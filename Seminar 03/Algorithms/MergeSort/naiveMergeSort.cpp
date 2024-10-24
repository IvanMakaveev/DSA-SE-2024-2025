#include <iostream>
using namespace std;

template <class T>
void merge(T* firstArr, size_t firstSize, T* secondArr, size_t secondSize)
{
	T* resultArray = new T[firstSize + secondSize];

	int cursor1 = 0;
	int cursor2 = 0;
	int resultCursor = 0;

	while (cursor1 < firstSize && cursor2 < secondSize)
	{
		if (firstArr[cursor1] <= secondArr[cursor2])
			resultArray[resultCursor++] = firstArr[cursor1++];
		else
			resultArray[resultCursor++] = secondArr[cursor2++];
	}

	while (cursor1 < firstSize)
		resultArray[resultCursor++] = firstArr[cursor1++];
	while (cursor2 < secondSize)
		resultArray[resultCursor++] = secondArr[cursor2++];

	for (int i = 0; i < firstSize + secondSize; i++)
		firstArr[i] = resultArray[i];
	delete[] resultArray;
}

template <class T>
void mergeSort(T* arr, size_t size)
{
	if (size == 1)
		return;

	int mid = size / 2;

	mergeSort(arr, mid);
	mergeSort(arr + mid, size - mid);

	merge<T>(arr, mid, arr + mid, size - mid);
}