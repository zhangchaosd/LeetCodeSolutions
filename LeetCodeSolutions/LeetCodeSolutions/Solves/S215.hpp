#include <vector>
#include <string>
#include <list>
#include <map>

using namespace std;


/*
 * @lc app=leetcode id=215 lang=cpp
 *
 * [215] Kth Largest Element in an Array
 */
class S215 {
public:
	static bool cmpa(const int& a, const int& b)
	{
		return a > b;
	}
	static bool cmpb(const int& a, const int& b)
	{
		return a < b;
	}
	int findKthLargest(vector<int>& nums, int k) {
		int n = nums.size();
		int ans;
		if (k < n / 2)
		{
			partial_sort(nums.begin(), nums.begin() + k, nums.end(), cmpa);
			ans = nums[k - 1];
		}
		else
		{
			partial_sort(nums.begin(), nums.begin() + n - k + 1, nums.end(), cmpb);
			ans = nums[n - k];
		}

		return ans;
	}
};



