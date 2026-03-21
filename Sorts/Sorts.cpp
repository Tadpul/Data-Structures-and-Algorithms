#include <iostream>

void bubbleSort(int numberArray[], int size)
{
    for (int i{ size - 1 }; i > 0; i--)
    {
        for (int j{ 0 }; j < i; j++)
        {
            if (numberArray[j] > numberArray[j + 1])
            {
                int temp{ numberArray[j] };
                numberArray[j] = numberArray[j + 1];
                numberArray[j + 1] = temp;
            }
        }
    }
}

void selectionSort(int numberArray[], int size)
{
    for (int i{ 0 }; i < size - 1; i++)
    {
        int minNumberIndex{ i }; 
        for (int j{ i + 1 }; j < size; j++) { if (numberArray[i] > numberArray[j]) minNumberIndex = j; }

        if (numberArray[i] > numberArray[minNumberIndex])
        {
            int temp{ numberArray[minNumberIndex] };
            numberArray[minNumberIndex] = numberArray[i];
            numberArray[i] = temp;
        }
    }
}

void insertSort(int numberArray[], int size)
{
    for (int i{ 1 }; i < size; i++)
    {
        for (int j{ i }; j > 0 && numberArray[j] < numberArray[j - 1]; j--)
        {
            int temp{ numberArray[j - 1] };
            numberArray[j - 1] = numberArray[j];
            numberArray[j] = temp;
        }
    }
}

int main()
{
    int sortedList[] = {2, 1, 3, 5, 1};
    insertSort(sortedList, 5);
    for (int number : sortedList)
    {
        std::cout << number << ' ';
    }
    std::cout << '\n';
}