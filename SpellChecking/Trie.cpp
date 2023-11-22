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
//Function to search for a word in the Trie
bool Trie::search(TrieNode* root, string key)
{

    for (int i = 0; i < key.length(); i++) {

        // If current character is not present in the Trie-> make suggestions
        if (root->children[key[i]] == nullptr) {
            //printSuggestions(root, key.substr(0, i));
            return false;
        }
        //if present -> switch to the next character

        root = root->children[key[i]];
    }
    if (root->isEnd == true) {
        return true;
    }
    else {
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
