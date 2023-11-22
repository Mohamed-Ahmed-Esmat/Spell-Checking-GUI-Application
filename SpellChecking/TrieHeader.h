#pragma once
#include <iostream>
using namespace std;

const int maxSize = 256;

class Trie
{
private:
	class TrieNode
	{
	public:
		TrieNode* children[maxSize];
		bool isEnd;

		// Constructor
		TrieNode()
		{
			isEnd = false;
			for (int i = 0; i < maxSize; i++)
				children[i] = NULL;
		}
	};

	TrieNode* root;

public:
	Trie();
	~Trie();
	TrieNode* getRoot();
	void deleteNode(TrieNode* node);
	void deleteWord(string word);
	void insert(string word, TrieNode* root);
	bool search(TrieNode* root, string key);
	void printSuggestions(TrieNode* root, string res);
};
