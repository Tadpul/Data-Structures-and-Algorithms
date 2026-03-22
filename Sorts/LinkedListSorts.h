#pragma once

#include <initializer_list>
#include <iostream>

struct Node
{
public:
    int value;
    Node* next;

    Node(int val);
};

class LinkedList
{
private:
    int size;
    Node* head;
    Node* tail;

public:
    LinkedList();
    LinkedList(int val);
    LinkedList(std::initializer_list<int> vals);
    ~LinkedList();

    void push(int val);
    int at(int index);
    void changeValueAt(int index, int value);
    bool swap(int index1, int index2);
    void printLinkedList();
    int getSize();
};

std::ostream& operator<<(std::ostream& os, LinkedList& linkedList);

void bubbleSort(LinkedList& linkedList);
void selectionSort(LinkedList& linkedList);
void insertionSort(LinkedList& linkedList);

void merge(LinkedList& linkedList, int leftIndex, int middleIndex, int rightIndex);
void mergeSort(LinkedList& linkedList, int leftIndex, int rightindex);
