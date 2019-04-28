#include <cstdio>

#include <vector>

#include <map>
#include <algorithm>
//#include <cstring>
#include <string>
#include <set>

#include "ListNode.h"

#include "Solves\S13.hpp"
#include "Solves\S15.hpp"
#include "Solves\S20.hpp"
#include "Solves\S21.hpp"
#include "Solves\S23.hpp"
#include "Solves\S24.hpp"
#include "Solves\S25.hpp"
#include "Solves\S26.hpp"
#include "Solves\S28.hpp"
#include "Solves\S33.hpp"
#include "Solves\S39.hpp"
#include "Solves\S46.hpp"
#include "Solves\S47.hpp"
#include "Solves\S48.hpp"
#include "Solves\S53.hpp"
#include "Solves\S54.hpp"
#include "Solves\S55.hpp"
#include "Solves\S56.hpp"
#include "Solves\S73.hpp"
#include "Solves\S75.hpp"
#include "Solves\S79.hpp"
#include "Solves\S88.hpp"
#include "Solves\S91.hpp"
#include "Solves\S410.hpp"
#include "Solves\S922.hpp"
#include "Solves\S994.hpp"
#include "Solves\S1029.hpp"
#include "Solves\S1031.hpp"
#include "Solves\S5040.hpp"
#include "Solves\S5039.hpp"

using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution318 {
public:
	int maxProduct(vector<string> & words) {
		if (words.size() <= 1) return 0;

		vector<int> arr(words.size(), 0);
		for (int i = 0; i < words.size(); i++) {
			for (int j = 0; j < words[i].length(); j++) {
				arr[i] = (arr[i] | (1 << (words[i][j] - 'a')));
			}
		}
		int res = 0;
		for (int i = 0; i < words.size(); i++) {
			//cout<<arr[i]<<' ';
			for (int j = i + 1; j < words.size(); j++) {
				// judge whether there exists common alphabets between the two words.
				if ((arr[i] & arr[j]) == 0) {
					res = max(res, (int)(words[i].length() * words[j].length()));
				}
			}
		}

		return res;
	}
};

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec449 {

public:
	string s;
	int f;
	string int2s(int a)
	{
		char c1, c2, c3, c4;
		char* p = (char*)& a;
		c1 = *p;
		c2 = *(p + 1);
		c3 = *(p + 2);
		c4 = *(p + 3);
		int cs = 0;
		if (c4 != 0)cs++;
		if (c3 != 0)cs++;
		if (c2 != 0)cs++;
		if (c1 != 0)cs++;

		if (cs == 0)
		{
			string ts = "5";
			ts[0] = 5;
			return ts;
		}
		else if(cs == 1)
		{
			string ts = "12";
			ts[0] = cs;
			ts[1] = c1;
			return ts;
		}
		else if (cs == 2)
		{
			string ts = "123";
			ts[0] = cs;
			ts[1] = c1;
			ts[2] = c2;
			return ts;
		}
		else if (cs == 3)
		{
			string ts = "1234";
			ts[0] = cs;
			ts[1] = c1;
			ts[2] = c2;
			ts[3] = c3;
			return ts;
		}
		else if (cs == 4)
		{
			string ts = "12345";
			ts[0] = cs;
			ts[1] = c1;
			ts[2] = c2;
			ts[3] = c3;
			ts[4] = c4;
			return ts;
		}
	}
	void se(TreeNode* root)
	{
		if (root == nullptr) return;

		if (root->left && root->left->val == root->val) f = -1;
		if (root->right && root->right->val == root->val) f = 1;
		s += int2s(root->val);
		se(root->left);
		se(root->right);
	}

	// Encodes a tree to a single string.
	string serialize(TreeNode * root) {
		f = 0;
		s = "";
		if (root == nullptr)return s;
		se(root);
		string s2 = f == 1 ? "2" : (f == -1 ? "0" : "1");
		string s3 = s2 + s;
		return s3;
	}
	vector<int>t;
	int f2;

	TreeNode * bt(int s, int e)
	{
		if (s > e)return nullptr;
		if (s >= t.size())return nullptr;
		TreeNode * tt = new TreeNode(t[s]);

		if (s == e)return tt;

		int rs = s + 1;
		if (f2 == -1 || f2 == 0)
		{
			for (; t[rs] <= tt->val;)
				rs++;
		}
		else if (f2 == 1)
		{
			for (; t[rs] < tt->val;)
				rs++;
		}
		tt->left = bt(s + 1, rs - 1);
		tt->right = bt(rs, e);
		return tt;
	}
	// Decodes your encoded data to tree.
	void getints(string s)
	{
		for (int i = 1; i < s.length();)
		{
			int c1=0, c2=0, c3=0, c4=0;
			int cs = s[i];
			if (cs == 5)
			{
				t.push_back(0);
				i++;
				continue;
			}
			if (cs == 4)
			{
				c1 = s[i + 1];
				c2 = s[i + 2];
				c3 = s[i + 3];
				c4 = s[i + 4];
			}

			if (cs == 3)
			{
				c2 = s[i + 1];
				c3 = s[i + 2];
				c4 = s[i + 3];
			}

			if (cs == 2)
			{
				c3 = s[i + 1];
				c4 = s[i + 2];
			}

			if (cs == 1)
				c4 = s[i + 1];

			int num = (c1 << 24) | (c2 << 16) | (c3 << 8) | c4;
			t.push_back(num);
			i += cs;
			i++;
		}
	}
	TreeNode * deserialize(string data) {
		if (data.length() == 0)return nullptr;
		if (data[0] == '0') f2 = -1;
		else if (data[0] == '1') f2 = 0;
		else if (data[0] == '2') f2 = 1;
		getints(data);
		TreeNode* ans = bt(0, t.size() - 1);
		return ans;
	}
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));

