#pragma once
#include <iostream>
using namespace std;




const int maxSize = 26;
class Trie
{
private:
	class TrieNode
	{
		public:
			TrieNode* children[maxSize];
			bool isEnd;

			//Constructor
			TrieNode()
			{
				isEnd = false;
				for (int i = 0; i < maxSize; i++)
					children[i] = NULL;
			}
	};

	TrieNode* root;

public:
	TrieNode* root;
	Trie();
	~Trie();
	void insert(string);
	bool search(TrieNode* root, string key);
	void printSuggestions(TrieNode*, string);
};
