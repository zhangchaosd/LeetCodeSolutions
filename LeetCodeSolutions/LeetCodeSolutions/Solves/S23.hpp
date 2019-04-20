
#include <vector>
#include <list>
#include <map>
#include <set>

using namespace std;
/*
 * @lc app=leetcode id=23 lang=cpp
 *
 * [23] Merge k Sorted Lists
 *
 * https://leetcode.com/problems/merge-k-sorted-lists/description/
 *
 * algorithms
 * Hard (33.88%)
 * Total Accepted:    370.7K
 * Total Submissions: 1.1M
 * Testcase Example:  '[[1,4,5],[1,3,4],[2,6]]'
 *
 * Merge k sorted linked lists and return it as one sorted list. Analyze and
 * describe its complexity.
 *
 * Example:
 *
 *
 * Input:
 * [
 * 1->4->5,
 * 1->3->4,
 * 2->6
 * ]
 * Output: 1->1->2->3->4->4->5->6
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

class Solution {
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
public:
	ListNode* mergeKLists(vector<ListNode*>& lists) {
		if (lists.empty()) return nullptr;
		vector<ListNode*>anss;
		//anss=lists;
		while (lists.size() > 1)
		{

			for (int i = 0; i < lists.size() / 2; i++)
			{
				anss.push_back(mergeTwoLists(lists[i * 2], lists[i * 2 + 1]));

			}
			if (lists.size() % 2)
				anss.push_back(lists[lists.size() - 1]);


			lists = anss;
			anss.clear();
		}




		return lists[0];
	}
};



