#include <iostream>
#include <algorithm>
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
    transform(word.begin(), word.end(), word.begin(), ::tolower);

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
    transform(key.begin(), key.end(), key.begin(), ::tolower);
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
