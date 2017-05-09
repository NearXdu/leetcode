class Solution {
    private:
	bool compareIgnoreCase(string const& s1, string const&s2)
	{
	    return equal(s1.begin(), s1.end(), s2.begin(), 
		    [](char a, char b){return tolower(a) == tolower(b); });//Lambda
	}
	void removeSyntex(string &s)//删去非法字符
	{
	    string tmp;
	    for (int i = 0; i < s.size(); i++)
	    {
		if (isalnum(s[i]))
		{
		    tmp += s[i];
		}
	    }
	    s = tmp;
	}
    public:
	bool isPalindrome(string s) {
	    removeSyntex(s);
	    if (s.size() == 0)
		return true;
	    int mid;
	    mid = s.size() / 2;
	    string leftSubString(s.begin(), s.begin() + mid);//前半
	    string rightSubString(s.rbegin(), s.rbegin() + mid);//后半
	    return compareIgnoreCase(leftSubString, rightSubString);
	}
};
