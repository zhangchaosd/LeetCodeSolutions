
#include <vector>
#include <list>
#include <map>
#include <set>

using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class S141 {
public:
	bool hasCycle(ListNode* head) {
		if (head == 0)return false;
		if (head->next == 0)return false;
		ListNode * p1 = head->next;
		ListNode * p2 = head;
		while (p1 != p2)
		{
			p1 = p1->next;
			if (p1)
				p1 = p1->next;
			if (p1 == 0)
				return false;
			p2 = p2->next;
		}
		return true;
	}
};


