
#include <vector>
#include <list>
#include <map>
#include <set>

using namespace std;


/*
 * @lc app=leetcode id=33 lang=cpp
 *
 * [33] Search in Rotated Sorted Array
 *
 * https://leetcode.com/problems/search-in-rotated-sorted-array/description/
 *
 * algorithms
 * Medium (32.79%)
 * Total Accepted:    397.5K
 * Total Submissions: 1.2M
 * Testcase Example:  '[4,5,6,7,0,1,2]\n0'
 *
 * Suppose an array sorted in ascending order is rotated at some pivot unknown
 * to you beforehand.
 *
 * (i.e., [0,1,2,4,5,6,7] might become [4,5,6,7,0,1,2]).
 *
 * You are given a target value to search. If found in the array return its
 * index, otherwise return -1.
 *
 * You may assume no duplicate exists in the array.
 *
 * Your algorithm's runtime complexity must be in the order of O(log n).
 *
 * Example 1:
 *
 *
 * Input: nums = [4,5,6,7,0,1,2], target = 0
 * Output: 4
 *
 *
 * Example 2:
 *
 *
 * Input: nums = [4,5,6,7,0,1,2], target = 3
 * Output: -1
 *
 */
class S33 {
public:
	int search(vector<int>& nums, int target) {
		int n = nums.size(); if (n == 0)return -1;
		int l = 0;
		int r = n - 1;
		int m = r >> 1;
		while (l < r)
		{
			if (nums[m] >= nums[l])
			{
				if (nums[m] < target)
				{
					l = m + 1;
				}
				else if (nums[m] > target)
				{
					if (target < nums[l])
						l = m + 1;
					else
					{
						r = m;
					}

				}
				else
				{
					return m;
				}

			}
			else
			{
				if (nums[m] < target)
				{
					if (target < nums[l])
						l = m + 1;
					else
					{
						r = m;
					}

				}
				else if (nums[m] > target)
				{
					r = m;
				}
				else return m;
			}
			m = (l + r) >> 1;
		}
		if (nums[r] != target)return -1;
		return r;//
	}
};










