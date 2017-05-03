class Solution {
    public:
	int numDecodings(string s) {
	    if (s.size() == 0 || s[0] == '0')
		return 0;
	    vector<int>dp(s.size() + 1);
	    dp[0] = 1;
	    dp[1] = 1;
	    for (int i = 1; i < s.size(); i++)
	    {
		int tmp = (int)atoi(s.substr(i - 1, 2).c_str());
		if (tmp <= 26 && tmp >= 10)
		    dp[i + 1] += dp[i - 1];
		if (tmp%10 != 0)//s[i]==0
		    dp[i + 1] += dp[i];
	    }
	    return dp[s.size()];
	}
};
