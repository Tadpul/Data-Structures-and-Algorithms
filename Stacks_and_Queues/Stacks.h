#pragma once

#include <iostream>

struct Node
{
    int value;
    Node* next;

    Node(int val);
};

class Stack
{
private:
    Node* top;
    int height;

public:
    Stack();
    Stack(int value);
    ~Stack();
    void push(int val);
    int pop();
    int peek();
    int getHeight();
    bool isEmpty();
    void printStack();
};

void sortStack(Stack& inputStack);

std::ostream& operator<<(std::ostream& os, Stack& stackType);
