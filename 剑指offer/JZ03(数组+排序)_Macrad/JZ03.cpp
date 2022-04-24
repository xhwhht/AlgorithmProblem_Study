#include <iostream>
#include<string>
#include<vector>

using namespace std;
class JZ03Solution {
public:
	//----------------核心代码------------------------------//
	int duplicate(vector<int>& numbers) {
		int num_temp;
		for (int i = 0; i < numbers.size(); i++)
		{
			if (i == numbers[i])       //数字和下标一致就不需要交换因为已经对应
				;
			else
				if (numbers[numbers[i]] == numbers[i])  //数字和数字作为下标处的数字一致说明重复
					return numbers[i];
				else
				{
					num_temp = numbers[numbers[i]];    //将数字放在对应的下标处，如9 应该在numbers[9]
					numbers[numbers[i]] = numbers[i];
					numbers[i] = num_temp;
				}

		}
		return -1;
	}
	//----------------End------------------------------//
};


int main()
{
	vector<int>number;
	int num;

	while (cin >> num && cin.get() != '\n')
	{
		number.emplace_back(std::move(num));

	}

	JZ03Solution Test;
	int result = Test.duplicate(number);
	cout << result;

}
