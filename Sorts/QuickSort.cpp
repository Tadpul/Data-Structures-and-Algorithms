#include <iostream>

// helper functions to implement quick sort
void swap(int array[], int index1, int index2)
{
    int temp{ array[index1] };
    array[index1] = array[index2];
    array[index2] = temp;
}

int pivot(int array[], int pivotIndex, int endIndex)
{
    int swapIndex{ pivotIndex };
    for (int i{ pivotIndex }; i <= endIndex; i++)
    {
        if (array[i] < array[pivotIndex])
        {
            swapIndex++;
            swap(array, swapIndex, i);
        }
    }
    swap(array, pivotIndex, swapIndex);
    return swapIndex;
}

// recursive function that implements quick sort
void quickSort(int array[], int leftIndex, int rightIndex)
{
    if (leftIndex >= rightIndex) return;

    int newRightIndex{ pivot(array, leftIndex, rightIndex) };
    quickSort(array, leftIndex, newRightIndex - 1);
    quickSort(array, newRightIndex + 1, rightIndex);
}

