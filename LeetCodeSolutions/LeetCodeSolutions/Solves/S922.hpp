#include <vector>
using namespace std;
class S922 {
public:
	vector<int> sortArrayByParityII(vector<int>& A) {
		vector<int>o;
		vector<int>e;
		vector<int>ans;
		for (int i : A)
		{
			if (i % 2)
				o.push_back(i);
			else
				e.push_back(i);
		}
		for (int i = 0; i < o.size(); i++)
		{
			ans.push_back(e[i]);
			ans.push_back(o[i]);
		}
		return ans;
	}
};