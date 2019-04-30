
#include <vector>
#include <list>
#include <map>
#include <set>

using namespace std;

/*
 * @lc app=leetcode id=114 lang=cpp
 *
 * [114] Flatten Binary Tree to Linked List
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
class S104 {
public:
	void flatten(TreeNode* root) {
		if (!root)return;
		if (root->right == 0)
		{
			root->right = root->left;
			root->left = NULL;
		}
		else if (root->left)
		{
			TreeNode* t = root->right;
			TreeNode* t2 = root->left;
			while (t2->right)
				t2 = t2->right;
			t2->right = t;
			root->right = root->left;
			root->left = NULL;
		}
		flatten(root->right);
	}
};









