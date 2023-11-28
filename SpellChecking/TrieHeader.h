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

	void insert1( TrieNode* root, string word);
	bool search1(TrieNode* root, string key);
	string ConvertToLower(const std::string& str);
	

public:
	Trie();
	~Trie();
	Trie(const Trie& other);
	Trie& operator=(const Trie& other);
	void copyNodes(TrieNode* destination, TrieNode* source);
	void deleteNode(TrieNode* node);
	void deleteWord(string word);
	void insert(string word);
	bool search(string key);
	void printSuggestions(TrieNode* root, string res);
};
