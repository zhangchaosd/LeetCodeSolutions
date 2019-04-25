
#include <vector>
#include <list>
#include <map>
#include <set>

using namespace std;


/*
 * @lc app=leetcode id=47 lang=cpp
 *
 * [47] Permutations II
 *
 * https://leetcode.com/problems/permutations-ii/description/
 *
 * algorithms
 * Medium (39.95%)
 * Total Accepted:    234.6K
 * Total Submissions: 587K
 * Testcase Example:  '[1,1,2]'
 *
 * Given a collection of numbers that might contain duplicates, return all
 * possible unique permutations.
 *
 * Example:
 *
 *
 * Input: [1,1,2]
 * Output:
 * [
 * ⁠ [1,1,2],
 * ⁠ [1,2,1],
 * ⁠ [2,1,1]
 * ]
 *
 *
 */
class S47 {

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
			map<int, int>vismp;
			for (int i = 0; i < depth; i++)
			{
				if (vis[i] == false && vismp[numss[i]] == 0)
				{
					vis[i] = true;
					path.push_back(numss[i]);
					dfs(i, curdepth + 1);
					path.pop_back();
					vis[i] = false;
					vismp[numss[i]] = 1;
				}
			}
		}
	}


public:
	vector<vector<int>> permuteUnique(vector<int> & nums) {
		numss = nums;
		int n = nums.size();
		depth = n;
		vis = vector<bool>(n, false);
		map<int, int>vismp;
		for (int i = 0; i < n; i++)
		{
			if (vismp[nums[i]] == 0)
			{
				vis[i] = true;
				path.push_back(nums[i]);
				dfs(i, 1);
				path.pop_back();
				vis[i] = false;
				vismp[nums[i]] = 1;
			}
		}
		return ans;
	}
};














