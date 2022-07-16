/*
题目：给定一组数返回最大峰值间距
eg：1 1----> 2
    1 2 3 3 3 2 1 ->5
数组两端算峰值
*/
#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main () {
	
	vector<int>blocks{ 1,2,2,3,4,4,4,3,3,3,2};

	int len = blocks.size(),res=1,upFlag=1,equal, max_res=0,equal_res=1;
	if (1 == len)  return 1;
	if (2 == len)  return 2;

	for (int i = 1; i < len; i++)
	{
		if (1 == upFlag)   //upflag 序列处于非严格增长时刻
		{
			if (blocks[i] > blocks[i - 1])
			{
				res++;	
				equal_res = 1;  //如果增长就清零目前 记录的“峰值相等数据”因为这个是局部峰值 不可作为第i个峰值的数据
			}
			else if(blocks[i] == blocks[i - 1])
			{
				equal = blocks[i];
				res++;
				equal_res++;
			}
			else  //赠变减的时候 比较第i-1个峰值的时刻
			{
				upFlag = 0;
				max_res = max(res,max_res);
				res = equal_res;               //保存第i个峰值的数据（如果值一样的峰值）
			}
		}
		else  //当前处于非严格递减的序列
		{
			if (blocks[i] <= blocks[i - 1])
				res++;
			else
			{
				upFlag = 1;
				res++;
			}
		}
	    
	}

	res= max(res + 1, max_res); //res+1 为整个区间最后一段满足条件的区块
	cout << res;
}