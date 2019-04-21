#include <vector>
#include <list>
using namespace std;
class S1029 {
	static bool cmp(vector<int>& v1, vector<int>& v2)
	{
		int c1 = abs(v1[0] - v1[1]);
		int c2 = abs(v2[0] - v2[1]);
		return c1 > c2;
	}
public:
	int twoCitySchedCost(vector<vector<int>> & costs) {
		sort(costs.begin(), costs.end(), cmp);
		int l = costs.size();
		int n1 = 0;
		int n2 = 0;
		int ans = 0;

		for (int i = 0; i < l; i++)
		{
			if (costs[i][0] < costs[i][1])
			{
				n1++;
				ans += costs[i][0];
			}
			else
			{
				n2++;
				ans += costs[i][1];
			}

			if (n1 * 2 == l || n2 * 2 == l)
			{
				i++;
				if (n1 * 2 != l)
				{
					for (; i < l; i++)
					{
						ans += costs[i][0];
					}
				}
				else if (n2 * 2 != l)
				{
					for (; i < l; i++)
					{
						ans += costs[i][1];
					}
				}
				break;
			}
		}
		return ans;

	}
};