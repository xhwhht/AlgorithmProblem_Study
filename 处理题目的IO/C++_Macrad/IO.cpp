
#include <iostream>
#include <vector>
#include<string>
#include <algorithm>
#include <sstream>

using namespace std;
int main()
{
//-----------------------第一类输入-----------------------------//
   
	cout << sizeof(long);
	cout << sizeof(long long);

	int N, M;
	while (cin >> N >> M)
	{
		cout << N <<" " << M;
		for (int i = 0; i < M; i++)
		{
			int a, b, c;
			cin >> a >> b >> c;
			cout << a << " " << b << " " << c << endl;
		}
	}


//-----------------------第二类输入----------------------------------//
	int n;
	while (1)
	{
		cin >> n;
		if (n == 0)
		{
			break;
		}
		else
		{
			int sum = 0, val;
			++n;
			while (--n)
			{
				cin >> val;
				sum = sum + val;
			}
			cout << sum << endl;
		}
	}
	

//----------------------第三类输入---------------------------------------//

		int n;
		while (cin >> n)
		{
			int a, sum = 0;
			for (int i = 0; i < n; i++)
			{
				cin >> a;
				sum += a;
			}
			cout << sum << endl;
		}


//------------------------第四类输入------------------------------------//
	int val, sum = 0;
	while (cin >> val)
	{
		sum = sum + val;
		if (cin.get() == '\n')
		{
			cout << sum << endl;
			sum = 0;
		}

	}
//-----------------------第五类输入-----------------------------------//
	vector<string> str;
	string s;
	while (cin >> s)
	{
		str.push_back(s);
		if (cin.get() == '\n')
		{
			sort(str.begin(), str.end());
			for (int i = 0; i < str.size(); ++i)
			{
				if (i == (str.size() - 1))
					cout << str[i] << endl;
				else
					cout << str[i] << " ";
			}
			vector<string>().swap(str);     //str.clear(); 如果定义一个vector 生命周期在if结束后就消失
		}
	}

//----------------------第六类输入--------------------------------------//	

	string strInput;
	while (getline(cin, strInput))
	{
		vector<string> str;
		stringstream toApartStr(strInput);
		string temp;
		while (getline(toApartStr, temp, ','))
		{
			str.push_back(temp);
		}
		sort(str.begin(), str.end());
		for (int i = 0; i < str.size(); ++i)
		{
			if (i == str.size() - 1)
				cout << str[i] << endl;
			else
				cout << str[i] << ",";
		}
	}


	return 0;
}

/*
#include<bits/stdc++.h>  //#include <sstream>
using namespace std;

int main()
{
	string s;
	while(getline(cin, s))
	{
		stringstream ss(s);
		string temp;
		vector<string> vec;
		while(getline(ss,temp,','))
		{
			vec.push_back(temp);
		}
		sort(vec.begin(),vec.end());
		for(int i = 0; i < vec.size(); i++)
		{
			cout<<vec[i];
			if(i < vec.size() - 1)
			{
				cout<<',';
			}
		}
		cout<<endl;
	}
	return 0;
	//源代码：https://ac.nowcoder.com/acm/contest/view-submission?submissionId=52299272
}
*/
