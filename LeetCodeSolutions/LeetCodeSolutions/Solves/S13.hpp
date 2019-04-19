#include <vector>
#include <list>
#include <map>
using namespace std;
class S13 {//47
public:
	int romanToInt(string s) {
		vector<int>ints = { 1,5,10,50,100,500,1000 };
		vector<char>cs = { 'I','V','X','L','C','D','M' };
		map<char, int>mp;
		for (int i = 0; i < 7; i++)
			mp[cs[i]] = ints[i];
		int l = s.length();
		int ans = 0;
		for (int i = 0; i < l; i++)
		{
			char curc = s[i];
			if (i == l - 1)
			{
				ans += mp[curc];
			}
			else
			{
				ans += mp[curc];
				if (curc == 'I')
				{
					if (s[i + 1] == 'V' || s[i + 1] == 'X') ans -= 2 * mp[curc];
				}
				else if (curc == 'X')
				{
					if (s[i + 1] == 'L' || s[i + 1] == 'C') ans -= 2 * mp[curc];
				}
				else if (curc == 'C')
				{
					if (s[i + 1] == 'D' || s[i + 1] == 'M') ans -= 2 * mp[curc];
				}
			}
		}
		return ans;

	}
};