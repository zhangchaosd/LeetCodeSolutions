#include <vector>

using namespace std;

class S153 {
public:
	int findMin(vector<int>& nums) {
		int n = nums.size();
		int l = 0;
		int r = n - 1;
		int m = (l + r) / 2;
		while (l < r)
		{
			if (nums[l] < nums[r])return nums[l];
			if (nums[m] >= nums[l])
				l = m + 1;
			else
				r = m;
			m = (r + l) / 2;
		}
		return nums[r];
	}
};

