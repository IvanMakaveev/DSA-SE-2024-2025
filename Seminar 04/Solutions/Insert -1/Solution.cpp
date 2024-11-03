size_t getInsertedIndex(const int* arr1, const int* arr2, size_t start, size_t end)
{
	size_t mid = start + (end - start) / 2;

	if (arr2[mid] == -1)
		return mid;

	if (arr2[mid] == arr1[mid])
		return getInsertedIndex(arr1, arr2, mid + 1, end);
	else
		return getInsertedIndex(arr1, arr2, start, mid - 1);
}