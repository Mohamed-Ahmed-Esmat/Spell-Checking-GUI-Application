#include <iostream>
#include "TrieHeader.h"
using namespace std;


template <typename DataType>
Trie<DataType>::Trie() : maxElements(500)
{
    root = new TrieNode();
}

template<typename DataType>
Trie<DataType>::Trie(int maxElements) : maxElements(maxElements)
{
    root = new TrieNode();
}


template <typename DataType>
Trie<DataType>::~Trie()
{
    deleteNode(root);
    delete root;
}

template <typename DataType>
Trie<DataType>::Trie(const Trie<DataType>& other)
{
    root = new TrieNode();
    copyNodes(root, other.root);
}

template <typename DataType>
void Trie<DataType>::copyNodes(TrieNode* destination, TrieNode* source)
{
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
Trie<DataType>& Trie<DataType>::operator=(const Trie<DataType>& other)
{
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
bool Trie<DataType>::isEmpty() const {
    for (int i = 0; i < maxSize; i++) {
        if (root->children[i] != nullptr) {
            return false;
        }
    }
    return true;
}

template <typename DataType>
void Trie<DataType>::deleteWord(DataType word)
{
    TrieNode* temp = root;
    if (temp == nullptr) {
        cout << "Trie is empty\n";
        return;
    }
    char currentChar;
    if (search1(root, word)) {
        cout << "Delete " << word;
        for (int i = 0; i < word.length(); i++) {
            currentChar = word[i];
            temp = temp->children[currentChar];
        }
        temp->isEnd = false;
    }
    else
        cout << "Word not available\n";
}

template <typename DataType>
void Trie<DataType>::insert(DataType word)
{
    return insert1(root, word);
}

template <typename DataType>
void Trie<DataType>::insert1(TrieNode* root, DataType word)
{
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
    string* words = new string[maxElements];
    cout << "Words stored in the trie:\n";
    string currentWord;
    int index = 0;
    getWord(root, currentWord, words, index);
    cout << endl;
    return words;
}

template <typename DataType>
void Trie<DataType>::getWord(TrieNode* root, DataType currentWord, DataType words[], int& index) const
{
    if (root->isEnd) {
        cout << index << " " << currentWord << " " << endl;
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
template class Trie<int>;