
#include <vector>
#include <list>
#include <map>
#include <set>

using namespace std;
/*
 * @lc app=leetcode id=25 lang=cpp
 *
 * [25] Reverse Nodes in k-Group
 *
 * https://leetcode.com/problems/reverse-nodes-in-k-group/description/
 *
 * algorithms
 * Hard (35.97%)
 * Total Accepted:    177.4K
 * Total Submissions: 493.3K
 * Testcase Example:  '[1,2,3,4,5]\n2'
 *
 * Given a linked list, reverse the nodes of a linked list k at a time and
 * return its modified list.
 *
 * k is a positive integer and is less than or equal to the length of the
 * linked list. If the number of nodes is not a multiple of k then left-out
 * nodes in the end should remain as it is.
 *
 *
 *
 *
 * Example:
 *
 * Given this linked list: 1->2->3->4->5
 *
 * For k = 2, you should return: 2->1->4->3->5
 *
 * For k = 3, you should return: 3->2->1->4->5
 *
 * Note:
 *
 *
 * Only constant extra memory is allowed.
 * You may not alter the values in the list's nodes, only nodes itself may be
 * changed.
 *
 *
 */
 /**
  * Definition for singly-linked list.
  * struct ListNode {
  *     int val;
  *     ListNode *next;
  *     ListNode(int x) : val(x), next(NULL) {}
  * };
  */

#ifndef LISTNODE
#define LISTNODE
struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}
};
#endif // !ListNode

class S25 {
public:
	ListNode* reverseKGroup(ListNode* head, int k) {
		if (head == 0) return nullptr;
		if (k == 1) return head;
		int cnt = 0;
		ListNode * startt = head;
		while (startt)
		{
			cnt++;
			startt = startt->next;
		}

		int rn = cnt / k;
		if (rn == 0) return head;

		ListNode * cur = head;
		startt = new ListNode(0);
		startt->next = head;
		ListNode * lastt = startt;
		for (int i = 0; i < rn; i++)
		{
			ListNode* nextd = cur;
			for (int j = 0; j < k; j++)
				nextd = nextd->next;
			ListNode * tn = cur->next;
			ListNode * tn2;
			cur->next = nextd;
			ListNode * lasttt = cur;
			for (int j = 0; j < k - 1; j++)
			{
				tn2 = tn->next;

				tn->next = lasttt;
				lasttt = tn;
				tn = tn2;
			}

			lastt->next = lasttt;//??
			lastt = cur;
			cur = nextd;
		}
		ListNode* ans = startt->next;
		delete startt;
		return ans;
	}
};







