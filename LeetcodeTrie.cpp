#include<string>
#include <set>
#include<vector>
#include<iostream>
#include<map>
#include<stack>
#include <unordered_set>
#include <algorithm>    // std::min_element, std::max_element
using namespace std;
const int ALPHABET_SIZE = 26;
struct TreeNode
{
	struct TreeNode* children[ALPHABET_SIZE];
	bool bIsEndOfWord;
};

TreeNode* getNode()
{
	struct TreeNode* pNode = new TreeNode();
	pNode->bIsEndOfWord = false;

	for (int i = 0; i < ALPHABET_SIZE; i++)
	{
		pNode->children[i] = nullptr;
	}
	return pNode;
}

void insert(struct TreeNode* root, string key)
{
	struct TreeNode* pCrawl = root;
	
	for (int i = 0; i < key.length(); ++i)
	{
		int index = key[i] - 'a';
		if (!pCrawl->children[index])
		{
			pCrawl->children[i] = getNode();
		}

		pCrawl = pCrawl->children[i];
	}

	// mark last node as leaf 
	pCrawl->bIsEndOfWord = true;
}

bool search(struct TreeNode* root, string key)
{
	struct TreeNode* pCrawl = root;

	for (int i = 0; i < key.length(); ++i)
	{
		int index = key[i] - 'a';
		if (!pCrawl->children[index])
		{
			return false;
		}

		pCrawl = pCrawl->children[i];
	}

	// mark last node as leaf 
	return (pCrawl != nullptr && pCrawl->bIsEndOfWord);
}
