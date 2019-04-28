
#include <vector>
#include <list>
#include <map>
#include <set>

using namespace std;


/*
 * @lc app=leetcode id=91 lang=cpp
 *
 * [91] Decode Ways
 */
class S91 {
public:
	int numDecodings(string s) {
		int n = s.length();
		if (n == 0)return 0;
		if (s[0] == '0')return 0;
		if (n == 1)return 1;
		unsigned long long j1 = 1;
		unsigned long long j2 = 1;
		unsigned long long ans = 0;
		for (int i = 1; i < n; i++)
		{
			if ((s[i - 1] == '1' || (s[i - 1] == '2' && s[i] < '7')) && s[i] != '0')
			{
				if (i < n - 1 && s[i + 1] == '0')
				{
					ans = j1;
					j2 = j1;
				}
				else
				{
					ans = j1 + j2;
					j2 = j1;
					j1 = ans;
				}


			}
			else
			{
				ans = j1;
				j2 = j1;
			}
			if (s[i] == '0' && (s[i - 1] != '1' && s[i - 1] != '2'))return 0;
		}
		return ans;
	}
};






