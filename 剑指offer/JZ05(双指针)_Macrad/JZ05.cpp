#include <iostream>
#include<string>
#include<vector>

using namespace std;

class JZ05Solution {
public:
	//----------------核心代码------------------------------//
	void replaceSpace(char* s) {
		
	
     //统计空格的个数
		
		int Len = 0;
		int BlankNums = 0;
		while(s[Len]!='\0')
		{
			if (s[Len]== ' ')
				++BlankNums;

			++Len;
		}
	    
		int NewLen = Len + BlankNums*2;

		int indexLast = NewLen;     
		int indexFirst = Len;  //此位置指向\0

		while (indexFirst >= 0 && indexLast > indexFirst)
		{
			if ( s[indexFirst] ==' ')
			{
				s[indexLast--] = '0';
				s[indexLast--] = '2';
				s[indexLast--] = '%';
			}
			else
			{
				s[indexLast--] = s[indexFirst];   //先赋值再减一
			}
			--indexFirst;
		}

	}

};


int main()
{
	char S[20];
	char c[7] = {"h ell " };
	
	memset(S,0, sizeof(S));
	for (int i=0;i<7;++i )
		{
		S[i] = c[i];
		}

	
	JZ05Solution Test;
	Test.replaceSpace(&S[0]);
	
	for (auto res : S)
		cout << res;

}

