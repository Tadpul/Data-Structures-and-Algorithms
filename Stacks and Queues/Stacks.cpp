#include <iostream>

struct Node
{
    int value;
    Node* next;

    Node(int val) : value(val), next(nullptr) {}
};


class Stack
{
private:
    Node* top;
    int height;

public:
    Stack() : top(nullptr), height(0) {}

    Stack(int value) : top(new Node(value)), height(1) {}

    ~Stack()
    {
        while (top)
        {
            Node* temp = top;
            top = top->next;
            delete temp;
        }
    }

    void push(int val)
    {
        Node* newNode{ new Node(val) };
        newNode->next = top;
        top = newNode;
        height++;
    }

    int pop()
    {
        if (top == nullptr) return INT_MIN;

        int val = top->value;
        Node* temp{top->next};
        delete top;
        top = temp;
        height--;
        return val;
    }

    int peek() { return top->value; }

    int getHeight() { return height; }

    bool isEmpty()
    {
        if (!top) { return true; }
        else { return false; }
    }

    void printStack()
    {
        Node* temp{ top };
        while (temp)
        {
            std::cout << temp->value;
            temp = temp->next;
        }
        std::cout << '\n';  
    }
};

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

std::ostream& operator<<(std::ostream& os, Stack& stackType)
{
    stackType.printStack();
    return os;
}

int main()
{
    
}
