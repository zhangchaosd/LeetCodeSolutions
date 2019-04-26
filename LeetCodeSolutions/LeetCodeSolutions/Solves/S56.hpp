
#include <vector>
#include <list>
#include <map>
#include <set>

using namespace std;

/*
 * @lc app=leetcode id=56 lang=cpp
 *
 * [56] Merge Intervals
 */
class S56 {
	vector<vector<int> >ans;
	vector<int>tmp;
	static bool cmp(vector<int>& v1, vector<int>& v2)
	{
		if (v1[0] != v2[0])return v1[0] < v2[0];
		return v1[1] < v2[1];
	}
public:
	vector<vector<int>> merge(vector<vector<int>> & intervals) {
		int n = intervals.size();
		if (n == 0)
		{
			return ans;
		}
		sort(intervals.begin(), intervals.end(), cmp);
		ans.push_back(intervals[0]);
		for (int i = 1; i < n; i++)
		{
			if (intervals[i][0] > ans[ans.size() - 1][1]) ans.push_back(intervals[i]);
			else
			{

				ans[ans.size() - 1][1] = max(ans[ans.size() - 1][1], intervals[i][1]);
			}

		}
		return ans;
	}
};