class Solution636 {
	//Solution636 s636;
	//vector<string>v = { "0:start:0","0:end:0","1:start:1","1:end:1","2:start:2","2:end:2","2:start:3","2:end:3" };
	//vector<int>v2 = s636.exclusiveTime(3, v);

	void anstring(string& s, int& no, int& timee, int& dir)
	{
		if (s[1] == ':')
		{
			no = s[0] - ('0' - 0);
			if (s[2] == 's')
				dir = 1;
			else
				dir = 0;
		}
		else
		{
			int shi = no = s[0] - ('0' - 0);
			int ge = no = s[1] - ('0' - 0);
			no = shi * 10 + ge;
			if (s[3] == 's')
				dir = 1;
			else
				dir = 0;
		}
		timee = 0;
		int startidx;
		if (no > 9 && dir == 1)
			startidx = 9;
		else if (no < 10 && dir == 0)
			startidx = 6;
		else if (dir == 1)
			startidx = 8;
		else
			startidx = 7;

		auto it = s.begin() + startidx;
		for (int i = startidx;; i++)
		{
			if (it != s.end())
			{
				int t = (*it) - '0';
				timee *= 10;
				timee += t;
				it++;
			}
			else
				break;
		}
	}
public:
	vector<int> exclusiveTime(int n, vector<string>& logs) {
		vector<int>ans(n, 0);
		int asize = logs.size();
		string s;
		int num;
		int timee;
		int dir = -1;//1 start   0end
		int lastTime = -1;
		int lastNum = -1;
		int lastDir = -1;
		vector<int>stackk;
		for (int i = 0; i < asize; i++)
		{
			s = logs[i];
			anstring(s, num, timee, dir);

			if (lastTime != -1)
			{
				if (dir == 1)
				{
					if (lastDir == 1)
					{
						ans[stackk[stackk.size() - 1]] += (timee - lastTime);
					}
					else
					{
						if(stackk.size())
							ans[stackk[stackk.size() - 1]] += (timee - lastTime - 1);
					}

					stackk.push_back(num);
				}
				else if (dir == 0)
				{
					stackk.pop_back();
					if (lastDir == 1)
					{
						ans[lastNum] += (timee - lastTime + 1);
					}
					else
					{
						ans[num] += (timee - lastTime);
					}
				}
			}
			else
			{
				stackk.push_back(num);
			}

			lastTime = timee;
			lastNum = num;
			lastDir = dir;
		}


		return ans;
	}
};

class Solution667 {
public:
	vector<int> constructArray(int n, int k) {
		vector<int>ans;
		if (k == 1)
		{
			for (int i = 1; i <= n; i++)
				ans.push_back(i);
			return ans;
		}
		for (int i = 0; i < n - k; i++)
		{
			ans.push_back(n - k - i);
		}
		
		bool da = true;
		int tmin = n-k+1;
		int tmax = n;
		for (int i = 0; i < k; i++)
		{
			if (da)
			{
				ans.push_back(tmax);
				tmax--;
			}
			else
			{
				ans.push_back(tmin);
				tmin++;
			}
			da = !da;
		}

		return ans;
	}
};

