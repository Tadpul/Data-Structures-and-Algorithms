#pragma once

struct Node
{
public:
    int value;
    Node* next;

    Node(int val);
};

class Queue
{
private:
    Node* first;
    Node* last;
    int length;

public:
    Queue(int val);
    ~Queue();
    void enqueue(int val);
    int dequeue();
    void printQueue();
};
