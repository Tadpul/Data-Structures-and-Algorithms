#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <stack>

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

bool itemInCommon(std::vector<int> vector1, std::vector<int> vector2)
{
    std::unordered_map<int, bool> cppHT;

    for (int number : vector1)
    {
        cppHT.insert({number, true});
    }

    for (int number: vector2)
    {
        if (cppHT[number]) std::cout << "these 2 lists share a value\n";  
        return true;
    }
    return false;
}

std::vector<int> findDuplicates(const std::vector<int>& numVector)
{
    std::unordered_map<int, bool> numHT;
    std::vector<int> dupVector;

    for (int num : numVector)
    {
        if (numHT.find(num) != numHT.end())
        {
            dupVector.push_back(num);
            std::cout << num << " has been added to duplicate list\n";
        }
        else
        {
            numHT.insert({num, true});
        }
    }
    return dupVector;
}

char firstNonRepeatingChar(const std::string& input_string)
{
    std::unordered_map<char, int> charCounter;
    for (char letter : input_string) { charCounter[letter]++; }
    for (const auto& iterator : charCounter)
    {
        std::cout << iterator.first << ", " << iterator.second << '\n';
    }
    
    for (char letter : input_string)
    {
        if (charCounter[letter] == 1) return letter;
    }
}

std::ostream& operator<<(std::ostream& os, const std::vector<int>& vect)
{
    std::cout << "{ ";
    for (int num : vect) { std::cout << num << ' '; }
    std::cout << "}\n";
    return os;
}

std::vector<std::vector<std::string>> groupAnagrams(const std::vector<std::string>& strings)
{
    std::unordered_map<std::string, std::vector<std::string>> anagramMap;
    // orders string and adds it to the anagram, then adds the unordered aspect to the ordered string
    for (std::string string : strings)
    {
        std::string orderedString{ "" };
        std::stack<char> unorderedStack;
        std::stack<char> tempStack;

        // adds the unordered letters to unordered stack
        for (char letter : string) { unorderedStack.push(letter); }

        // reorders the leltters in the temporary stack
        while (!unorderedStack.empty())
        {
            char temp;
            temp = unorderedStack.top();
            unorderedStack.pop();

            while (!tempStack.empty() && tempStack.top() > temp)
            {
                unorderedStack.push(tempStack.top());
                tempStack.pop();
            }
            tempStack.push(temp);
        }

        // moves ordered letters from the ordered stack to the ordered string 
        while (!tempStack.empty())
        {
            orderedString += tempStack.top();
            tempStack.pop();
        }

        // adds the unordered string to the ordered string as a vector.
        anagramMap[orderedString].push_back(string);
    }

    std::vector<std::vector<std::string>> anagramVector;
    for (const auto& node : anagramMap)
    {
        anagramVector.push_back(node.second);
        for (const std::string word : node.second)
        {
            std::cout << word << ' ';
        }
        std::cout << '\n';
    }
    return anagramVector;
}

int main()
{
    std::vector<std::string> anagram = {"eat", "tea", "tan", "ate", "nat", "bat"};
    groupAnagrams(anagram);
}