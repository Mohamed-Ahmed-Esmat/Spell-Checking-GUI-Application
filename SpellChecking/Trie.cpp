#include <iostream>
#include "TrieHeader.h"
using namespace std;

template <typename DataType>
Trie<DataType>::Trie() : maxElements(100), currentElements(0) {
    root = new TrieNode();
}

template <typename DataType>
Trie<DataType>::Trie(int maxElements) : maxElements(maxElements), currentElements(0) {
    root = new TrieNode();
}

template <typename DataType>
Trie<DataType>::~Trie() {
    deleteNode(root);
    delete root;
}

template <typename DataType>
Trie<DataType>::Trie(const Trie<DataType>& other) {
    root = new TrieNode();
    copyNodes(root, other.root);
}

template <typename DataType>
void Trie<DataType>::copyNodes(TrieNode* destination, TrieNode* source) {
    if (source->isEnd) {
        destination->isEnd = true;
    }

    for (int i = 0; i < maxSize; i++) {
        if (source->children[i] != nullptr) {
            destination->children[i] = new TrieNode();
            copyNodes(destination->children[i], source->children[i]);
        }
    }
}

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
void Trie<DataType>::deleteNode(TrieNode* node) {
    for (int i = 0; i < maxSize; i++) {
        if (node->children[i] != nullptr) {
            deleteNode(node->children[i]);
            delete node->children[i];
        }
    }
}

template <typename DataType>
bool Trie<DataType>::isEmpty() const {
    return currentElements == 0;
}

template <typename DataType>
void Trie<DataType>::deleteWord(DataType word) {

    TrieNode* temp = root;
    if (isEmpty()) {
        cout << "Trie is empty\n";
        return;
    }
    char currentChar;
    if (search(word)) {
        cout << "Delete " << word << endl;
        for (int i = 0; i < word.length(); i++) {
            currentChar = word[i];
            temp = temp->children[currentChar];
        }
        temp->isEnd = false;
        currentElements--;
    }
    else
        cout << "Word not available\n";
}

template <typename DataType>
void Trie<DataType>::insert(DataType word) {
    if (currentElements == maxElements) {
        cerr << "---Maximum number of elements reached. Can't insert----" << endl;
        return;
    }
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
        currentElements++;
    }
}

template <typename DataType>
bool Trie<DataType>::search(DataType key)
{
    TrieNode* temp = root;
    cout << "Searching for " << key << endl;
    key = ConvertToLower(key);

    for (int i = 0; i < key.length(); i++) {
        if (temp->children[key[i]] == nullptr) {
            cout << "Word not found\n";
            return false;
        }
        temp = temp->children[key[i]];
    }
    if (temp->isEnd == true) {
        cout << "Word found\n";
        return true;
    }
    else {
        cout << "Word not found\n";
        cout << "Suggestions: " << endl;
        printSuggestions(temp, key);
        cout << endl;
        return false;
    }
}

template <typename DataType>
void Trie<DataType>::printSuggestions(TrieNode* temp, DataType currentWord) const
{
    if (temp->isEnd == true) {
        cout << currentWord << " ";
    }

    for (int i = 0; i < 256; i++) {
        if (temp->children[i] != nullptr) {
            DataType nextWord = currentWord + static_cast<char>(i);
            printSuggestions(temp->children[i], nextWord);
        }
    }
}

template <typename DataType>
DataType Trie<DataType>::ConvertToLower(const DataType& str)
{
    DataType lowercaseStr = str;

    for (char& c : lowercaseStr) {
        if (c >= 'A' && c <= 'Z') {
            c = c - 'A' + 'a';
        }
    }

    return lowercaseStr;
}

template <typename DataType>
ostream& operator<<(ostream& out, const Trie<DataType>& trie)
{
    trie.displayAllWords(out);
    return out;
}

template <typename DataType>
void Trie<DataType>::displayAllWords(ostream& out) const
{
    DataType currentWord = "";
    displayWords(out, root, currentWord);
}

template <typename DataType>
void Trie<DataType>::displayWords(ostream& out, TrieNode* node, DataType currentWord) const
{
    if (node == nullptr) {
        return;
    }

    if (node->isEnd) {
        out << currentWord << endl;
    }

    for (int i = 0; i < maxSize; ++i) {
        if (node->children[i] != nullptr) {
            DataType nextWord = currentWord + static_cast<char>(i);
            displayWords(out, node->children[i], nextWord);
        }
    }
}

template <typename DataType>
Trie<DataType>& Trie<DataType>::operator+(const Trie<DataType>& other)
{
    if (this == &other || other.isEmpty())
        return *this;
    DataType* words = other.getAllWords();
    int length = 0;
    while (words[length] != "") {
        length++;
    }
    for (int i = 0; i < length; i++) {
        insert(words[i]);
    }
    delete[] words;
    return *this;
}
template <typename DataType>
DataType* Trie<DataType>::getAllWords() const {
    DataType* words = new DataType[maxElements];
    DataType currentWord;
    int index = 0;
    getWord(root, currentWord, words, index);
    cout << endl;
    return words;
}

template <typename DataType>
void Trie<DataType>::getWord(TrieNode* root, DataType currentWord, DataType words[], int& index) const
{
    if (root->isEnd) {
        words[index++] = currentWord;
    }

    for (int i = 0; i < 256; i++) {
        if (root->children[i] != nullptr) {
            getWord(root->children[i], currentWord + static_cast<char>(i), words, index);
        }
    }
}




template ostream& operator<<(ostream& out, const Trie<string>& trie);
template class Trie<string>;