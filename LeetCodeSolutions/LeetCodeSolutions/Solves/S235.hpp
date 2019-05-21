#include <vector>
#include <string>
#include <list>
#include <map>

using namespace std;

/*
 * @lc app=leetcode id=235 lang=cpp
 *
 * [235] Lowest Common Ancestor of a Binary Search Tree
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
class S235 {
public:
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		TreeNode* ans = root;
		while (1)
		{
			if (p->val < ans->val && q->val < ans->val)
				ans = ans->left;
			else if (p->val > ans->val && q->val > ans->val)
				ans = ans->right;
			else
			{
				if (ans->val == p->val)
					return p;
				if (ans->val == q->val)
					return q;
				return ans;
			}

		}
		return ans;
	}
};


