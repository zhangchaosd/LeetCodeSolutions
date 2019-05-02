
#include <vector>
#include <list>
#include <map>
#include <set>

using namespace std;

class S121 {
public:
	int maxProfit(vector<int>& prices) {
		int n = prices.size();
		if (n < 2) return 0;
		int ans = 0;
		int tans = prices[1] - prices[0];
		int minn = prices[0];
		if (tans < 0)minn = prices[1];
		for (int i = 2; i < n; i++)
		{
			if (prices[i] - minn > tans)
				tans = prices[i] - minn;
			if (prices[i] < minn)
				minn = prices[i];
		}
		if (tans > 0)ans = tans;
		return ans;
	}
};


