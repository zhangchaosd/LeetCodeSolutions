#include <vector>
#include <string>
#include <list>

using namespace std;

/*
*@lc app = leetcode id = 189 lang = cpp
*
*[189] Rotate Array
*/
class S189 {
public:
	void rotate(vector<int>& nums, int k) {
		int n = nums.size();
		k = k % n;
		if (n == 0 || k == 0)return;
		int t;
		if ((n / k) * k == n || (n / (n - k) * (n - k) == n))
		{
			for (int i = 0; i < k && i < n - k; i++)
			{
				int pos = i;
				int next = k + i;
				t = nums[i];
				int t2;
				do
				{
					t2 = nums[next];
					nums[next] = t;
					t = t2;
					pos = next;
					next = (next + k) % n;
				} while (pos != i);
			}
		}
		else
		{
			int pos = 0;
			int next = k;
			t = nums[0];
			int t2;
			do {
				t2 = nums[next];
				nums[next] = t;
				t = t2;
				pos = next;
				next = (next + k) % n;
			} while (pos != 0);
		}


		return;
	}
};








