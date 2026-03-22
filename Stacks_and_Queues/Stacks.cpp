#include "Stacks.h"
#include <iostream>

// node constructor
Node::Node(int val) : value(val), next(nullptr) {}

// stack constructors
Stack::Stack() : top(nullptr), height(0) {}

Stack::Stack(int value) : top(new Node(value)), height(1) {}

// stack destructor
Stack::~Stack()    
{
    while (top)
    {
        Node* temp = top;
        top = top->next;
        delete temp;
    }
}

// stack member functions
void Stack::push(int val)
{
    Node* newNode{ new Node(val) };
    newNode->next = top;
    top = newNode;
    height++;
}

int Stack::pop()
{
    if (top == nullptr) return INT_MIN;

    int val = top->value;
    Node* temp{top->next};
    delete top;
    top = temp;
    height--;
    return val;
}

int Stack::peek() { return top->value; }

int Stack::getHeight() { return height; }

bool Stack::isEmpty()
{
    if (!top) { return true; }
    else { return false; }
}

void Stack::printStack()
{
    Node* temp{ top };
    while (temp)
    {
        std::cout << temp->value;
        temp = temp->next;
    }
    std::cout << '\n';  
}

// stack sort function
void sortStack(Stack& inputStack)
{
    Stack tempStack;
    int temp;

    while (!inputStack.isEmpty())
    {
        temp = inputStack.pop();
        if (!tempStack.isEmpty() && (tempStack.peek() > temp))
        {
            inputStack.push(tempStack.pop());
        }

        tempStack.push(temp);
    }

    while (!tempStack.isEmpty())
    {
        inputStack.push(tempStack.pop());
    }
}

// operator overload
std::ostream& operator<<(std::ostream& os, Stack& stackType)
{
    stackType.printStack();
    return os;
}