class Solution720 {
public:
	static bool cmp(string& s1, string& s2)
	{
		for (int i = 0; i < s1.length(); i++)
		{
			if (s1[i] != s2[i])
				return s1[i] < s2[i];
		}
	}
	bool cp(string s1, string s2)
	{
		for (int i = 0; i < s1.length(); i++)
			if (s1[i] != s2[i])
				return false;
		return true;
	}
	string longestWord(vector<string> & words) {
		
		vector<set<string> >tong(32);
		set<string>las;
		set<string>nex;
		vector<string>ans;
		for (int i = 0; i < words.size(); i++)
		{
			tong[words[i].length()].insert(words[i]);
		}
		las = tong[1];
		for (int i = 2; i < 32; i++)
		{
			las = tong[i - 1];
			for (auto it = las.begin(); it != las.end(); it++)
			{
				for (auto it2 = tong[i].begin(); it2 != tong[i].end(); it2++)
				{
					if (cp(*it, *it2))
					{
						nex.insert(*it2);
					}
				}
			}
			if (nex.empty())
			{
				for (auto it = las.begin(); it != las.end(); it++)
				{
					ans.push_back(*it);
				}
				sort(ans.begin(), ans.end(), cmp);
				return ans[0];
			}
			tong[i] = nex;//////
			nex.clear();
		}
	}
};

class Solution858 {


	int pp;
	int qq;
	int zuidagongyueshu;
	int detp;
	int detq;

	void getgy()
	{
		zuidagongyueshu = 1;
		for (int i = 2; i < qq; i++)
		{
			if (((pp / i) * i == pp) && ((qq / i) * i == qq))
				zuidagongyueshu = i;
		}
		detp = pp / zuidagongyueshu;
		detq = qq / zuidagongyueshu;
	}


public:
	int mirrorReflection(int p, int q) {
		if (q == 0)
			return 0;
		if (q == p)
			return 1;
		pp = p; qq = q;
		getgy();
		int nowx = 0;
		int nowy = 0;
		while (1)
		{
			printf("one turn\n");
			nowx += detp;
			nowy += detq;
			if ((nowy / pp) * pp == nowy)
			{
				int ju = nowx % p;
				int pn = nowx / p;
				int ny = nowy / p;
				if (pn * p == nowx)
				{
					if (ny % 2 == 0)
						return 0;
					if (pn % 2)
						return 1;
					else
						return 2;
				}
				else if (ju * 2 == p)
					return 0;
			}
		}
	}
};

class Solution976 {

	//Solution976 s976;
	//vector<int>v = { 2,1,2 };//5
	//vector<int>v1 = { 1,2,1 };//0
	//vector<int>v2 = { 3,2,3,4 };//10
	//vector<int>v3 = { 3,6,2,3 };//8
	//printf("%d %d %d %d", s976.largestPerimeter(v), s976.largestPerimeter(v1), s976.largestPerimeter(v2), s976.largestPerimeter(v3));


public:
	static bool cmp(int &a, int &b)
	{
		return a > b;
	}

	void getmaxs(int a, int b, int c, int& m1, int& m2, int& m3)
	{
		int t;
		if (a < b)
		{
			t = a;
			a = b;
			b = t;
		}
		if (a < c)
		{
			t = a;
			a = c;
			c = t;
		}
		if (b < c)
		{
			t = b;
			b = c;
			c = t;
		}
		m1 = a;
		m2 = b;
		m3 = c;
	}

	bool cans(const int& a, const int& b, const int& c)
	{
		return b + c > a;
	}


