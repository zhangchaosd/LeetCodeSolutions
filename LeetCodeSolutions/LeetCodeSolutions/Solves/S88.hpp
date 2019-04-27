
#include <vector>
#include <list>
#include <map>
#include <set>

using namespace std;


class S88 {
public:
	void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
		int tt = m + n;
		m--;
		n--;
		for (int i = tt - 1; i >= 0; i--)
		{
			if (m == -1)
				nums1[i] = nums2[n--];
			else if (n == -1)
				nums1[i] = nums1[m--];
			else if (nums1[m] > nums2[n])
				nums1[i] = nums1[m--];
			else
				nums1[i] = nums2[n--];
		}
		return;
	}
};




