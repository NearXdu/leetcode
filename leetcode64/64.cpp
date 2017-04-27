class Solution {  
    public:  
	int minPathSum(vector<vector<int>>& grid) {  
	    int m=grid.size();  
	    int n=grid[0].size();  
	    vector<vector<int>>dp(m, vector<int>(n));  
	    if (m == 0 || n == 0)  
		return 0;  
	    dp[0][0]=grid[0][0];  
	    for (int i = 0; i < m; i++)  
	    {  
		for (int j = 0; j < n; j++)  
		{  
		    if (i >= 1 && j >= 1)  
			dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];  
		    else if (i>=1)//边界条件  
			dp[i][j] = dp[i-1][j]+ grid[i][j];  
		    else if (j >= 1)//边界条件  
			dp[i][j] = dp[i][j-1] + grid[i][j];  
		}  
	    }  
	    return dp[m - 1][n - 1];  
	}  
};  
