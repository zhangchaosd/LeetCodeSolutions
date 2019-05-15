#include <vector>
#include <string>
#include <list>

using namespace std;

/*
 * @lc app=leetcode id=206 lang=cpp
 *
 * [206] Reverse Linked List
 */
 /**
  * Definition for singly-linked list.
  * struct ListNode {
  *     int val;
  *     ListNode *next;
  *     ListNode(int x) : val(x), next(NULL) {}
  * };
  */
class S206 {
public:
	ListNode* reverseList(ListNode* head) {
		if (!head)return NULL;
		ListNode* las = NULL;
		ListNode* p1 = head;
		ListNode* p2 = head->next;
		while (p2)
		{
			p1->next = las;
			las = p1;
			p1 = p2;
			p2 = p2->next;
		}
		p1->next = las;
		return p1;
	}

	ListNode* reverseList2(ListNode* head) {
		if (!head)return NULL;
		ListNode* p1 = head;
		ListNode* p2 = reverseList(head->next);
		p1->next = 0;
		ListNode* p3 = p2;
		while (p3 && p3->next)
			p3 = p3->next;
		if (p3)
			p3->next = p1;
		else
		{
			p2 = p1;
		}
		return p2;
	}
};

