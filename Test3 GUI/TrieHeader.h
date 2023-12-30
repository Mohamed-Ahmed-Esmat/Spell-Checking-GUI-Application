#pragma once
#include <iostream>
#include <algorithm>
using namespace std;

const int numChildren = 26;

template <typename DataType>
class Trie
{
private:
    class TrieNode
    {
    public:
        TrieNode* children[numChildren];
        bool isEnd;
        int frequency;

        // Constructor
        TrieNode()
        {
            isEnd = false;
            frequency = 0;
            for (int i = 0; i < numChildren; i++)
                children[i] = nullptr;
        }
    };

    TrieNode* root;

    int currentElements;
    void getWord(TrieNode* temp, DataType currentWord, DataType words[], int& index) const;
    DataType ConvertToLower(const DataType& str);

public:
    Trie();
    ~Trie();
    DataType* getAllWords(int& index) const;
    Trie(const Trie& other);
    bool isEmpty() const;
    Trie& operator=(const Trie& other);
    Trie& operator+(const Trie& other);
    void displayWords(ostream& out, TrieNode* node, DataType currentWord) const;
    void displayAllWords(ostream& out) const;
    void copyNodes(TrieNode* destination, TrieNode* source);
    void deleteNode(TrieNode* node);
    void clear();
    bool deleteWord(DataType word);
    bool insert(DataType word);
    bool search(DataType key);
    void findAllWords(TrieNode* temp, DataType currentWord, int& suggestionsCount, DataType suggestions[]) const;
    void printSuggestions(TrieNode* temp, DataType currentWord, int& suggestionsCount, DataType top3words[]) const;
    void printSuggestions1(DataType currentWord, int& suggestionsCount, DataType top3words[]);

};

template <typename DataType>
ostream& operator<<(ostream& out, const Trie<DataType>& trie);
