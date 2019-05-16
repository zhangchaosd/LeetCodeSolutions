#include <vector>
#include <string>
#include <list>
#include <map>

using namespace std;

/*
 * @lc app=leetcode id=212 lang=cpp
 *
 * [212] Word Search II
 */
class S212 {
	vector<string>ans;
	vector<vector<char> >vis;
	vector<vector<char>> board0;
	string w;
	map<string, bool>fd;
	int m, n;
	int sz[3] = { -1,0,1 };

	bool dfs(int y, int x, int dep)
	{
		if (dep == w.length() - 1)
			return true;
		bool res = false;
		vis[y][x] = 1;

		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				if (i != j && sz[i] + sz[j] && y + sz[i] >= 0 && y + sz[i] < m && x + sz[j] >= 0 && x + sz[j] < n)
				{
					if (vis[y + sz[i]][x + sz[j]] == 0 && w[dep + 1] == board0[y + sz[i]][x + sz[j]])
					{
						if (dfs(y + sz[i], x + sz[j], dep + 1))
							return true;
					}
				}
			}
		}

		vis[y][x] = 0;
		return res;
	}
public:
	vector<string> findWords(vector<vector<char>> & board, vector<string> & words) {
		m = board.size();
		if (m == 0)return ans;
		n = board[0].size();
		if (n == 0)return ans;
		vector<char>tvis(n, 0);
		int ns = words.size();
		board0 = board;
		for (int i = 0; i < ns; i++)
		{
			w = words[i];
			if (fd[w]) continue;
			int l = w.length();

			if (l == 0)continue;
			for (int y = 0; y < m; y++)
			{
				if (fd[w])break;
				for (int x = 0; x < n; x++)
				{
					if (board[y][x] == w[0])
					{
						vis = vector<vector<char>>(m, tvis);

						bool res = dfs(y, x, 0);
						if (res)
						{
							ans.push_back(w);
							fd[w] = true;
							break;
						}
					}
				}
			}
		}
		return ans;
	}
};



