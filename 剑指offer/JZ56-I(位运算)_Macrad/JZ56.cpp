#include <iostream>
#include<string>
#include<vector>
#include<stack>

using namespace std;



class JZ65Solution {
public:
	//----------------核心代码------------------------------//
	int add(int a, int b)
	{
		while (b != 0)
		{
			int c = (unsigned int)(a&b) << 1;
			a = a ^ b;
			b = c;

		}
		return a;
	}
};


int main()
{
	JZ65Solution Test;
	int a = -1,b=3,res;

	res = Test.add(a, b);
	cout << res;
}
