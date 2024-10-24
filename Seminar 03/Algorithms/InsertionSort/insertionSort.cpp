#include <utility>

template <class T>
void insertionSort(T* arr, size_t size)
{
    for (size_t i = 1; i < size; i++)
    {
        T element = arr[i];
        size_t index = i - 1;

        while (index >= 0 && arr[index] > element)
        {
            arr[index + 1] = arr[index];
            index--;
        }

        arr[index + 1] = element;
    }
}