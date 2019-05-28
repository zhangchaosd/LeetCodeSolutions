#include <vector>
#include <string>
#include <list>
#include <map>

using namespace std;

/*
 * @lc app=leetcode id=237 lang=cpp
 *
 * [237] Delete Node in a Linked List
 */
 /**
  * Definition for singly-linked list.
  * struct ListNode {
  *     int val;
  *     ListNode *next;
  *     ListNode(int x) : val(x), next(NULL) {}
  * };
  */
class S237 {
public:
	void deleteNode(ListNode* node) {
		ListNode* net = node->next;
		while (net)
		{
			node->val = net->val;


			if (net->next == nullptr)
			{
				delete net;
				node->next = nullptr;
				break;
			}
			node = net;
			net = node->next;
		}
	}
};



