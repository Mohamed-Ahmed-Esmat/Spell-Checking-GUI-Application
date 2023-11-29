#pragma once
#include <iostream>
using namespace std;

const int maxSize = 256;

template <typename DataType>
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

	void insert1( TrieNode* root, DataType word);
	bool search1(TrieNode* root, DataType key);
	string ConvertToLower(const std:: DataType& str);
	

public:
	Trie();
	~Trie();
	Trie(const Trie& other);
	Trie& operator=(const Trie& other);
	void copyNodes(TrieNode* destination, TrieNode* source);
	void deleteNode(TrieNode* node);
	void deleteWord(DataType word);
	void insert(DataType word);
	bool search(DataType key);
	void printSuggestions(TrieNode* root, DataType res);
};
