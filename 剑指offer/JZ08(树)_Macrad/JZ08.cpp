#include <iostream>
#include<string>
#include<vector>
#include<stack>
/*
struct TreeLinkNode {
	int val;
	struct TreeLinkNode *left;
	struct TreeLinkNode *right;
	struct TreeLinkNode *next;
	TreeLinkNode(int x) :val(x), left(NULL), right(NULL), next(NULL) {

	}
};
*/
class Solution {
public:
	TreeLinkNode* GetNext(TreeLinkNode* pNode) {
		if (!pNode)return nullptr;
		if (pNode->right)
		{
			pNode = pNode->right;
			while (pNode->left)pNode = pNode->left;
			return pNode;
		}
		while (pNode->next)
		{
			TreeLinkNode* root = pNode->next;
			if (root->left == pNode)return root;
			else pNode = root;
		}
		return nullptr;
	}
};