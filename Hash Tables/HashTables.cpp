#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

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
    HashTable()
    {
        for (int i{ 0 }; i < SIZE; i++)
        {
            dataMap[i] = nullptr;
        }
    }

    void printHashTable()
    {
        for (int i{ 0 }; i < SIZE; i++)
        {
            if (dataMap[i])
            {
                Node* temp = dataMap[i];
                std::cout << i << ':';
                while (temp)
                {
                    std::cout << " { " << temp->key << ", " << temp->value << " }";
                    temp = temp->next;
                }
                std::cout << '\n';
            }
            else std::cout << i << ": empty\n"; 
        }
    }

    int hash(std::string key)
    {
        int hash{ 0 };
        for (char letter : key)
        {
            int asciiValue{ int(letter) };
            hash = (hash + int(asciiValue) * 23) % SIZE;
        }
        return hash;
    }

    void setNode(std::string key, int val)
    {
        Node* newNode(new Node(key, val));
        int index{ hash(key) };

        if (dataMap[index] == nullptr) dataMap[index] = newNode;
        else
        {
            Node* temp{ dataMap[index] };
            while (temp->next != nullptr)
            {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    int getValue(std::string key) 
    {
        int index = hash(key);
        if (dataMap[index])
        {
            Node* temp{dataMap[index]};
            while (temp)
            {
                if (temp->key == key) return temp->value;
                temp = temp->next;
            }
        }
        return INT_MIN;
    }

    std::vector<std::string> keys()
    {
        std::vector<std::string> keys;

        for (Node* node : dataMap)
        {
            Node* temp{ node }; 
            while (temp) 
            {
                keys.push_back(temp->key);
                temp = temp->next;
            }
        }
        return keys;
    }
};

int main()
{
    HashTable myHT;

    myHT.setNode("dildos", 10);
    myHT.setNode("dildos", 2);
    myHT.printHashTable();

    for (std::string key : myHT.keys())
    {
        std::cout << key << " ";
    }

    std::unordered_map<int, bool> cppHT;
    std::vector<int> vector1 = {1, 2, 3};
    std::vector<int> vector2 = {4, 5, 1};

    for (int number : vector1)
    {
        cppHT.insert({number, true});
    }

    for (int number: vector2)
    {
        if (cppHT[number]) std::cout << "these 2 lists share a value\n";  
    }

}