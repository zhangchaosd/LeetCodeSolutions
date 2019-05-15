#include <vector>
#include <string>
#include <list>

using namespace std;

/*
 * @lc app=leetcode id=208 lang=cpp
 *
 * [208] Implement Trie (Prefix Tree)
 */
class Trie208 {
	struct node {
		char c;
		int ct;
		map<char, node*>childs;
		node(char _c)
		{
			c = _c;
			ct = 0;
		}
	};

	map<char, node*>tres;
public:
	/** Initialize your data structure here. */
	Trie208() {
	}

	/** Inserts a word into the trie. */
	void insert(string word) {
		int n = word.length();
		node* cur;
		if (tres[word[0]] == NULL)
		{
			tres[word[0]] = new node(word[0]);
		}
		cur = tres[word[0]];
		cur->ct++;
		for (int i = 1; i < n; i++)
		{
			if (cur->childs[word[i]] == NULL)
			{
				cur->childs[word[i]] = new node(word[i]);
			}
			cur = cur->childs[word[i]];
			cur->ct++;
		}
	}

	/** Returns if the word is in the trie. */
	bool search(string word) {
		node* cur = tres[word[0]];
		int n = word.length();
		for (int i = 1; i < n && cur; i++)
		{
			cur = cur->childs[word[i]];
		}
		if (!cur)return false;
		int t = 0;
		for (auto it = cur->childs.begin(); it != cur->childs.end(); it++)
		{
			if (it->second)
				t += it->second->ct;
		}
		return t < cur->ct;
	}

	/** Returns if there is any word in the trie that starts with the given prefix. */
	bool startsWith(string prefix) {
		node* cur = tres[prefix[0]];
		int n = prefix.length();
		for (int i = 1; i < n && cur; i++)
		{
			cur = cur->childs[prefix[i]];
		}
		return cur;
	}
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */


