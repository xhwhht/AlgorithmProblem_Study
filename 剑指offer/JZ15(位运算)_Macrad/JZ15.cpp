#include <iostream>
#include<string>
#include<vector>
#include<stack>

using namespace std;



class JZ15Solution {
public:
	//----------------核心代码------------------------------//
	int  NumberOf1(int n) {
	int count=0,flag=1;
	for (int i = 0; i < 32; i++)
	{
		if ( n & flag)
		{
			++count;
		}
		flag=flag << 1;
	}
	return count;

	/*
	 int count=0;
	 while(n)
	 {
		 ++count;
		 n=n&(n-1);
	 }
		return count;
	*/
	}
};


int main()
{
	JZ15Solution Test;
	
	int n, res;
	cin >> n;
	res = Test.NumberOf1(n);
	cout << res;
}
