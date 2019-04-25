
#include <vector>
#include <list>
#include <map>
#include <set>

using namespace std;

/*
 * @lc app=leetcode id=54 lang=cpp
 *
 * [54] Spiral Matrix
 */
class S54 {
public:
	vector<int> spiralOrder(vector<vector<int>>& matrix) {
		vector<int>ans;
		int m = matrix.size(); if (m == 0)return ans;
		int n = matrix[0].size();
		int tt = m * n;
		if (tt == 0)return ans;
		int ttcnt = 0;
		vector<bool>ttttt(n, false);
		vector<vector<bool> >vis(m, ttttt);
		int curx = 0;
		int cury = 0;
		while (ttcnt != tt)
		{
			ans.push_back(matrix[cury][curx]);
			vis[cury][curx] = true;
			{
				if (cury <= (m - 1) / 2)
				{
					if (cury > 0 && (vis[cury - 1][curx] == false))
					{
						cury--;
					}
					else if (curx < n - 1 && (vis[cury][curx + 1] == false))
					{
						curx++;
					}
					else
					{
						cury++;
					}
				}
				else
				{
					if (cury < m - 1 && (vis[cury + 1][curx] == false))
					{
						cury++;
					}
					else if (curx > 0 && (vis[cury][curx - 1] == false))
					{
						curx--;
					}
					else
					{
						cury--;
					}
				}
			}
			ttcnt++;
		}

		return ans;
	}
};




