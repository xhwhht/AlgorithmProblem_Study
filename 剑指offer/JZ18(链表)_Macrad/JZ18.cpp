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

class JZ18Solution {
public:
	//----------------核心代码------------------------------//
	ListNode* deleteNode(ListNode* head,ListNode* ToBeDeleted) {
   
		if (ToBeDeleted->next != NULL)  //删除的不是尾节点
		{
			ListNode* pNext = ToBeDeleted->next;
			*ToBeDeleted = *pNext;
			
			delete pNext;
			pNext = nullptr;
		}
		else if (head == ToBeDeleted)    //只有一个节点
		{
			delete ToBeDeleted;
			ToBeDeleted = nullptr;
			head = nullptr;
		}
		else                             //删除尾节点  需要寻找前一个节点     
		{
			ListNode* curNode = head;
			while (curNode->next != ToBeDeleted)
			{
				curNode = curNode->next;
			}

			curNode->next = nullptr;
			delete ToBeDeleted;
			ToBeDeleted = nullptr;
			curNode = nullptr;
		
		}

		return head;
	
	}

};


int main()
{
	ListNode* beforeHead = new ListNode(-1);
	ListNode* cur, *head;
	cur = beforeHead;

	int n, val;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> val;

		ListNode* newNode = new ListNode(val);  //导致内存会有其他位置存此节点的地址
		cur->next = newNode;
		cur = newNode;
		newNode = nullptr;
	}
	head = beforeHead->next;

	cout << endl;
	cout << "打印链表:" << endl;
	
	ListNode* curRead = head;
	while (curRead != NULL) //curRead！=NULL 和后面不一样curRead->next!=NULL  curRead地址 curRead->next curRead地址里放的内容
	{
		cout << curRead->val << ' ';
		curRead = curRead->next;
	}
	
	//清理
	delete beforeHead;
	beforeHead = nullptr;
	curRead = nullptr;
	cur = nullptr;

	cout << endl;
	cout << endl;
	cout << "打印的结果:" << endl;

	
	JZ18Solution Test;
	ListNode *ToBeDeleted;
	ToBeDeleted = head->next;
	Test.deleteNode(head,ToBeDeleted);

	while (head != NULL) //curRead！=NULL 和后面不一样curRead->next!=NULL  curRead地址 curRead->next curRead地址里放的内容
	{
		cout << head->val << ' ';
		head = head->next;
	}

	ToBeDeleted = nullptr;
}


/*
//-------------------------牛客网上的版本----------------------------------------//
// 最上面是书上指定位置删除
//  下面使用的是后面的节点覆盖注意覆盖的写法
ListNode* deleteNode(ListNode* head, int val) {
ListNode *cur=head,*pBehind=head;

if(cur->next==NULL)
{
	return head;
}
else
{
	pBehind=head->next;
	while(cur!=NULL)
	{
		if(cur->val==val)
		{
			*cur = *pBehind;
			break;
		}
		else
		{
			cur=cur->next;
			if(pBehind->next!=NULL)
			{
				pBehind=pBehind->next;
			}
			else
			{
				*cur=*pBehind;
			}
		}
	}
	return head;
}
}
*/