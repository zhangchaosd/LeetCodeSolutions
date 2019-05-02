
#include <vector>
#include <list>
#include <map>
#include <set>

using namespace std;

class S125 {
	map<char, int>mp;

public:
	bool isPalindrome(string s) {
		int p2 = s.length();
		int n = p2;
		int p1 = 0;
		while (p1 < p2 && mp[s[p1]] == 0)
			p1++;
		p2--;
		while (p2 >= 0 && mp[s[p2]] == 0)
			p2--;
		while (p1 < p2)
		{
			if (mp[s[p1]] != mp[s[p2]])
				return false;
			p1++;
			while (p1 < p2 && mp[s[p1]] == 0)
				p1++;
			p2--;
			while (p2 > p1 && mp[s[p2]] == 0)
				p2--;
		}
		return true;
	}
	S125()
	{
		for (int i = 1; i <= 26; i++)
		{
			mp['a' + i - 1] = i;
			mp['A' + i - 1] = i;

		}
		mp['0'] = 30;
		mp['1'] = 31;
		mp['2'] = 32;
		mp['3'] = 33;
		mp['4'] = 34;
		mp['5'] = 35;
		mp['6'] = 36;
		mp['7'] = 37;
		mp['8'] = 38;
		mp['9'] = 39;
	}
};


