
#include <vector>
#include <list>
#include <map>
#include <set>

using namespace std;
class S15 {//01
	static bool cmp(int& a, int& b)
	{
		return a < b;
	}
public:
	vector<vector<int>> threeSum(vector<int>& nums) {
		vector<int>tp;
		vector< vector<int> >ans;
		sort(nums.begin(), nums.end(), cmp);

		int l = nums.size();
		if (l < 3)return ans;

		for (int i = 0; i < l;)
		{

			int j = i + 1;
			int k = l - 1;
			while (j < k)
			{
				if (nums[i] + nums[j] + nums[k] == 0)
				{
					tp.push_back(nums[i]);
					tp.push_back(nums[j]);
					tp.push_back(nums[k]);
					ans.push_back(tp);
					tp.clear();
					j++;
					while (j < k && nums[j - 1] == nums[j])j++;
					k--;
					while (j < k && nums[k] == nums[k + 1])k--;
				}
				else if (nums[i] + nums[j] + nums[k] > 0) k--;
				else j++;
			}

			i++;
			while (i < l && nums[i] == nums[i - 1])i++;
		}
		return ans;
	}
};