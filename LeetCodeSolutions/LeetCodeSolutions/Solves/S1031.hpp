#include <vector>
#include <list>
using namespace std;
class S1031 {
	int sz[1001];
public:
	int maxSumTwoNoOverlap(vector<int>& A, int L, int M) {
		sz[0] = 0;
		int n = A.size();
		for (int i = 0; i < n; i++)
		{
			sz[i + 1] = sz[i] + A[i];
		}
		int ans = 0;
		for (int i = 0; i + L <= n; i++)
		{
			for (int j = i + L; j + M <= n; j++)
			{
				ans = max(ans, sz[i + L] - sz[i] + sz[j + M] - sz[j]);
			}
		}
		for (int i = 0; i + M <= n; i++)
		{
			for (int j = i + M; j + L <= n; j++)
			{
				ans = max(ans, sz[i + M] - sz[i] + sz[j + L] - sz[j]);
			}
		}

		return ans;
	}
};