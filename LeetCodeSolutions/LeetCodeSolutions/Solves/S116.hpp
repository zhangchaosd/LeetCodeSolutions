
#include <vector>
#include <list>
#include <map>
#include <set>

using namespace std;

/*
 * @lc app=leetcode id=116 lang=cpp
 *
 * [116] Populating Next Right Pointers in Each Node
 */

 // Definition for a Node.
class Node {
public:
	int val;
	Node* left;
	Node* right;
	Node* next;

	Node() {}

	Node(int _val, Node* _left, Node* _right, Node* _next) {
		val = _val;
		left = _left;
		right = _right;
		next = _next;
	}
};

class S116 {
	Node* rooot;
	Node* getad(int dep, int n)
	{
		int nmax = pow(2, dep);
		if (nmax <= n) return NULL;
		int curd = 0;
		int l = 0;
		int r = nmax - 1;
		int m = r / 2;
		Node * res = rooot;
		while (curd != dep)
		{
			if (n <= m)
			{
				r = m;
				m = (r + l) / 2;
				res = res->left;
			}
			else
			{
				l = m + 1;
				m = (r + l) / 2;
				res = res->right;
			}
			curd++;
		}
		return res;
	}
	void dfs(Node * rot, int dep, int n)
	{
		if (!rot)return;
		rot->next = getad(dep, n + 1);
		if (rot->left)
			dfs(rot->left, dep + 1, 2 * n);
		if (rot->right)
			dfs(rot->right, dep + 1, 2 * n + 1);
	}
public:
	Node * connect(Node * root) {
		rooot = root;
		dfs(root, 0, 0);
		return root;
	}
};










