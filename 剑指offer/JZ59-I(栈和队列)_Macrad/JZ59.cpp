#include <iostream>
#include<string>
#include<vector>
#include<stack>
#include<deque>

using namespace std;
struct ListNode {
	int val;
	ListNode  *next;
	ListNode(int x) :val(x), next(NULL) {}

};


class JZ59Solution {
public:
	//----------------核心代码------------------------------//
	vector<int> maxSlidingWindow(vector<int>& nums, int k) {
		vector<int>res;
		deque<int>maxValue;
		//如果传入空
		if (nums.empty() || k == 0)
		{
			return res;
		}
		// 未形成窗口
		for (int i = 0; i < k; ++i)
		{
			while (!maxValue.empty() && nums[i] > maxValue.back())  //保证单调递减
			{
				maxValue.pop_back();
			}
			maxValue.push_back(nums[i]);
		}
		res.push_back(maxValue.front());
		// 形成窗口
		for (int i = k; i < nums.size(); ++i)
		{
			if (maxValue.front() == nums[i - k])   //是否最大元素是不在窗口的最前面，若在则滑动后删除
				maxValue.pop_front();
			while (!maxValue.empty() && nums[i] > maxValue.back())  //保证单调递减
			{
				maxValue.pop_back();
			}
			maxValue.push_back(nums[i]);
			res.push_back(maxValue.front());
		}


		return res;
	}

};


int main()
{
	
	vector<int> val = { 1,3,-1,-3,5,3,6,7 };
	vector<int>res;
	int k = 3;

	JZ59Solution Test;
	res = Test.maxSlidingWindow(val, k);

	for (auto value : res)
	{
		cout << value << " ";
	}
}
