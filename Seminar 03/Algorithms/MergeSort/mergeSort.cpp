#include <iostream>
using namespace std;

template <class T>
void merge(T* firstArr, size_t firstSize, T* secondArr, size_t secondSize, T* buffer)
{
	size_t resultIter = 0;
	size_t firstIter = 0;
	size_t secondIter = 0;

	while (firstIter < firstSize && secondIter < secondSize)
		buffer[resultIter++] = (firstArr[firstIter] < secondArr[secondIter] ? firstArr[firstIter++] : secondArr[secondIter++]);

	while (firstIter < firstSize)
		buffer[resultIter++] = firstArr[firstIter++];

	while (secondIter < secondSize)
		buffer[resultIter++] = secondArr[secondIter++];
}

template <class T>
void mergeSortStep(T* arr, size_t size, T* buffer)
{
	if (size <= 1)
		return;

	size_t middle = size / 2;

	mergeSortStep(arr, middle, buffer);

	mergeSortStep(arr + middle, size - middle, buffer + middle);

	merge(arr, middle, arr + middle, size - middle, buffer);

	for (size_t i = 0; i < size; i++)
		arr[i] = buffer[i];
}

template <class T>
void mergeSort(T* arr, size_t size)
{
	if (!arr || size == 0)
		return;

	T* buffer = new T[size];

	mergeSortStep(arr, size, buffer);

	delete[] buffer;
}