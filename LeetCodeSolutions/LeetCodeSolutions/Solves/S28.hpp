
#include <vector>
#include <list>
#include <map>
#include <set>

using namespace std;


/*
 * @lc app=leetcode id=28 lang=cpp
 *
 * [28] Implement strStr()
 *
 * https://leetcode.com/problems/implement-strstr/description/
 *
 * algorithms
 * Easy (31.71%)
 * Total Accepted:    410.6K
 * Total Submissions: 1.3M
 * Testcase Example:  '"hello"\n"ll"'
 *
 * Implement strStr().
 *
 * Return the index of the first occurrence of needle in haystack, or -1 if
 * needle is not part of haystack.
 *
 * Example 1:
 *
 *
 * Input: haystack = "hello", needle = "ll"
 * Output: 2
 *
 *
 * Example 2:
 *
 *
 * Input: haystack = "aaaaa", needle = "bba"
 * Output: -1
 *
 *
 * Clarification:
 *
 * What should we return when needle is an empty string? This is a great
 * question to ask during an interview.
 *
 * For the purpose of this problem, we will return 0 when needle is an empty
 * string. This is consistent to C's strstr() and Java's indexOf().
 *
 */
class S28 {
public:
	int strStr(string haystack, string needle) {
		int n1 = haystack.length();
		int n2 = needle.length();
		if (n2 == 0)return 0;
		if (n2 > n1)return -1;

		for (int i = 0; i + n2 <= n1; i++)
		{
			int j = 0;
			for (; j < n2; j++)
			{
				if (haystack[i + j] != needle[j])
					break;
			}
			if (j == n2)
				return i;
		}
		return -1;
	}
};








