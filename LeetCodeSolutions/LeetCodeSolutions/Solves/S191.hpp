#include <vector>
#include <string>
#include <list>

using namespace std;

class S191{
public:
	int hammingWeight(uint32_t n) {
		int res = 0;
		while (n)
		{
			res += n % 2;
			n = n >> 1;
		}
		return res;
	}
};
