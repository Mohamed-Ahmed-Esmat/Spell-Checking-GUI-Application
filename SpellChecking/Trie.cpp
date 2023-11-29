#include <iostream>
#include "TrieHeader.h"
using namespace std;


//Constructor
template <typename DataType>
Trie<DataType>::Trie()
{
    root = new TrieNode();
}

//Destructor
template <typename DataType>
Trie<DataType>::~Trie()
{
    deleteNode(root);
    delete root;
}

// Copy Constructor
template <typename DataType>
Trie<DataType>::Trie(const Trie<DataType>& other) {
    root = new TrieNode();
    copyNodes(root, other.root);
}

//  function for deep copy of nodes
template <typename DataType>
void Trie::copyNodes(TrieNode* destination, TrieNode* source) {
    if (source->isEnd) {
        destination->isEnd = true;
    }

    for (int i = 0; i < maxSize; ++i) {
        if (source->children[i] != nullptr) {
            destination->children[i] = new TrieNode();
            copyNodes(destination->children[i], source->children[i]);
        }
    }
}

// Overloading the assignment
template <typename DataType>
Trie<DataType>& Trie<DataType>::operator=(const Trie<DataType>& other) {
    if (this != &other) { 
        this->~Trie();
        root = new TrieNode();
        copyNodes(root, other.root);
    }
    return *this;
}

template <typename DataType>
void Trie<DataType>::deleteNode(TrieNode* node)
{
    for (int i = 0; i < maxSize; i++) {
        if (node->children[i] != nullptr) {
            deleteNode(node->children[i]);
            delete node->children[i];
        }
    }
}

template <typename DataType>
void Trie<DataType>::deleteWord(DataType word) {
    TrieNode* temp = root;
    if (temp == nullptr) { cout << "Trie is empty\n"; return; }
    char currentChar;
    if (search1(root, word)) {
        cout << "Delete " << word;
        for (int i = 0; i < word.length(); i++) {
            currentChar = word[i];
            temp = temp->children[currentChar];
        }
        temp->isEnd = false;
    }
    else cout << "Word not available\n";
}

template <typename DataType>
void Trie<DataType>::insert(DataType word) {
    return insert1(root, word);
}

template <typename DataType>
void Trie<DataType>::insert1(TrieNode* root, DataType word) {
    word = ConvertToLower(word);

    TrieNode* temp = root;
    bool wordExists = true;

    for (int i = 0; i < word.length(); i++) {
        if (temp->children[word[i]] == nullptr) {
            temp->children[word[i]] = new TrieNode;
            wordExists = false;
        }
        temp = temp->children[word[i]];
    }

    if (wordExists && temp->isEnd) {
        cout << "Word already exists in the trie: " << word << endl;
    }
    else {
        temp->isEnd = true;

    }
}

template <typename DataType>
bool Trie<DataType>::search(DataType key)
{
    return search1(root, key);
}

template <typename DataType>
bool Trie<DataType>::search1(TrieNode* root, DataType key)
{
    cout << "Searching for " << key << endl;
    key = ConvertToLower(key);

    for (int i = 0; i < key.length(); i++) {
        if (root->children[key[i]] == nullptr) {
            cout << "Word not found\n";
            return false;
        }
        root = root->children[key[i]];
    }
    if (root->isEnd == true) {
        cout << "Word found\n";
        return true;
    }
    else {
        cout << "Word not found\n";
        cout << "Suggestions: " << endl;
        printSuggestions(root, key);
        cout << endl;
        return false;
    }
}

template <typename DataType>
void Trie<DataType>::printSuggestions(TrieNode* root, DataType res)
{
    if (root->isEnd == true) {
        cout << res << " ";
    }

    for (int i = 0; i < 256; i++) {
        if (root->children[i] != nullptr) {
            res.push_back(i);
            printSuggestions(root->children[i], res);
            res.pop_back();
        }
    }
}

template <typename DataType>
string Trie<DataType>::ConvertToLower(const std::DataType& str) {
    std::DataType lowercaseStr = str;

    for (char& c : lowercaseStr) {
        if (c >= 'A' && c <= 'Z') {
            c = c - 'A' + 'a';
        }
    }

    return lowercaseStr;
}
