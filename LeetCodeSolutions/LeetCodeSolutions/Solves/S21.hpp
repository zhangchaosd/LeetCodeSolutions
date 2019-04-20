
#include <vector>
#include <list>
#include <map>
#include <set>

using namespace std;
/*
 * @lc app=leetcode id=21 lang=cpp
 *
 * [21] Merge Two Sorted Lists
 *
 * https://leetcode.com/problems/merge-two-sorted-lists/description/
 *
 * algorithms
 * Easy (46.69%)
 * Total Accepted:    554.9K
 * Total Submissions: 1.2M
 * Testcase Example:  '[1,2,4]\n[1,3,4]'
 *
 * Merge two sorted linked lists and return it as a new list. The new list
 * should be made by splicing together the nodes of the first two lists.
 *
 * Example:
 *
 * Input: 1->2->4, 1->3->4
 * Output: 1->1->2->3->4->4
 *
 *
 */
 

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


class S21 {
public:
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		ListNode* p1 = l1;
		ListNode* p2 = l2;
		ListNode* startt = 0;
		ListNode* lastt = 0;
		if (l1 == 0)return l2;
		if (l2 == 0)return l1;

		if (p1->val > p2->val)
		{
			startt = p2;
			p2 = p2->next;
		}
		else
		{
			startt = p1;
			p1 = p1->next;
		}
		lastt = startt;
		while (p1 && p2)
		{
			if (p1->val > p2->val)
			{
				lastt->next = p2;
				lastt = p2;
				p2 = p2->next;
			}
			else
			{
				lastt->next = p1;
				lastt = p1;
				p1 = p1->next;
			}
		}
		if (p1)lastt->next = p1;
		if (p2)lastt->next = p2;


		return startt;
	}
};


