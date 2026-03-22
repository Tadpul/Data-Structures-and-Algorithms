#pragma once
#include <vector>

class Heap
{
private:
    std::vector<int> heap;

    int leftChild(int index);
    int rightChild(int index);
    int parent(int index);
    void swap(int index1, int index2);

public:
    void insert(int val);
    void printHeap();
    void pushDown(int index);
    int remove();
};