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
            array[index] = leftArray[j];
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
        array[index] = leftArray[j];
        j++;
        index++;
    }
}

int main()
{
    int numberArray[]{1, 3, 4, 6, 7, 9, 2, 4, 5, 6, 7, 8};
    merge(numberArray, 0, 5, 11);

    for (int i{ 0 }; i < 11; i++)
    {
        std::cout << numberArray[i] << ' ';
        numberArray[i];
    }
}