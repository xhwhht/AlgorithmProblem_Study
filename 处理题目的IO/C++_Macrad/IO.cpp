

#include <iostream>
using namespace std;
int main()
{
	//-----------------------第一类输入-------------------------------//
   
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







	//------------------------------------------------------------------//

	return 0;
}

