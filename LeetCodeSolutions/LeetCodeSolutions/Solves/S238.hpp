#include <vector>
#include <string>
#include <list>
#include <map>

using namespace std;

/*
 * @lc app=leetcode id=238 lang=cpp
 *
 * [238] Product of Array Except Self
 */
class Solution238 {
public:
	vector<int> productExceptSelf(vector<int>& nums) {
		vector<int>ans;
		int n = nums.size();
		int j = 1;
		int nz = 0;
		for (auto i : nums)
		{
			if (i != 0)j *= i;
			if (i == 0)nz++;
		}
		if (nz > 1)
		{
			ans = vector<int>(n, 0);
			return ans;
		}
		for (int i = 0; i < n; i++)
		{
			ans.push_back(nums[i] == 0 ? j : nz == 1 ? 0 : (j / nums[i]));
		}
		return ans;
	}
};



