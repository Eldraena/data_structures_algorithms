#include <stdio.h>
#include <malloc.h>

#define ALPHABET_SIZE 26

typedef struct TrieNode
{
	TrieNode* childArr[ALPHABET_SIZE];
	int isEndOfWord;
	int cnt;
};
TrieNode* root;


TrieNode* trie_createNode()
{
	TrieNode* pNode = (TrieNode*)malloc(sizeof(TrieNode));
	if (pNode)
	{
		for (int i = 0; i < ALPHABET_SIZE; i++)
			pNode->childArr[i] = nullptr;
		pNode->isEndOfWord = 0;
		pNode->cnt = 0;
	}
	return pNode;
}

void trie_init()
{
	root = trie_createNode();
}

void trie_destroy(TrieNode* pNode)
{
	if (pNode)
	{
		for (int i = 0; i < ALPHABET_SIZE; i++)
		{
			if (pNode->childArr[i])
				trie_destroy(pNode->childArr[i]);
		}
		free(pNode);
	}
}

void trie_insertWord(const char* word)
{
	TrieNode* pTmp = root;
	if (pTmp)
	{
		while(*word)
		{
			int key = *word++ - 'a';
			if (pTmp->childArr[key] == nullptr)
				pTmp->childArr[key] = trie_createNode();
			pTmp->childArr[key]->cnt++;
			pTmp = pTmp->childArr[key];
		}
		pTmp->isEndOfWord++;
	}
}

bool trie_searchWord(const char* word)
{
	TrieNode* pTmp = root;
	if (pTmp)
	{
		while (*word)
		{
			int key = *word++ - 'a';
			if (pTmp->childArr[key] == nullptr)
				return false;
			pTmp = pTmp->childArr[key];
		}
		if (pTmp->isEndOfWord)
			return true;
	}
	return false;
}

void trie_deleteWord(const char* word)
{
	if (!trie_searchWord(word))
		return;

	TrieNode* pTmp = root;
	if (pTmp)
	{
		while (*word)
		{
			int key = *word++ - 'a';
			pTmp->childArr[key]->cnt--;
			pTmp = pTmp->childArr[key];
		}
		pTmp->isEndOfWord--;
	}
}

int trie_countPrefix(const char* prefix)
{
	TrieNode* pTmp = root;
	if (pTmp)
	{
		while (*prefix)
		{
			int key = *prefix++ - 'a';
			if (pTmp->childArr[key] == nullptr)
				return 0;
			pTmp = pTmp->childArr[key];
		}
		return pTmp->cnt;
	}
	return 0;
}

int main()
{
	return 0;
}
