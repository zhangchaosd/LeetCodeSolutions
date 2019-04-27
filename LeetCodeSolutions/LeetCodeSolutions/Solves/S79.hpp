
#include <vector>
#include <list>
#include <map>
#include <set>

using namespace std;


class S79 {
	vector<vector<char>> board22;
	vector<vector<int>> vis2;
	int m2;
	int n2;
	string s2;
	int l2;
	bool dfs2(int y, int x, int depth)
	{
		vis2[y][x] = 1;
		if (depth >= l2)
		{
			return true;
		}
		else
		{
			if (y > 0 && board22[y - 1][x] == s2[depth] && vis2[y - 1][x] == 0)
			{
				if (dfs2(y - 1, x, depth + 1))
					return true;
			}
			if (y < m2 - 1 && board22[y + 1][x] == s2[depth] && vis2[y + 1][x] == 0)
			{
				if (dfs2(y + 1, x, depth + 1))
					return true;
			}
			if (x > 0 && board22[y][x - 1] == s2[depth] && vis2[y][x - 1] == 0)
			{
				if (dfs2(y, x - 1, depth + 1))
					return true;
			}
			if (x < n2 - 1 && board22[y][x + 1] == s2[depth] && vis2[y][x + 1] == 0)
			{
				if (dfs2(y, x + 1, depth + 1))
					return true;
			}
		}
		vis2[y][x] = 0;
		return false;
	}
public:
	bool exist(vector<vector<char>> & board, string word) {
		m2 = board.size();
		if (m2 == 0)return false;
		n2 = board[0].size();
		board22 = board;
		s2 = word;
		vector<int>t(n2, 0);
		vis2 = vector<vector<int> >(m2, t);
		// vis=vis0;
		bool ans;
		l2 = word.length();
		for (int i = 0; i < m2; i++)
		{
			for (int j = 0; j < n2; j++)
			{
				if (board[i][j] == word[0])
				{
					ans = dfs2(i, j, 1);
					if (ans)return true;
				}
			}
		}
		return false;
	}
};




