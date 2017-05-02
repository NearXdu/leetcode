class Solution {
    public:
	bool isScramble(string s1, string s2) {
	    if (s1.size() != s2.size())
		return false;
	    if (s1.size() == 1)
		return s1 == s2;
	    string str1 = s1;
	    string str2 = s2;
	    sort(str1.begin(), str1.end());
	    sort(str2.begin(), str2.end());
	    for (int i = 0; i < str1.size(); i++)//减少递归次数，元素不相等的串肯定不满足
	    {
		if (str1[i] != str2[i])
		    return false;
	    }
	    string s11, s12;
	    string s21, s22;
	    bool result = false;
	    for (int i = 1; i < s1.size(); i++)
	    {
		s11 = s1.substr(0, i);
		s12 = s1.substr(i, s1.size() - i);
		s21 = s2.substr(0, i);
		s22 = s2.substr(i, s2.size() - i);
		result = isScramble(s11, s21) && isScramble(s12, s22);
		if(result)//及时返回
		    return true;
		else//为false的时候交换左右子树
		{
		    s21 = s2.substr(0, s2.size() - i);
		    s22 = s2.substr(s2.size() - i, i);
		    result = isScramble(s11, s22) && isScramble(s12, s21);
		    if(result)//及时返回
			return true;
		}
	    }
	    return result;
	}
};
