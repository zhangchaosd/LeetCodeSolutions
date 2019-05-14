#include <vector>
#include <string>
#include <list>

using namespace std;

/*
 * @lc app=leetcode id=173 lang=cpp
 *
 * [173] Binary Search Tree Iterator
 */
 /**
  * Definition for a binary tree node.
  * struct TreeNode {
  *     int val;
  *     TreeNode *left;
  *     TreeNode *right;
  *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  * };
  */
class BSTIterator {
	list<TreeNode*>pa;
public:
	BSTIterator(TreeNode* root) {
		while (root)
		{
			pa.push_back(root);
			root = root->left;
		}
	}

	/** @return the next smallest number */
	int next() {
		TreeNode* cur = pa.back();
		pa.pop_back();
		int res = cur->val;
		if (cur->right)
		{
			pa.push_back(cur->right);
			cur = cur->right;
			while (cur->left)
			{
				pa.push_back(cur->left);
				cur = cur->left;
			}
		}

		return res;
	}

	/** @return whether we have a next smallest number */
	bool hasNext() {
		return !(pa.empty());
	}
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */





