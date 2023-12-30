#include <iostream>
#include <string>
#include "TrieHeader.h"
using namespace std;

template <typename DataType>
Trie<DataType>::Trie() : currentElements(0) {
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

    for (int i = 0; i < numChildren; i++) {
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
    for (int i = 0; i < numChildren; i++) {
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
bool Trie<DataType>::deleteWord(DataType word) {

    TrieNode* temp = root;
    if (isEmpty()) {
        cout << "Trie is empty\n";
        return false;
    }

    if (!search(word)) {
        cout << "Word not available\n";
        return false;
    }

    cout << "Delete " << word << endl;

    for (char c : word) {
        int index = c - 'a'; // Calculate index based on the character 'a'

        if (temp->children[index] == nullptr) {
            cout << "Word not found in the Trie\n";
            return false;
        }
        temp = temp->children[index]; // Move to the next node
    }

    temp->isEnd = false; // Mark the last node as not the end of the word
    temp->frequency = 0;
    currentElements--;   // Decrement the count of elements in the Trie
    return true;
}

template <typename DataType>
bool Trie<DataType>::insert(DataType word) {
    if (word.empty()) {
        cout << "Empty word cannot be inserted into the Trie\n";
        return false;
    }

    word = ConvertToLower(word);

    TrieNode* temp = root;

    for (char c : word) {
        int index = c - 'a'; // Calculate index based on the character 'a'

        if (index < 0 || index >= numChildren) {
            cout << "Invalid character found in the word: " << c << endl;
            return false;
        }

        if (temp->children[index] == nullptr) {
            temp->children[index] = new TrieNode(); // Create new node if it doesn't exist
        }

        temp = temp->children[index]; // Move to the next node
    }
    if (temp->isEnd)
    {
        temp->frequency++;
    }
    else {
        temp->isEnd = true; // Mark the last node as the end of the word
        temp->frequency++;
        currentElements++;  // Update the count of elements in the Trie
    }
    return true;
}



template <typename DataType>
bool Trie<DataType>::search(DataType key)
{
    TrieNode* temp = root;
    cout << "Searching for " << key << endl;
    key = ConvertToLower(key);


    for (int i = 0; i < key.length(); i++) {
        if (temp->children[key[i] - 'a'] == nullptr) {
            cout << "Word not found\n";
            return false;
        }
        temp = temp->children[key[i] - 'a'];
    }

    if (temp->isEnd) {
        return true;
    }
    else {
        return false;
    }
}

template <typename DataType>
void Trie<DataType>::findAllWords(TrieNode* temp, DataType currentWord, int& suggestionsCount, DataType suggestions[]) const
{
    if (temp->isEnd == true) {
        suggestions[suggestionsCount++] = currentWord + " " + to_string(temp->frequency);
    }

    for (int i = 0; i < 26; i++) {
        if (temp->children[i] != nullptr) {
            char c = 'a' + i;
            findAllWords(temp->children[i], currentWord + c, suggestionsCount, suggestions);
        }
    }
}

template <typename DataType>
void Trie<DataType>::printSuggestions(TrieNode* temp, DataType currentWord, DataType top3words[]) const
{
    const int maxSuggestions = 10000;
    DataType suggestions[maxSuggestions];
    int suggestionsCount = 0;
    findAllWords(temp, currentWord, suggestionsCount, suggestions);
    sort(suggestions, suggestions + suggestionsCount, [](const DataType& a, const DataType& b) {
        // Assuming suggestions are in the format "word frequency"
        return stoi(a.substr(a.find_last_of(' ') + 1)) > stoi(b.substr(b.find_last_of(' ') + 1));
        });
    for (int i = 0; i < min(3, suggestionsCount); i++) {
        int lastSpacePos = suggestions[i].find_last_of(' ');
        DataType wordPart = suggestions[i].substr(0, lastSpacePos);
        top3words[i] = wordPart;
    }
}

template <typename DataType>
void Trie<DataType>::printSuggestions1(DataType currentWord, DataType top3words[]) {
    TrieNode* temp = root;
    currentWord = ConvertToLower(currentWord);

    for (int i = 0; i < currentWord.length(); i++) {
        temp = temp->children[currentWord[i] - 'a'];
    }

    printSuggestions(temp, currentWord, top3words);
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

    for (int i = 0; i < numChildren; ++i) {
        if (node->children[i] != nullptr) {
            DataType nextWord = currentWord + static_cast<char>('a' + i);
            displayWords(out, node->children[i], nextWord);
        }
    }
}

template <typename DataType>
Trie<DataType>& Trie<DataType>::operator+(const Trie<DataType>& other)
{
    if (this == &other || other.isEmpty())
        return *this;
    int index = 0;
    DataType* words = other.getAllWords(index);
    for (int i = 0; i < index; i++) {
        insert(words[i]);
    }
    delete[] words;
    return *this;
}

template <typename DataType>
DataType* Trie<DataType>::getAllWords(int& index) const {
    DataType* words = new DataType[currentElements];
    DataType currentWord;
    getWord(root, currentWord, words, index);
    cout << endl;
    return words;
}

template <typename DataType>
void Trie<DataType>::getWord(TrieNode* temp, DataType currentWord, DataType words[], int& index) const
{
    if (temp == nullptr) {
        return;
    }
    if (temp->isEnd) {
        words[index++] = currentWord;
    }

    for (int i = 0; i < numChildren; i++) {
        if (temp->children[i] != nullptr) {
            DataType nextWord = currentWord + static_cast<char>('a' + i);
            getWord(temp->children[i], nextWord, words, index);
        }
    }
}


template ostream& operator<<(ostream& out, const Trie<string>& trie);
template class Trie<string>;
