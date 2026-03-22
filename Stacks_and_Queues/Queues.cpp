#include "Queues.h"
#include <iostream>
#include <climits>

// node constructor
Node::Node(int val) : value(val), next(nullptr) {} 

// queue constructor
Queue::Queue(int val)
    : length(1) 
{
    Node* newNode{ new Node(val) };
    first = newNode;
    last = newNode;
}

// queue destructor
Queue::~Queue()
{
    Node* temp;

    while (first)
    {
        temp = first;
        first = temp->next;
        delete temp;
    }
}

// queue member functions
void Queue::enqueue(int val)
{
    Node* newNode{ new Node(val) };
    if (first == nullptr)
    {
        first = newNode;
    }
    else
    {
        last->next = newNode;
        last = newNode;
    }
    last = newNode;
    length++;
}

int Queue::dequeue()
{
    if (first == nullptr)
    {
        return INT_MIN;
    }

    int dequeuedValue = first->value;
    if(length == 1)
    {
        delete first;
        first = nullptr;
        last = nullptr;
    }
    else
    {
        Node* temp = first->next;
        delete first;
        first = temp;
    }
    length--;
    return dequeuedValue;
}

void Queue::printQueue()
{
    Node* temp{ first };
    while (temp)
    {
        std::cout << temp->value;
        temp = temp->next;
    }
    std::cout << '\n';
}
