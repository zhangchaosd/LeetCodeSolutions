
#include <vector>
#include <list>
#include <map>
#include <set>

using namespace std;

/*
 * @lc app=leetcode id=103 lang=cpp
 *
 * [103] Binary Tree Zigzag Level Order Traversal
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
class S103 {
	vector<vector<int>> ans;
	vector<int>topu;
	int depth;
	void dfs(TreeNode* cur, int de)
	{
		if (de + 1 > depth)
		{
			ans.push_back(topu);
			depth++;
		}
		ans[de].push_back(cur->val);
		if (cur->left)
			dfs(cur->left, de + 1);
		if (cur->right)
			dfs(cur->right, de + 1);
	}
public:
	vector<vector<int>> zigzagLevelOrder(TreeNode * root) {
		if (!root) return ans;
		depth = 0;
		dfs(root, 0);
		for (int i = 1; i < ans.size(); i++)
		{
			if (i % 2)
			{
				int m = ans[i].size();
				for (int j = 0; j * 2 < m; j++)
				{
					int t = ans[i][j];
					ans[i][j] = ans[i][m - 1 - j];
					ans[i][m - 1 - j] = t;
				}
			}
		}
		return ans;
	}
};









