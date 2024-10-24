#include <utility>

template <class T>
void bubbleSort(T* arr, size_t size)
{
    unsigned int end = size - 1;
    for (size_t i = 0; i < size; i++)
    {
        unsigned int lastSwappedIndex = 0;

        for (size_t j = 0; j < end; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                std::swap(arr[j], arr[j + 1]);
                lastSwappedIndex = j;
            }
        }

        if (lastSwappedIndex == 0)
        {
            return;
        }

        end = lastSwappedIndex;
    }
}