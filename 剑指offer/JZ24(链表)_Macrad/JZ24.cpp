#include <iostream>
#include<string>
#include<vector>
#include<stack>

using namespace std;
struct ListNode {
	int val;
	ListNode  *next;
	ListNode(int x) :val(x), next(NULL) {}

};


class JZ24Solution {
public:
	//----------------核心代码------------------------------//
	ListNode* reverseList(ListNode* head) {
    return   recur(head, NULL);
	}
	private:
		ListNode*  recur(ListNode* cur,ListNode* pre);
};

ListNode* JZ24Solution::recur(ListNode* cur, ListNode* pre)
{
	if (cur == nullptr)
	{
		return pre;
	}

	ListNode*res = recur(cur->next, cur);
	cur->next = pre;
	return res;

}

int main()
{
	ListNode* beforeHead = new ListNode(-1);
	ListNode* cur;
	cur = beforeHead;

	vector<int> val = { 1,2,3,4,5 };
	for (int i = 0; i <val.size(); ++i)
	{

		ListNode* newNode = new ListNode(val[i]);  //导致内存会有其他位置存此节点的地址
		cur->next = newNode;
		cur = newNode;
	}
	ListNode* head;
	head = beforeHead->next;
	delete beforeHead;

	JZ24Solution Test;
	ListNode* res;
	res = Test.reverseList(head);
	for (int i=0; i < val.size(); i++)
	{
		cout << res->val<<" ";
		res = res->next;
	}
}
/*
  ListNode* reverseList(ListNode* head) {
	ListNode* behind=head;
	ListNode* before=NULL;
	ListNode* cur;
	while(behind)
	{
		cur=behind;
		behind=cur->next;
		cur->next=before;
		before=cur;
	}
	head=before;
	behind=nullptr;
	cur=nullptr;
	before=nullptr;        //可直接返回before
	return head;
	}         
*/