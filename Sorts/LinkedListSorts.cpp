#include <iostream>
#include <initializer_list>

struct Node
{
public:
    int value;
    Node* next;

    Node(int val) : value(val), next(nullptr) {}
};

class LinkedList
{
private:
    int size;
    Node* head;
    Node* tail;

public:
    LinkedList() : size(0), head(nullptr) {}

    LinkedList(int val) : size(1)
    {
        Node* newNode{ new Node(val) };
        head = newNode;
        tail = newNode;
    }

    LinkedList(std::initializer_list<int> vals) : size(0), head(nullptr), tail(nullptr)
    {
        for (int val : vals)
        {
            this->push(val);
        }
    }

    ~LinkedList()
    {
        Node* temp;
        tail = nullptr;
        while (head)
        {
            temp = head->next;
            delete head;
            head = temp;
        }
    }

    void push(int val)
    {
        Node* newNode{ new Node(val) };
        if (size == 0)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
        size++;
    }

    int at(int index)
    {
        if (index >= 0 && index < size)
        {
            Node* temp{ head };
            for (int i{ 0 }; i < index; i++) temp = temp->next;
            return temp->value;
        }
        return INT_MIN;
    }

    bool swap(int index1, int index2)
    {
        if (index1 != index2 && (index1 >= 0 && index1 < size) && (index2 >= 0 && index2 < size))
        {
            Node* node1{ head };
            Node* node2{ head };

            for (int i{ 0 }; i < index1; i++)
            {
                node1 = node1->next;
            }

            for (int i{ 0 }; i < index2; i++)
            {
                node2 = node2->next;
            }
            
            int temp{ node1->value };
            node1->value = node2->value;
            node2->value = temp;
            return true;
        }
        return false;
    }

    void printLinkedList()
    {
        Node* temp{ head };

        for (int i{ 0 }; i < size; i++)
        {
            std::cout << temp->value << ' ';
            temp = temp->next;
        }
        std::cout << '\n';
    }

    int getSize() { return size; }
};

std::ostream& operator<<(std::ostream& os, LinkedList& linkedList)
{
    linkedList.printLinkedList();
    return os;
}

void bubbleSort(LinkedList& linkedList)
{
    for (int i{ 0 }; i < linkedList.getSize() - 1; i++)
    {
        for (int j{ i }; j < linkedList.getSize() - 1; j++)
        {
            if (linkedList.at(j) > linkedList.at(j + 1)) linkedList.swap(j, j + 1);
        }
    }
}

void selectionSort(LinkedList& linkedList)
{
    for (int i{0}; i < linkedList.getSize() - 1; i++)
    {
        int minValueIndex{ i };
        for (int j{ i + 1 }; j < linkedList.getSize(); j++)
        {
            if (linkedList.at(minValueIndex) > linkedList.at(j)) minValueIndex = j;
        }
        
        if (linkedList.at(minValueIndex) < linkedList.at(i)) linkedList.swap(i, minValueIndex);
    }
}

void insertionSort(LinkedList& linkedList)
{
    for (int i{ 1 }; i < linkedList.getSize(); i++)
    {
        for (int j{ i }; j > 0 && linkedList.at(j) < linkedList.at(j - 1); j--)
        {
            linkedList.swap(j, j - 1);
        }
    }
}

int main()
{
    LinkedList myLL({1, 4, 2, 5, 6, 7});
    insertionSort(myLL);
    std::cout << myLL;
}