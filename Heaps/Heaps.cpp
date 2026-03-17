#include <iostream>
#include <vector>

class Heap
{
private:
    std::vector<int> heap;

    int leftChild(int index) { return index * 2 + 1; }

    int rightChild(int index) { return index * 2 + 2; }

    int parent(int index) { return (index - 1) / 2; }
    
    void swap(int index1, int index2) 
    {
        int temp{ heap[index1] };
        heap[index1] = heap[index2];
        heap[index2] = temp;
    }


public:
    void insert(int val)
    {
        heap.push_back(val);
        int current = heap.size() - 1;

        while (current > 0 && heap[current] > heap[parent(current)])
        {
            swap(current, parent(current));
            current = parent(current);
        }
    }

    void printHeap()
    {
        std::cout << "[ ";
        for (int value : heap)
        {
            std::cout << value << ' ';
        }
        
        std::cout << ']';
    }

    void pushDown(int index)
    {
        int current{ index };
        int max{ index };

        while (true)
        {
            if(leftChild(current) < heap.size() && heap[leftChild(current)] > heap[current]) max = leftChild(current);
            if(rightChild(current) < heap.size() && heap[rightChild(current)] > heap[current]) max = rightChild(current);

            if (current != max)
            {
                swap(current, max);
                current = max;
            }
            else return;
        }
    }
    
    int remove()
    {
        if (heap.size() == 0) return INT_MIN;

        int max{ heap[0] };
        if (heap.size() == 1) heap.pop_back();
        else
        {
            heap[0] = heap.back();
            heap.pop_back();
            pushDown(0);
        }

        return max;
    }
};

int main()
{
    
}