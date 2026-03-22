#pragma once

struct Node 
{
public:
	int value;
	Node* next;

    Node(int value);
};

class LinkedList 
{
private:
	Node* head;
	Node* tail;
	int numOfNodes;

public:
    LinkedList(int value);
    ~LinkedList();
    void append(int value);
    void removeLastNode();
    Node* getNode(int index);
    void prependNode(int value);
    bool setNode(int index, int val);
    bool insertNode(int index, int val);
    bool deleteNode(int index);
    void reverseList();
    Node* getMiddle();
    int binaryToDecimal();
    void partitionList(int x);
    void reverseBetween(int index1, int index2);
    void swapPairs();
    void printList();

    void getHead();
    void getTail();
    void getLength();
};