#include "HashTables.h"
#include <unordered_map>
#include <stack>
#include <unordered_set>

// node constructor
Node::Node(std::string stringKey, int val) : key(stringKey), value(val), next(nullptr) {}  

// hash table constructor
HashTable::HashTable()
{
    for (int i{ 0 }; i < SIZE; i++)
    {
        dataMap[i] = nullptr;
    }
}

// hash table member functions
int HashTable::hash(std::string key)
{
    int hash{ 0 };
    for (char letter : key)
    {
        int asciiValue{ int(letter) };
        hash = (hash + int(asciiValue) * 23) % SIZE;
    }
    return hash;
}

void HashTable::setNode(std::string key, int val)
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

int HashTable::getValue(std::string key) 
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

std::vector<std::string> HashTable::keys()
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

void HashTable::printHashTable()
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

// other hash table related functions
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

std::vector<int> twoSum(const std::vector<int>& numbers, int target) 
{
    std::unordered_map<int, int> targetMap;

    for (int i{ 0 }; i < numbers.size(); i++)
    {
        int thisNumber = numbers[i];
        int complement = target - thisNumber;

        if (targetMap.find(complement) != targetMap.end())
        {
            return {targetMap[complement], i};
        }
        targetMap[thisNumber] = i;
    }
    return {};
}

std::vector<int> subarraySum(std::vector<int> nums, int target)
{
    std::unordered_map<int, int> sumMap;
    int currentSum{ 0 };

    sumMap[0] = -1;

    for (std::size_t i{ 0 }; i < nums.size(); i++)
    {
        currentSum += nums[i];
        int complement = currentSum - target;

        if (sumMap.find(complement) != sumMap.end())
        {
            return {sumMap[complement] + 1, (int)i};
        }
        sumMap[currentSum] = (int)i;
    }
    return {};
}

std::vector<int> removeDuplicates(const std::vector<int>& myList)
{
    std::unordered_set<int> set{ myList.begin(), myList.end() };
    std::vector<int> returnVector{ set.begin(), set.end() };
    return returnVector;
}

std::vector<std::vector<int>> findPairs(const std::vector<int>& arr1, const std::vector<int>& arr2, int target) 
{
    std::vector<std::vector<int>> pairVector;
    std::unordered_set<int> set1{ arr1.begin(), arr1.end() };
    for (int number : arr2)
    {
        int complement{ target - number };
        if (set1.find(complement) != set1.end()) pairVector.push_back({number, complement});
    }
    return pairVector;
}

int longestConsecutiveSequence(const std::vector<int>& nums)
{
    int longest{ 0 };
    std::unordered_set<int> numSet{ nums.begin(), nums.end() };
    
    for (int number : numSet)
    {
        if (numSet.find(number - 1) == numSet.end())
        {
            int currentLongest{ 0 };
            int newNumber{ number };
            while (numSet.find(newNumber) != numSet.end())
            {
                newNumber++;
                currentLongest++;
            }
            if (currentLongest > longest) longest = currentLongest;
        }
    }
    return longest;
}
