#pragma once

struct Node 
{
public:
	int value;
	Node* next;
	Node* previous;

    Node(int val);
};

class DoublyLinkedList
{
private:
	Node* head;
	Node* tail;
	Node* defaultNode;
	int length;

public:
	DoublyLinkedList(int initialValue);
    ~DoublyLinkedList();
    void append(int value);
    void deleteLast();
    void prepend(int value);
    void deleteFirst();
    void printList();
    Node* getNode(int index);
    bool setNode(int index, int val);
    bool insertNode(int index, int val);
    bool deleteNode(int index);
    void partitionList(int x);
    void reverseBetween(int index1, int index2);
    void swapPairs();
};