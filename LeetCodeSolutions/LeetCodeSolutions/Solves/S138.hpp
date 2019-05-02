
#include <vector>
#include <list>
#include <map>
#include <set>

using namespace std;


// Definition for a Node.
class Node138 {
public:
	int val;
	Node138* next;
	Node138* random;

	Node138() {}

	Node138(int _val, Node138* _next, Node138* _random) {
		val = _val;
		next = _next;
		random = _random;
	}
};

class S138 {
	map<Node138*, int>ptoi;
	map<int, Node138*>itop;
	map<int, Node138*>itop2;
public:
	Node138* copyRandomList(Node138* head) {
		if (head == 0)return 0;
		Node138* ans = new Node138(head->val, 0, 0);
		Node138* tp;
		Node138* las = ans;
		itop2[1] = ans;
		ptoi[head] = 1;
		if (head->random)
			itop[1] = head->random;
		head = head->next;
		int cnt = 2;
		while (head)
		{
			tp = new Node138(head->val, 0, 0);
			itop2[cnt] = tp;
			ptoi[head] = cnt;
			if (head->random)
				itop[cnt] = head->random;
			las->next = tp;
			las = tp;
			cnt++;
			head = head->next;
		}
		for (auto i : itop)
		{
			itop2[i.first]->random = itop2[ptoi[i.second]];
		}
		return ans;
	}
};


