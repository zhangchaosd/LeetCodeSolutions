#include <vector>
#include <string>
#include <list>
#include <map>

using namespace std;

/*
 * @lc app=leetcode id=258 lang=cpp
 *
 * [258] Add Digits
 */
class Solution258 {
	const int sz[9] = { 9,1,2,3,4,5,6,7,8 };
public:
	int addDigits(int num) {
		if (num < 10)return num;
		return sz[num % 9];
	}
};



