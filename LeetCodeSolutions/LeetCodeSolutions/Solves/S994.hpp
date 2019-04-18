#include <vector>
#include <list>
using namespace std;
class S994 {
public:
	int orangesRotting(vector<vector<int>> & grid) {
		int kuan = grid[0].size();
		int gao = grid.size();
		vector<int>tmp;
		vector<vector<int> >tp(gao, tmp);
		int shang, xia, zuo, you, cur;
		bool hasfresh = false;
		bool hasfresh0 = false;
		int ans = 0;
		bool newRot = false;
		do
		{
			hasfresh = false;
			tp.clear();
			newRot = false;
			for (int i = 0; i < gao; i++)
			{
				tmp.clear();
				for (int j = 0; j < kuan; j++)
				{
					cur = grid[i][j];
					if (cur == 1)
					{
						hasfresh0 = true;
						shang = i == 0 ? 0 : grid[i - 1][j];
						xia = i == gao - 1 ? 0 : grid[i + 1][j];
						zuo = j == 0 ? 0 : grid[i][j - 1];
						you = j == kuan - 1 ? 0 : grid[i][j + 1];
						if (shang == 0 && xia == 0 && zuo == 0 && you == 0)
							return -1;
						if (shang == 2 || xia == 2 || zuo == 2 || you == 2)
						{
							cur = 2;
							newRot = true;
						}
						else
							hasfresh = true;

					}
					tmp.push_back(cur);
				}
				tp.push_back(tmp);
			}
			if (hasfresh0 && newRot == false) return -1;
			grid = tp;
			ans++;
		} while (hasfresh);
		if (hasfresh0 == false)return 0;
		return ans;
	}
};