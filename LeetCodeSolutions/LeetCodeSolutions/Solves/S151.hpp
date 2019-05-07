#include <string>

using namespace std;

class S151 {
public:
	string reverseWords(string s) {
		int n = s.length();

		{
			int tn = n - 1;
			while (tn >= 0 && s[tn] == ' ') tn--;
			string ss;
			if (tn < 0) return ss;
			if (tn < n - 1) s.erase(tn + 1);
			n = tn + 1;
		}


		char tc;
		for (int i = 0; i < n / 2; i++)
		{
			tc = s[i];
			s[i] = s[n - 1 - i];
			s[n - 1 - i] = tc;
		}

		{
			int tn = n - 1;
			while (tn >= 0 && s[tn] == ' ') tn--;
			string ss;
			if (tn < n - 1) s.erase(tn + 1);
			n = tn + 1;
		}
		{
			int p1 = 0;
			while (p1 < n && s[p1] != ' ') p1++;
			int p2 = p1;
			while (p2 < n)
			{
				p1++;
				while (s[p2] == ' ') p2++;
				while (p2 < n && s[p2] != ' ')
				{
					s[p1] = s[p2];
					p1++;
					p2++;
				}
				if (p1 < n) s[p1] = ' ';
			}
			s.erase(p1);
			n = s.length();
		}

		int p1 = 0;
		while (p1 < n && s[p1] == ' ') p1++;
		int p2 = p1;
		while (p2 + 1 < n && s[p2 + 1] != ' ') p2++;
		int ti;
		while (p1 < n)
		{
			ti = (p1 + p2) / 2;
			for (int i = 0; p1 + i <= ti; i++)
			{
				tc = s[p1 + i];
				s[p1 + i] = s[p2 - i];
				s[p2 - i] = tc;
			}
			p1 = p2 + 1;
			while (p1 < n && s[p1] == ' ') p1++;
			p2 = p1;
			while (p2 + 1 < n && s[p2 + 1] != ' ') p2++;
		}
		return s;
	}
};

