#include <iostream>
#include "TrieHeader.h"
using namespace std;


//Constructor
Trie::Trie()
{
    root = new TrieNode();
}

//Destructor
Trie::~Trie()
{
    deleteNode(root);
    delete root;
}
// Copy Constructor
Trie::Trie(const Trie& other) {
    root = new TrieNode();
    copyNodes(root, other.root);
}
//  function for deep copy of nodes
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

// Overloading the assignment operator
Trie& Trie::operator=(const Trie& other) {
    if (this != &other) { 
        this->~Trie();
        root = new TrieNode();
        copyNodes(root, other.root);
    }
    return *this;
}

void Trie::deleteNode(TrieNode* node)
{
    for (int i = 0; i < maxSize; i++) {
        if (node->children[i] != nullptr) {
            deleteNode(node->children[i]);
            delete node->children[i];
        }
    }
}

void Trie::deleteWord(string word) {
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

void Trie::insert(string word) {
    return insert1(root, word);
}

void Trie::insert1(TrieNode* root, string word) {
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


bool Trie::search(string key)
{
    return search1(root, key);
}

bool Trie::search1(TrieNode* root, string key)
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

void Trie::printSuggestions(TrieNode* root, string res)
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

string Trie::ConvertToLower(const std::string& str) {
    std::string lowercaseStr = str;

    for (char& c : lowercaseStr) {
        if (c >= 'A' && c <= 'Z') {
            c = c - 'A' + 'a';
        }
    }

    return lowercaseStr;
}
