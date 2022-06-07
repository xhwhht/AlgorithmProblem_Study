#include <iostream>
#include<string>
#include<vector>
#include<stack>

using namespace std;



class JZ56Solution {
public:
	//----------------核心代码------------------------------//
	int singleNumbers(vector<int>& nums) {
	
		int  count[32] = { 0 };
		unsigned int res = 0, m = 1;
		for (int num : nums)
		{
			m = 1;
			for (int i = 0; i < 32; i++)
			{
				if (m&num) { ++count[i]; }

				m = m << 1;
			}
		}
		for (int i = 31; i >= 0; i--)
		{
			res = res << 1;
			res = res | (count[i] % 3);

		}

		return (int)res;

	}
};


int main()
{
	JZ56Solution Test;
    int res;
	vector<int>input{ 9,1,7,9,7,9,7 };
	res = Test.singleNumbers(input);
	cout << res;
}