	int largestPerimeter(vector<int>& A) {
		//solve 2:
		//bad
		/*int asize1 = A.size();
		int res = 0;
		int max1 = -1;
		int max2 = -1;
		int max3 = -1;
		int startidx = 2;
		for (int i = 2; i < asize1; i++)
		{
			if (i == startidx)
			{
				getmaxs(A[0], A[1], A[2], max1, max2, max3);
				if (max2 + max3 > max1)
				{
					res = max1 + max2 + max3;
				}
			}
			else
			{
				if (A[i] > max3)
				{
					if (A[i] <= max2)
					{
						max3 = A[i];
					}
					else if (A[i] <= max1)
					{
						max3 = max2;
						max2 = A[i];
					}
					else
					{
						if (cans(A[i], max1, max2))
						{
							max3 = max2;
							max2 = max1;
							max1 = A[i];
						}
						else
							continue;
					}

					res = max1 + max2 + max3;
				}
			}
		}
		return res;*/

		//solve 1:
		int asize = A.size();
		partial_sort(A.begin(), A.begin() + 3, A.end(), &cmp);
		for (int i = 0; i+2 < asize; i++)
		{
			if (A[i] < A[i + 1] + A[i + 2])
				return A[i] + A[i + 1] + A[i + 2];

			if (i%3 == 0)
			{
				if(i+6<= asize)
					partial_sort(A.begin() + i+3, A.begin() + i + 6, A.end(), &cmp);
				else if(i + 5== asize)
					partial_sort(A.begin() + i + 3, A.begin() + i + 5, A.end(), &cmp);
			}

		}
		return 0;
	}
};

class Solution983 {



public:
	int mincostTickets(vector<int> & days, vector<int> & costs) {
		int lastd = days[days.size() - 1];
		vector<int>ans(lastd + 32, -1);
		{
			vector<char> isFree(lastd + 32, 0);


			for (int i = 0; i < days.size(); i++)
			{
				isFree[days[i]] = 1;
			}


			ans[0] = 0;

			for (int i = 1; i <= lastd; i++)
			{
				if (isFree[i] == 1)
				{
					for (int j = 0; j < 30; j++)
					{
						if (isFree[i + j] == 0)
						{
							ans[i + j] = ans[i + j - 1];
							continue;
						}
						else if (ans[i + j] == -1)
						{
							ans[i + j] = ans[i + j - 1] + costs[0];
						}
						if (j == 0)
						{
							if (ans[i - 1] + costs[0] < ans[i + j])
								ans[i + j] = ans[i - 1] + costs[0];
						}
						if (j < 7)
						{
							if (costs[1] < costs[2])
							{
								if (ans[i - 1] + costs[1] < ans[i + j])
									ans[i + j] = ans[i - 1] + costs[1];
							}
							else
							{
								if (ans[i - 1] + costs[2] < ans[i + j])
									ans[i + j] = ans[i - 1] + costs[2];
							}
						}
						else
						{
							if (ans[i - 1] + costs[2] < ans[i + j])
								ans[i + j] = ans[i - 1] + costs[2];
						}
					}
				}
				else
					ans[i] = ans[i - 1];
			}
		}

		return ans[lastd];
	}
};

class Solution990 {

	vector<int> nods;

	int fdp(int a)
	{
		int p = 26;
		int ta = a;
		while (nods[a] != a)
			a = nods[a];

		return a;

	}

	void cn(int pa, int pb)
	{
		nods[pa] = pa;
	}

	bool suc(string s)
	{
		int pa = fdp(s[0]);
		int pb = fdp(s[3]);
		if (pa == pa && s[1] == '!') return false;
		else if (pa == pb && s[1] == '=') return true;
		if (pa != pb && s[1] == '!') return true;
		else {
			cn(pa, pb);
		}
		return true;
	}

public:
	bool equationsPossible(vector<string>& equations) {

		for (int i = 0; i < 26; i++)
		{
			nods.push_back(i);
		}
		for (int i = 0; i < equations.size(); i++)
		{
			if (!suc(equations[i]))
				return false;
		}
		return true;
	}
};



class Solution5024 {
	vector<int>ans;

	bool canWin(int N)
	{
		if (N == 1)return false;
		if (N == 2)return true;
		if (N == 3)return false;
		if (ans[N] != -1)
			return ans[N];
		vector<int>xs;
		for (int i = 1; i < N; i++)
		{
			if (N % i == 0)
				xs.push_back(i);
		}
		for (int i = 0; i < xs.size(); i++)
		{
			if (!canWin(N - xs[i]))
			{
				ans[N] = 1;
				return true;
			}
		}
		ans[N] = 0;
		return false;

	}
public:
	bool divisorGame(int N) {
		ans = vector<int>(1001, -1);
		ans[0] = 0;
		ans[1] = 0;
		ans[2] = 1;
		ans[3] = 0;
		return canWin(N);
	}
};

int main()
{
	S15 s;
	vector<int>v1 = { 1,-1,-1,0 };
	vector<int>v2 = { 1,1,0 };
	vector<int>v3 = { 0,1,1 };

	vector<vector<int> >v = { v1,v2,v3 };

	printf("%d",s.threeSum(v1));


	return 0;
}