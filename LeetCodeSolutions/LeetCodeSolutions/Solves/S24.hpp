
#include <vector>
#include <list>
#include <map>
#include <set>

using namespace std;
/*
 * @lc app=leetcode id=24 lang=cpp
 *
 * [24] Swap Nodes in Pairs
 *
 * https://leetcode.com/problems/swap-nodes-in-pairs/description/
 *
 * algorithms
 * Medium (44.09%)
 * Total Accepted:    301.6K
 * Total Submissions: 684K
 * Testcase Example:  '[1,2,3,4]'
 *
 * Given a linked list, swap every two adjacent nodes and return its head.
 *
 * You may not modify the values in the list's nodes, only nodes itself may be
 * changed.
 *
 *
 *
 * Example:
 *
 *
 * Given 1->2->3->4, you should return the list as 2->1->4->3.
 *
 *
 */

#ifndef LISTNODE
#define LISTNODE
struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}
};
#endif // !ListNode

class S24 {
public:
	ListNode* swapPairs(ListNode* head) {
		if (head == nullptr) return nullptr;
		if (head->next == nullptr) return head;
		ListNode * startt = head->next;
		ListNode * cur = head->next->next;
		ListNode * lastt = head;

		startt->next = head;
		head->next = cur;


		while (cur && cur->next)
		{
			lastt->next = cur->next;
			cur->next = lastt->next->next;
			lastt->next->next = cur;
			lastt = cur;
			cur = cur->next;

		}

		return startt;
	}
};





