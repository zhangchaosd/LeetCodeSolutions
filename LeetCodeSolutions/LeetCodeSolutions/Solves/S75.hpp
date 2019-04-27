
#include <vector>
#include <list>
#include <map>
#include <set>

using namespace std;


class S75 {
public:
	void sortColors(vector<int>& nums) {
		int n = nums.size();
		if (n == 0 || n == 1)return;
		int p2 = n - 1;
		int p3 = n - 1;
		int t;
		int pai = 0;
		for (int i = 0; i < n; i++)
		{
			if (pai == 0)
			{
				while (i <= p2 && (nums[i] == 1 || nums[i] == 2))
				{
					t = nums[i];
					nums[i] = nums[p2];
					nums[p2] = t; p2--;
				}
				if (i >= p2) { pai = 1; i--; }
			}
			else
			{

				while (i <= p3 && (nums[i] == 2))
				{
					t = nums[i];
					nums[i] = nums[p3];
					nums[p3] = t; p3--;
				}

			}
			if (i >= p3)break;
		}
		return;
	}
};





