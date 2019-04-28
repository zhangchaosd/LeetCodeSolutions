#include <vector>
#include <list>
using namespace std;

//https://leetcode-cn.com/contest/weekly-contest-134/problems/coloring-a-border/
class S5040 {
	vector<vector<int> > ans;
	vector<vector<int> > vis;
public:
	vector<vector<int>> colorBorder(vector<vector<int>>& grid, int r0, int c0, int color) {
		if (grid[r0][c0] == color)
		{
			ans = grid;
			return ans;
		}
		int m = grid.size();
		int n = grid[0].size();
		vector<int>t(n, 0);
		vis = vector<vector<int> >(m, t);
		vector<int>xs;
		vector<int>ys;
		xs.push_back(c0);
		ys.push_back(r0);
		int yuan = grid[r0][c0];

		vector<int>gx;
		vector<int>gy;

		while (!xs.empty())
		{
			int curx = xs[xs.size() - 1];
			xs.pop_back();
			int cury = ys[ys.size() - 1];
			ys.pop_back();
			vis[cury][curx] = 1;


			if (cury > 0 && grid[cury - 1][curx] == yuan && vis[cury - 1][curx] == 0)
			{
				xs.push_back(curx);
				ys.push_back(cury - 1);

			}

			if (cury < m - 1 && grid[cury + 1][curx] == yuan && vis[cury + 1][curx] == 0)
			{
				xs.push_back(curx);
				ys.push_back(cury + 1);
			}

			if (curx > 0 && grid[cury][curx - 1] == yuan && vis[cury][curx - 1] == 0)
			{
				xs.push_back(curx - 1);
				ys.push_back(cury);
			}

			if (curx < n - 1 && grid[cury][curx + 1] == yuan && vis[cury][curx + 1] == 0)
			{
				xs.push_back(curx + 1);
				ys.push_back(cury);
			}
			if (cury == m - 1 || cury == 0 || curx == 0 || curx == n - 1 || grid[cury + 1][curx] != yuan || grid[cury - 1][curx] != yuan || grid[cury][curx + 1] != yuan || grid[cury][curx - 1] != yuan)
			{
				gx.push_back(curx);
				gy.push_back(cury);
			}

		}
		ans = grid;

		for (int i = 0; i < gx.size(); i++)
		{
			ans[gy[i]][gx[i]] = color;
		}


		return ans;

	}
};