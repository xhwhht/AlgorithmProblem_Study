#include <iostream>
#include<vector>


struct myPos
{
	int x;
	int y;
}pos;
using namespace std;

int main() {
	
	int N;
	cin >> N;               //N 组坐标
	vector<myPos> VecPos;   //坐标类的数组
	
	for (int i = 0; i < N; ++i)
	{
		cin >> pos.x;
		cin >> pos.y;
		VecPos.emplace_back(pos);
	}


    //打印输出
	for (int i = 0; i < N; ++i)
	{
		cout << VecPos[i].x << " " << VecPos[i].y << endl;
	}



return 0;
}

