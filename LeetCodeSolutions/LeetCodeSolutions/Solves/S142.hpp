
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
class S142 {
	void noo()
	{
		printf("no cycle\n");
	}
public:
	ListNode* detectCycle(ListNode* head) {
		if (head == 0) { noo(); return 0; }
		if (head->next == 0) { noo(); return 0; }
		ListNode* p1 = head;
		ListNode* p2 = head;
		do
		{
			p1 = p1->next;
			if (p1)
				p1 = p1->next;
			if (p1 == 0)
			{
				noo(); return 0;
			}
			p2 = p2->next;
		} while (p1 != p2);
		ListNode * ans = head;
		int op = 0;
		while (ans != p2)
		{
			ans = ans->next;
			p2 = p2->next;
			op++;
		}
		printf("tail connects to node index %d", op);
		return ans;
	}
};

