/*
// Definition for a Node.
class Node {
public:
	int val;
	Node* next;
	Node* random;

	Node(int _val) {
		val = _val;
		next = NULL;
		random = NULL;
	}
};
*/
class Solution {
public:
	Node* copyRandomList(Node* head) {
		if (head == nullptr) { return nullptr; }
		unordered_map <Node*, Node*> map;
		Node *cur = head;

		//复制各个结点，构建新旧结点映射的map
		while (cur != nullptr)
		{
			map[cur] = new Node(cur->val);
			cur = cur->next;
		}

		//串接新链表
		cur = head;
		while (cur != nullptr)
		{
			map[cur]->next = map[cur->next];
			map[cur]->random = map[cur->random];
			cur = cur->next;
		}
		head = map[head];
		return head;
	}
}; 