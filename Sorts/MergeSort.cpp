#include <iostream>
#include <vector>

void merge(int array[], int leftIndex, int middleIndex, int rightIndex)
{
    int leftArraySize{ middleIndex - leftIndex + 1};
    int rightArraySize{ rightIndex - middleIndex };

    std::vector<int> leftArray(leftArraySize);
    std::vector<int> rightArray(rightArraySize);

    for (int i{ 0 }; i < leftArraySize; i++) { leftArray[i] = array[leftIndex + i]; }
    for (int j{ 0 }; j < rightArraySize; j++) { rightArray[j] = array[middleIndex + 1 + j]; }

    int index = leftIndex;
    int i{ 0 };
    int j{ 0 };
    while (i < leftArraySize && j < rightArraySize)
    {
        if (leftArray[i] < rightArray[j])
        {
            array[index] = leftArray[i];
            i++;
            index++;
        }
        else
        {
            array[index] = rightArray[j];
            j++;
            index++;
        }
    }

    while (i < leftArraySize)
    {
        array[index] = leftArray[i];
        i++;
        index++;
    }

    while (j < rightArraySize)
    {
        array[index] = rightArray[j];
        j++;
        index++;
    }
}

void meregeSort(int array[], int leftIndex, int rightIndex)
{
    if (leftIndex == rightIndex) return;

    int middleIndex = leftIndex + (rightIndex - leftIndex) / 2;
    meregeSort(array, leftIndex, middleIndex);
    meregeSort(array, middleIndex + 1, rightIndex);

    merge(array, leftIndex, middleIndex, rightIndex);
}

int main()
{
    int numberArray[]{1, 6, 4, 6, 7, 9, 2, 4, 1, 6, 7, 8};
    meregeSort(numberArray, 0, 11);

    for (int i{ 0 }; i < 12; i++)
    {
        std::cout << numberArray[i] << ' ';
        numberArray[i];
    }
}