#include <vector>
#include <list>
using namespace std;

//https://leetcode-cn.com/contest/weekly-contest-134/problems/moving-stones-until-consecutive/

class S5039 {
public:
	vector<int> numMovesStones(int a, int b, int c) {
		int x, y, z;
		if (a > b)
		{
			int t = a;
			a = b;
			b = t;
		}
		if (a > c)
		{
			int t = a;
			a = c;
			c = t;
		}
		if (b > c)
		{
			int t = b;
			b = c;
			c = t;
		}
		vector<int>ans;
		if (a + 2 == c)
		{
			ans.push_back(0);
			ans.push_back(0);

		}
		else if (a + 1 == b)
		{
			ans.push_back(1);
			ans.push_back(c - b - 1);
		}
		else if (b + 1 == c)
		{
			ans.push_back(1);
			ans.push_back(b - a - 1);
		}
		else if (a + 2 == b || b + 2 == c)
		{
			ans.push_back(1);
			ans.push_back(b - a - 1 + (c - b - 1));
		}

		else
		{
			ans.push_back(2);
			ans.push_back(b - a - 1 + (c - b - 1));
		}

		return ans;
	}
};