
class MinStack {
public:
	/** initialize your data structure here. */
	stack<int>S1, S2;
	MinStack() {
	}

	void push(int x) {
		S1.push(x);
		if (S2.empty() || S2.top() >= x)
		{
			S2.push(x);
		}
	}

	void pop() {
		if (S1.top() == S2.top())
		{
			S2.pop();
		}
		S1.pop();

	}

	int top() {
		return S1.top();
	}

	int min() {

		return S2.top();
	}
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->min();
 */



//----------------------------------双向链表对栈就行实现-----------------------------------------//
struct Node {
	Node* next;
	Node* pre;
	int val;
	Node(int x) :val(x), next(NULL), pre(NULL) {}
};

class MinStack {
public:
	MinStack() : dataStack(nullptr), helpStack(nullptr), curD(nullptr), curH(nullptr) {}  //两个栈
	void push(int x);
	void pop();
	int top();
	int min();

private:              //这个MinStack类（容器）占12个字节的大小
	Node* dataStack; //数据栈
	Node* helpStack; //辅助栈
	Node* curD;
	Node* curH;
};

void  MinStack::push(int x) {
	//不能分开写防止 压入俩次元素，辅助栈push元素的条件
	if (helpStack == NULL || curH->val >= x)
	{
		if (helpStack == NULL)
		{
			helpStack = new Node(x);
			curH = helpStack;
			curH->pre = helpStack;
		}
		else
		{
			curH->next = new Node(x);
			curH->next->pre = curH;
			curH = curH->next;
		}
	}

	if (dataStack == NULL)
	{
		dataStack = new Node(x);
		curD = dataStack;
		curD->pre = dataStack;
	}
	else {
		if (curD)
			curD->next = new Node(x);
		curD->next->pre = curD;
		curD = curD->next;
	}
}

void  MinStack::pop() {
	//注意pop时判断是否达到栈底
	if (curD->val == curH->val)
	{
		Node* toDelete = curH;
		if (curH == helpStack) helpStack = nullptr;
		else { curH = curH->pre; curH->next = nullptr; }
		delete toDelete;
		toDelete = nullptr;
	}
	Node* toDelete = curD;
	if (curD == dataStack) dataStack = nullptr;
	else { curD = curD->pre; curD->next = nullptr; }
	delete toDelete;
	toDelete = nullptr;
}
//注意不要对空指针取next、val
int MinStack::top() {
	if (curD) return  curD->val;
	else return NULL;
}
int MinStack::min() {
	if (curH != nullptr) return curH->val;
	else return NULL;
}