#include <vector>
using namespace std;
class S410 {
public:

	int splitArray(vector<int>& nums, int m) {
		long minn = -1;
		long maxx = 0;
		long midd = -1;

		for (int i = 0; i < nums.size(); i++)
		{
			if (nums[i] > minn)
				minn = nums[i];
			maxx += nums[i];
		}

		while (minn != maxx)
		{
			midd = (minn + maxx) >> 1;
			int tm = 1;
			long tsum = 0;
			for (int i = 0; i < nums.size(); i++)
			{
				tsum += nums[i];
				if (tsum > midd)
				{
					tsum = 0;
					tm++;
					i--;
				}
			}
			if (tm > m)
			{
				minn = midd + 1;
			}
			else
			{
				maxx = midd;
			}
		}
		return minn;
	}
};