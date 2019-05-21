#include <vector>
#include <string>
#include <list>
#include <map>

using namespace std;

/*
 * @lc app=leetcode id=236 lang=cpp
 *
 * [236] Lowest Common Ancestor of a Binary Tree
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
class S236 {
	TreeNode* P, * Q;
	vector<TreeNode*>pp, pq, tp;
	TreeNode* ans;
	bool bp, bq;
	void dfs(TreeNode* cur)
	{
		tp.push_back(cur);
		if (!bp && cur->val == P->val)
		{
			bp = true;
			pp = tp;
		}
		if (!bq && cur->val == Q->val)
		{
			bq = true;
			pq = tp;
		}
		if (bp && bq)
		{
			int np = pp.size();
			int nq = pq.size();
			int i = 0;
			for (i = 0; i < np && i < nq; i++)
			{
				if (pq[i] != pp[i])
					break;
			}
			ans = pq[i - 1];
			return;
		}
		else
		{
			if (cur->left)dfs(cur->left);
			if (ans)return;
			if (cur->right)dfs(cur->right);
			if (ans)return;
		}
		tp.pop_back();
	}
public:
	TreeNode* lowestCommonAncestor(TreeNode * root, TreeNode * p, TreeNode * q) {
		P = p;
		Q = q;
		ans = nullptr;
		bp = false;
		bq = false;
		dfs(root);
		return ans;
	}
};

