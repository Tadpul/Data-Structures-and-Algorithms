#pragma once

#include <iostream>
#include <string>
#include <vector>

class Node
{
public:
    std::string key;
    int value;
    Node* next;

    Node(std::string stringKey, int val);
};

class HashTable
{
private:
    static constexpr int SIZE{ 7 };
    Node* dataMap[SIZE];

public:
    HashTable();
    int hash(std::string key);
    void setNode(std::string key, int val);
    int getValue(std::string key);
    std::vector<std::string> keys();
    void printHashTable();
};

bool itemInCommon(std::vector<int> vector1, std::vector<int> vector2);
std::vector<int> findDuplicates(const std::vector<int>& numVector);
char firstNonRepeatingChar(const std::string& input_string);
std::vector<std::vector<std::string>> groupAnagrams(const std::vector<std::string>& strings);
std::vector<int> twoSum(const std::vector<int>& numbers, int target);
std::vector<int> subarraySum(std::vector<int> nums, int target);
std::vector<int> removeDuplicates(const std::vector<int>& myList);
std::vector<std::vector<int>> findPairs(const std::vector<int>& arr1, const std::vector<int>& arr2, int target);
int longestConsecutiveSequence(const std::vector<int>& nums);

std::ostream& operator<<(std::ostream& os, const std::vector<int>& vect);
