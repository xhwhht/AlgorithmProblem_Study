/*
两数相加
1.三目运算的巧妙
2.对于结果链表的头指针判断插入
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

 using namespace std;
static const auto io_sync_off = []() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	return nullptr;
}();
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    int sum=0,carry=0,a,b;
    ListNode *head=nullptr;
    ListNode *pHead=nullptr;
    while(l1||l2)
    {
       a=l1?l1->val:0;
       b=l2?l2->val:0;
       
       sum=a+b+carry;
        
        if(!head)
        {
            head=new ListNode(sum%10);
            pHead=head;
        }
        else
        {
            pHead->next=new ListNode(sum%10);
            pHead=pHead->next;
        }
        carry=sum/10;
        if(l1){l1=l1->next;}
        if(l2){l2=l2->next;}
    }
     if(carry>0)
        {
            pHead->next=new  ListNode(carry);
        }
    pHead=nullptr;
    return head;

    }
};