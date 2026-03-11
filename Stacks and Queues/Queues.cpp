#include <iostream>
#include <climits>

struct Node
{
public:
    int value;
    Node* next;

    Node(int val) : value(val), next(nullptr) {} 
};

class Queue
{
private:
    Node* first;
    Node* last;
    int length;

public:
    Queue(int val)
        : length(1) 
    {
        Node* newNode{ new Node(val) };
        first = newNode;
        last = newNode;
    }

    ~Queue()
    {
        Node* temp{ nullptr };
        Node* tempAfter{ first };
        first = nullptr;

        while (tempAfter)
        {
            temp = tempAfter;
            tempAfter = temp->next;

            delete temp;
        }
    }

    void enqueue(int val)
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

    int dequeue()
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

    void printQueue()
    {
        Node* temp{ first };
        while (temp)
        {
            std::cout << temp->value;
            temp = temp->next;
        }
        std::cout << '\n';
    }
};

int main()
{
    Queue myQueue{ 1 };
    myQueue.enqueue(4);
    myQueue.printQueue();
    myQueue.dequeue();
    myQueue.printQueue();
}
