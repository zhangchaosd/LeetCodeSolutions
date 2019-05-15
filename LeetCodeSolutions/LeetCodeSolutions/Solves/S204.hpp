#include <vector>
#include <string>
#include <list>

using namespace std;

/*
 * @lc app=leetcode id=204 lang=cpp
 *
 * [204] Count Primes
 */
class S204 {
public:
	int countPrimes(int n) {
		vector<bool>vis(n + 1, true);
		int ans = 0;
		for (int i = 2; i <= n; i++)
		{
			if (vis[i])
			{
				for (int j = 2; i * j <= n; j++)
					vis[i * j] = false;
			}
		}
		for (int i = 2; i < n; i++)
			if (vis[i])
				ans++;

		return ans;
	}
};


