#pragma once

#ifndef TREENODE
#define TREENODE
struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
#endif // !ListNode
