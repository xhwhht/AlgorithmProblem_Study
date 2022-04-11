#include <iostream>
#include<string>
#include<vector>


using namespace std;
class JZ03Solution {
public:
	//----------------核心代码------------------------------//
	int duplicate(vector<int>& numbers) {
	int num_temp;
		for (int i=0;i < numbers.size();i++)
		{
			if (i == numbers[i])
				;
			else
				if (numbers[numbers[i]] == numbers[i])
					return numbers[i];
				else
				{
					num_temp = numbers[numbers[i]];
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
	using namespace std;
	vector<int>number;
	int num;
	
	while (cin >> num&& cin.get() != '\n' )
	{
		number.emplace_back(std::move(num));

	}

	JZ03Solution Test;	
	int result=Test.duplicate(number);
	cout << result;

}

