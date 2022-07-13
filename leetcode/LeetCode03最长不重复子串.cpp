/*
 最长不重复字串

 1.通过 set记录出现过字符+双指针 i为左指针 rk右指针 rk向右移动压入set
   +出现重复的元素删除i左指针向右移动1个+
   会有无效循环但是也是必须的要删除第一次出现重复原色之前的元素，i不断右移
   可以有map记录每个元素第一次出现的位置 出现之后就更新
2. start 记录元素的位置  出现重复后更新其位置+1 并相应字符的位置更新 128 ascii的范围

 */

 //----------------------------------法-------------------------------------//
class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		unordered_set<int> element;
		int rk = -1, res = 0;
		int n = s.length();

		for (int i = 0; i < n; i++)
		{
			if (i != 0)
			{
				element.erase(s[i - 1]);
			}

			while (rk + 1 < n && !element.count(s[rk + 1]))
			{
				element.insert(s[rk + 1]);
				rk++;
			}

			res = max(res, rk - i + 1);
		}
		return res;
	}
};

//----------------------------------法二------------------------------------//
class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		vector<int> hash(128, -1);
		int res = 0, start = 0;

		for (int i = 0; i < s.size(); i++)
		{

			start = max(start, hash[s[i]] + 1);  //从重复的位置下一个开始算起
			res = max(res, i - start + 1);
			hash[s[i]] = i;

		}
		return res;
	}
};