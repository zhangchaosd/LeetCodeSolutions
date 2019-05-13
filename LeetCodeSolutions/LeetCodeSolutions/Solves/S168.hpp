#include <vector>
#include <string>

using namespace std;

class S168 {
public:
	string convertToTitle(int n) {
		string s0 = "ZABCDEFGHIJKLMNOPQRSTUVWXY";
		string s = "";
		string s2 = "";
		while (n)
		{
			s = s2 + s0[n % 26] + s;
			n = (n - 1) / 26;
		}
		return s;
	}
};


