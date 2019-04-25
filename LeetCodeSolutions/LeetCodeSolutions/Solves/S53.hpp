
#include <vector>
#include <list>
#include <map>
#include <set>

using namespace std;

/*
 * @lc app=leetcode id=53 lang=cpp
 *
 * [53] Maximum Subarray
 */
class S53 {
public:
	int maxSubArray(vector<int>& nums) {
		int n = nums.size(); if (n == 0)return 0;
		int ans = 0;
		int tans = 0;
		for (int i = 0; i < n; i++)
		{
			tans += nums[i];
			if (tans < 0) tans = 0;
			if (tans > ans) ans = tans;
		}
		if (ans == 0)
		{
			ans = nums[0];
			for (int i = 1; i < n; i++)
			{
				if (nums[i] > ans)
					ans = nums[i];
			}
		}
		return ans;
	}
};




