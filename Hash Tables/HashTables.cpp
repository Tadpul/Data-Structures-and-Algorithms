#include <iostream>
#include <string>

class Node
{
public:
    std::string key;
    int value;
    Node* next;

    Node(std::string stringKey, int val) : key(stringKey), value(val), next(nullptr) {}  
};

class HashTable
{
private:
    static const int SIZE{ 7 };
    Node* dataMap[SIZE];

public:
    void printHashTable()
    {
        for (int i{ 0 }; i < SIZE; i++)
        {
            std::cout << 1 << ": ";
            if (dataMap[i])
            {
                Node* temp = dataMap[i];
                while (temp)
                {
                    std::cout << "{ " << temp->key << ", " << temp->value << " }\n";
                    temp = temp->next;
                }
                
            }
        }
    }
};