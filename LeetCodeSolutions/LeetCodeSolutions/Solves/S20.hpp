
#include <vector>
#include <list>
#include <map>
#include <set>

using namespace std;
/*
 * @lc app=leetcode id=20 lang=cpp
 *
 * [20] Valid Parentheses
 *
 * https://leetcode.com/problems/valid-parentheses/description/
 *
 * algorithms
 * Easy (36.27%)
 * Total Accepted:    562.6K
 * Total Submissions: 1.6M
 * Testcase Example:  '"()"'
 *
 * Given a string containing just the characters '(', ')', '{', '}', '[' and
 * ']', determine if the input string is valid.
 *
 * An input string is valid if:
 *
 *
 * Open brackets must be closed by the same type of brackets.
 * Open brackets must be closed in the correct order.
 *
 *
 * Note that an empty string is also considered valid.
 *
 * Example 1:
 *
 *
 * Input: "()"
 * Output: true
 *
 *
 * Example 2:
 *
 *
 * Input: "()[]{}"
 * Output: true
 *
 *
 * Example 3:
 *
 *
 * Input: "(]"
 * Output: false
 *
 *
 * Example 4:
 *
 *
 * Input: "([)]"
 * Output: false
 *
 *
 * Example 5:
 *
 *
 * Input: "{[]}"
 * Output: true
 *
 *
 */
class S20 {
public:
	bool isValid(string s) {
		int l = s.length();
		char cur;
		char esp;
		vector<int>stac;
		for (int i = 0; i < l; i++)
		{
			cur = s[i];
			if (cur == ')')
			{
				if (stac.size() == 0)return false;
				if (stac[stac.size() - 1] != '(')return false;
				stac.pop_back();
			}
			else if (cur == ']')
			{
				if (stac.size() == 0)return false;
				if (stac[stac.size() - 1] != '[')return false;
				stac.pop_back();
			}
			else if (cur == '}')
			{
				if (stac.size() == 0)return false;
				if (stac[stac.size() - 1] != '{')return false;
				stac.pop_back();
			}
			else
			{
				stac.push_back(cur);
			}


		}
		return stac.size() == 0;
	}
};

