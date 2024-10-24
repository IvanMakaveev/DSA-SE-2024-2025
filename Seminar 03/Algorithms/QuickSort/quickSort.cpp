#include <iostream>*
using namespace std;

template <class T>
size_t partition(T* arr, size_t size)
{
    if (arr[0] > arr[size - 1])
        std::swap(arr[0], arr[size - 1]);

    T& pivot = arr[size - 1];
    size_t left = 0;
    size_t right = size - 1;

    while (true)
    {
        while (arr[++left] < pivot);

        while (arr[--right] > pivot)
        {
            if (left == right)
                break;
        }

        if (left >= right)
            break;

        std::swap(arr[left], arr[right]);
    }

    std::swap(arr[left], pivot);
    return left;
}

template <class T>
void quickSort(T* arr, size_t size)
{
    if (size <= 1)
        return;

    size_t pivotIndex = partition(arr, size);
    quickSort(arr, pivotIndex);
    quickSort(arr + pivotIndex + 1, size - pivotIndex - 1);
}
