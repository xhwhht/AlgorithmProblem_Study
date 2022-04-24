#include <iostream>
#include<string>
#include<vector>

using namespace std;
static const auto io_sync_off = []() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	return nullptr;
}();

class JZ04Solution {
public:
	//----------------核心代码------------------------------//
	bool Find(int target, vector<vector<int> > array) {

		int m = array.size();
		int n = array[0].size();
		int row = 0, columns = n-1;

		if (m == 1 && n == 0)
			return 0;

		for ( int count = 0; count < m + n; ++count)
		{
			if (array[row][columns] == target)
				return 1;
			else if (array[row][columns] > target)
			{
				if (columns == 0)
				{
					return 0;
				}
				columns--;
			}
			else if (array[row][columns] < target)
			{
				if(row==m-1)
				{
					return 0;
				}
				row++;
			}
		}

		return 0;
	
		//----------------End------------------------------//
	}

};


int main()
{
	const int Max_Line = 4;
	vector<vector<int>> array;
	vector<int> OneLine;
	int num,LineCount=0;


	//输入
	while (LineCount != Max_Line && cin >> num )
	{
		OneLine.emplace_back(std::move(num));
		if (cin.get() == '\n')
		{
			array.emplace_back(std::move(OneLine));
			OneLine.clear();
			LineCount++;

		}
	}
	cin.get();

	JZ04Solution Test;
	int target = 15;
	bool result = Test.Find(target,array);
	cout << result;

}

