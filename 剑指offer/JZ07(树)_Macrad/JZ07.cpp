#include <iostream>
#include<string>
#include<vector>
#include<stack>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class JZ07Solution {
public:
	//----------------核心代码------------------------------//
	TreeNode* reConstructBinaryTree(vector<int> pre, vector<int> vin) {
		int len = pre.size();

		if (len == 0)
		{
			return NULL;
		}

		vector<int>preLeft, preRight, vinLeft, vinRight;
		TreeNode* root = new TreeNode(pre[0]);

		int rootLocal = 0;    //根结点的位置	
		for (int i = 0; i < len; ++i){
			if (vin[i] == pre[0])
			{
				rootLocal = i;
				break;
			}
	}
    
    //寻找左子树的前序和中序
	for (int i = 0; i < rootLocal; i++)
	{
		vinLeft.push_back(vin[i]);
		preLeft.push_back(pre[i + 1]);
	}
	//寻找右子树的前序和中序
	for (int i = rootLocal + 1; i < len; ++i)
	{
		vinRight.push_back(vin[i]);
		preRight.push_back(pre[i]);
	}

	root->left = reConstructBinaryTree(preLeft, vinLeft);
	root->right = reConstructBinaryTree(preRight, vinRight);

	return root;
}
   	
};


int main()
{
	vector <int> pre,vin;
	int preNum = 0,vinNum = 0,val=0;

	cin >> preNum;
	++preNum;
	while(--preNum){
	    cin >> val;
		pre.push_back(val);
	}
    
	cin >> vinNum;
	++vinNum;
	while (--vinNum) {
		cin >> val;
		vin.push_back(val);
	}


	JZ07Solution Test;
	TreeNode* root;

	root=Test.reConstructBinaryTree(pre, vin);


}
