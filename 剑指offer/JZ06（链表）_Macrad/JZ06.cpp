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
		while (head != NULL)
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
	}
	head = beforeHead->next;
	delete beforeHead;

	cout << endl;
	cout << "放头指针的地址:" << endl;
	cout << &(head) << endl;

	cout << endl;
	cout << "首节点的地址（==首节点value的地址）:" << endl;
	cout << head << endl;
	cout << &(head->val) << endl;

	
	cout << endl;
	cout << "打印链表:" << endl;
	
	ListNode* curRead = head;
	while (curRead != NULL) //curRead！=NULL 和后面不一样curRead->next!=NULL  curRead地址 curRead->next curRead地址里放的内容
	{
		cout << curRead->val << ' ';
		curRead = curRead->next;
	}
	
	
	cout << endl;
	cout << endl;
	cout << "打印逆序输出的结果:" << endl;

	JZ06Solution Test;
	vector<int>res;
	res = Test.printListFromTailToHead(head);
	for (int num : res)
	{
		cout << num << ' ';
	}
	cout << endl;
	cout << endl;
	cout << "打印逆序输出后的头指针的地址以及指向首节点的地址:" << endl;
	cout << &head << endl;
	cout << head;
	cout << endl;
	
}

