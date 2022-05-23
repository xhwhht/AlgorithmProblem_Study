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

class JZ06Solution {
public:
	//----------------核心代码------------------------------//
	vector<int> res;
	vector<int> printListFromTailToHead(ListNode* head) {
    
    //-----------栈-----------------------------------//
		stack<int>ListNodeVal;
		cout << &head<<endl;
		cout << head;
		while (head!= NULL)
		{
			ListNodeVal.push(head->val);
	        head = head->next;
		}

		while (!ListNodeVal.empty())
		{
		   res.push_back(ListNodeVal.top());
		   ListNodeVal.pop();
		}

/* //-----------递归（系统栈）-----------------------------------//
	if (head != NULL)
	{
		if (head->next != NULL)
		{
		
			printListFromTailToHead(head->next);
			
		}
		res.push_back(head->val);
	}
	*/

	return res;
	}

};


int main()
{
	ListNode* head = new ListNode(0);
	ListNode* cur = head;

	int n,val;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> val;
		ListNode* newNode = new ListNode(val);
		cur->next = newNode;
		cur = newNode;
	}

	//ListNode curRead = *head;
	ListNode* curRead = head;
	
	
	cout <<"放头节点的地址"<< endl;
	cout << &(curRead) << endl;
	cout << &(head) << endl;


	cout <<endl;
	cout << "头节点->next 的地址" << endl;
	cout << &(curRead->next) << endl;
	cout << &(head->next) << endl;


	cout << "头节点的地址放的内容;val的地址" << endl;
	cout << head << endl;
	cout << *(&(curRead))<<endl;
	cout << *(&(head))<<endl;

	cout << endl;
	cout << *(&(curRead->next)) << endl;
	cout << *(&(head->next)) << endl;
	cout << (curRead->next) << endl;
	cout << (head->next) << endl;

	cout << "头节点的Val地址" << endl;
	cout << &((*(&(curRead)))->val) << endl;
	cout << &((*(&(head)))->val) << endl;

	cout << "头节点的Val" << endl;
	cout << (*(&(curRead)))->val<< endl;
	cout << (*(&(head)))->val << endl;

	cout << "头节点的next即第一节点的地址（ListNode数据结构）" << endl;
	cout << (*(&(curRead)))->next << endl;
	cout << (*(&(head)))->next << endl;
	
	cout << "打印链表:" << endl;
	while (curRead!=NULL) //curRead！=NULL 和后面不一样curRead->next!=NULL  curRead地址 curRead->next curRead地址里放的内容
	{
		//cout << &(curRead->val)<< ' '<< curRead<<' '<< *(&(curRead->val));
		//cout << &(curRead->next);
		cout << curRead->val;
		curRead = curRead->next;
		cout << endl;
	}
	cout << endl;


	JZ06Solution Test;
	vector<int>res;
    res=Test.printListFromTailToHead(head);
	
	cout << endl;
	for (int num : res)
	{
		cout << num<<' ';
	}
	cout << endl;
	cout << &head << endl;
	cout << head;
}

