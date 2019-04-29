
#include <vector>
#include <list>
#include <map>
#include <set>

using namespace std;


/*
 * @lc app=leetcode id=98 lang=cpp
 *
 * [98] Validate Binary Search Tree
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
class S98 {
	int getmin(TreeNode* rot)
	{
		if (rot->left)
			return getmax(rot->left);
		else
			return rot->val;
	}
	int getmax(TreeNode* rot)
	{
		if (rot->right)
			return getmax(rot->right);
		else
			return rot->val;
	}
	bool dfs(TreeNode* rot)
	{
		if (rot == 0)return true;
		bool bl = true, br = true;
		if (rot->left)
		{
			if (rot->left->val < rot->val)
			{
				bl = dfs(rot->left);
				if (bl)
				{
					int lmaxx = getmax(rot->left);
					if (lmaxx >= rot->val)
						return false;
				}
				else
				{
					return false;
				}

			}
			else
				return false;
		}
		if (rot->right)
		{
			if (rot->right->val > rot->val)
			{
				bl = dfs(rot->right);
				if (bl)
				{
					int rminn = getmin(rot->right);
					if (rminn <= rot->val)
						return false;
				}
				else
				{
					return false;
				}

			}
			else
				return false;
		}
		return true;
	}

public:
	bool isValidBST(TreeNode * root) {
		bool ans = dfs(root);
		return ans;
	}
};







