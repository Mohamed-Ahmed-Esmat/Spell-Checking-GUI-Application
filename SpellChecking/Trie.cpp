#include <iostream>
#include "TrieHeader.h"
using namespace std;


//Constructor
Trie::Trie()
{
	root = new TrieNode();
    //Testing
}

//Destructor
Trie::~Trie()
{
    for (int i = 0; i < maxSize; i++) {
        if(root->children[i] != NULL)
            delete root->children[i];
        else
        	continue;
    }
    delete root;
}

void Trie::insert(string word, TrieNode* root)
{
    TrieNode* temp = root;
    for (int i = 0; i < word.length(); i++)
    {
        if (temp->children[word[i]] == NULL)
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

        if (root->children[key[i]] == NULL) {
            printSuggestions(root, key.substr(0, i));
            return false;
        }
        //if present -> switch to the next character

        root = root->children[key[i]];
    }
    if (root->isEnd == true) {
        return true;
    }
}
