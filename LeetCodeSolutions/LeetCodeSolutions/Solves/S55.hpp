
#include <vector>
#include <list>
#include <map>
#include <set>

using namespace std;

/*
 * @lc app=leetcode id=55 lang=cpp
 *
 * [55] Jump Game
 */
class S55 {
public:
	bool canJump(vector<int>& nums) {
		int n = nums.size();
		if (n == 0 || n == 1)return true;
		if (nums[0] == 0)return false;
		int maxx = nums[0];
		int tt = nums[0];
		for (int i = 0; i < n; i++)
		{
			if (maxx < i)return false;
			tt = i + nums[i];
			if (tt > maxx)maxx = tt;
		}
		return maxx >= n - 1;
	}
};



