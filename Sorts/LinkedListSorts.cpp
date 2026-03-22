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

void LinkedList::changeValueAt(int index, int value)
{
    if (index >= 0 && index < size)
    {
        Node* temp{ head };
        for (int i{ 0 }; i < index; i++)
        {
            temp = temp->next;
        }
        temp->value = value;
    }
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

void merge(LinkedList& linkedList, int leftIndex, int middleIndex, int rightIndex)
{
    LinkedList leftList;
    LinkedList rightList;

    int leftListSize{ middleIndex - leftIndex + 1 };
    int rightListSize{ rightIndex - middleIndex };
    
    for (int i{ leftIndex }; i <= middleIndex; i++)
    {
        leftList.push(linkedList.at(i));
    }

    for (int j{ middleIndex + 1}; j <= rightIndex; j++)
    {
        rightList.push(linkedList.at(j));
    }

    int i{ 0 };
    int j{ 0 };
    int index{ leftIndex };
    while (i < leftListSize && j < rightListSize)
    {
        if (leftList.at(i) < rightList.at(j))
        {
            linkedList.changeValueAt(index, leftList.at(i));
            index++;
            i++;
        }
        else
        {
            linkedList.changeValueAt(index, rightList.at(j));
            index++;
            j++;
        }
    }

    while (i < leftListSize)
    {
        linkedList.changeValueAt(index, leftList.at(i));
        index++;
        i++;
    }
    while (j < rightListSize)
    {
        linkedList.changeValueAt(index, rightList.at(j));
        index++;
        j++;
    }
}

void mergeSort(LinkedList& linkedList, int leftIndex, int rightindex)
{
    if (leftIndex == rightindex) return;

    int middleIndex = leftIndex + (rightindex - leftIndex) / 2;
    mergeSort(linkedList, leftIndex, middleIndex);
    mergeSort(linkedList, middleIndex + 1, rightindex);

    merge(linkedList, leftIndex, middleIndex, rightindex);
}

int main()
{
    LinkedList myLL({2, 4, 1, 5, 6, 3, 6, 7});
    mergeSort(myLL, 0, myLL.getSize() - 1);

    myLL.printLinkedList();
}