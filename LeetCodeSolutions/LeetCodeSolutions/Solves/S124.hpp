
#include <vector>
#include <list>
#include <map>
#include <set>

using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class S124 {
	int ans;
	int dfs(TreeNode* rot)
	{
		int res = rot->val;
		int l = 0;
		int r = 0;
		if (rot->left)
			l = dfs(rot->left);
		if (rot->right)
			r = dfs(rot->right);
		if (l < r)
		{
			int t = l;
			l = r;
			r = t;
		}
		if (l + r + rot->val > ans) ans = l + r + rot->val;
		if (l + rot->val > 0)return l + rot->val;
		return 0;
	}
public:
	int maxPathSum(TreeNode * root) {
		ans = root->val;
		dfs(root);
		return ans;
	}
};


