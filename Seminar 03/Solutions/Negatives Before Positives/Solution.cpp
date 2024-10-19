// Example - Partition by Hoare

template <typename T>
int partition(T* arr, int len, T pivot)
{
	int left = 0;
    int right = len - 1;

	while (true)
    {
		while (arr[right] > pivot)
			right--;

		while (arr[left] < pivot)
			left++;

		if (left < right)
			std::swap(arr[left], arr[right]);
		else
			return right;
	}
}

void positivesAndNegatives(int* arr, size_t len)
{
	partition<int>(arr, len, 0);
}