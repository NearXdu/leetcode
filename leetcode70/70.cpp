class Solution {  
    private:  
	void helper(vector<int>&dp,int n)  
	{  
	    int i = 3;  
	    while (i <= n)  
	    {  
		dp[i] = dp[i - 1] + dp[i - 2];  
		i++;  
	    }  
	}  
    public:  
	int climbStairs(int n) {  
	    vector<int>dp(n+1);  
	    dp[0] = 0;  
	    dp[1] = 1;  
	    dp[2] = 2;  
	    helper(dp, n);  
	    return dp[n];  
	}  
}; 
