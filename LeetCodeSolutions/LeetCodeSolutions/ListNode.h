#pragma once

#ifndef LISTNODE
#define LISTNODE
struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}
};
#endif // !ListNode
