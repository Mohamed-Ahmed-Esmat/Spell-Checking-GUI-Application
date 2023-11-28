#include <iostream>
#include "TrieHeader.h"
using namespace std;


//Constructor
Trie::Trie()
{
    root = new TrieNode();
}

Trie::TrieNode* Trie::getRoot()
{
    return root;
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
    if (search(root, word)) {
        for (int i = 0; i < word.length(); i++) {
            currentChar = word[i];
            temp = temp->children[currentChar];
        }
        temp->isEnd = false;
    }
    else cout << "Word not available\n";
}


void Trie::insert(string word, TrieNode* root)
{
    TrieNode* temp = root;
    for (int i = 0; i < word.length(); i++)
    {
        if (temp->children[word[i]] == nullptr)
            temp->children[word[i]] = new TrieNode;
        temp = temp->children[word[i]];
    }
    temp->isEnd = true;
}

bool Trie::search(TrieNode* root, string key)
{
    cout << "Searching for " << key << endl;
    for (int i = 0; i < key.length(); i++) {

        if (root->children[key[i]] == nullptr) {

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
