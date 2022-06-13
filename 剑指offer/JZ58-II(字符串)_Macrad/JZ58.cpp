class Solution {
public:
	string reverseLeftWords(string s, int n) {
		//方法一
		return s.substr(n, s.size()) + s.substr(0, n);
	}
};
//方法二