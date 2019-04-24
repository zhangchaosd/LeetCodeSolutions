
#include <vector>
#include <list>
#include <map>
#include <set>

using namespace std;


/*
 * @lc app=leetcode id=46 lang=cpp
 *
 * [46] Permutations
 *
 * https://leetcode.com/problems/permutations/description/
 *
 * algorithms
 * Medium (54.51%)
 * Total Accepted:    364K
 * Total Submissions: 667.6K
 * Testcase Example:  '[1,2,3]'
 *
 * Given a collection of distinct integers, return all possible permutations.
 *
 * Example:
 *
 *
 * Input: [1,2,3]
 * Output:
 * [
 * ⁠ [1,2,3],
 * ⁠ [1,3,2],
 * ⁠ [2,1,3],
 * ⁠ [2,3,1],
 * ⁠ [3,1,2],
 * ⁠ [3,2,1]
 * ]
 *
 *
 */
class S46 {
	vector<vector<int> >ans;
	vector<bool>vis;
	vector<int>path;
	vector<int>numss;
	int depth;
	void dfs(int idx, int curdepth)
	{
		if (curdepth == depth)
		{
			ans.push_back(path);
		}
		else
		{
			for (int i = 0; i < depth; i++)
			{
				if (vis[i] == false)
				{
					vis[i] = true;
					path.push_back(numss[i]);
					dfs(i, curdepth + 1);
					path.pop_back();
					vis[i] = false;
				}
			}
		}


	}
public:
	vector<vector<int>> permute(vector<int> & nums) {
		numss = nums;
		int n = nums.size();
		depth = n;
		vis = vector<bool>(n, false);
		for (int i = 0; i < n; i++)
		{
			vis[i] = true;
			path.push_back(nums[i]);
			dfs(i, 1);
			path.pop_back();
			vis[i] = false;
		}
		return ans;
	}
};












