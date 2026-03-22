#include "LinkedListSorts.h"
#include <climits>

// node constructor
Node::Node(int val) : value(val), next(nullptr) {}

// linked list constructor
LinkedList::LinkedList() : size(0), head(nullptr) {}

LinkedList::LinkedList(int val) : size(1)
    {
        Node* newNode{ new Node(val) };
        head = newNode;
        tail = newNode;
    }

LinkedList::LinkedList(std::initializer_list<int> vals) : size(0), head(nullptr), tail(nullptr)
    {
        for (int val : vals)
        {
            this->push(val);
        }
    }

// destructor
LinkedList::~LinkedList()
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

// methods
void LinkedList::push(int val)
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

int LinkedList::at(int index)
    {
        if (index >= 0 && index < size)
        {
            Node* temp{ head };
            for (int i{ 0 }; i < index; i++) temp = temp->next;
            return temp->value;
        }
        return INT_MIN;
    }

bool LinkedList::swap(int index1, int index2)
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

void LinkedList::printLinkedList()
    {
        Node* temp{ head };

        for (int i{ 0 }; i < size; i++)
        {
            std::cout << temp->value << ' ';
            temp = temp->next;
        }
        std::cout << '\n';
    }

int LinkedList::getSize() { return size; }

// operator overload
std::ostream& operator<<(std::ostream& os, LinkedList& linkedList)
{
    linkedList.printLinkedList();
    return os;
}

// sorting algorithms
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

