#include <vector>
#include <string>

using namespace std;

/*
 * @lc app=leetcode id=171 lang=cpp
 *
 * [171] Excel Sheet Column Number
 */
class S171 {
public:
	int titleToNumber(string s) {
		int n = s.length();
		int res = 0;
		for (int i = 0; i < n; i++)
		{
			res *= 26;
			res += s[i] - 'A' + 1;
		}
		return res;
	}
};




