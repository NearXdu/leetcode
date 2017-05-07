class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int len = triangle.size();
        vector<vector<int>>dp(len, vector<int>(len));
        if (0 == len)
            return 0;
        dp[0][0] = triangle[0][0];
        for (int i = 1; i < len; i++)
        {
            for (int j = 0; j < i + 1; j++)
            {
                if (j>0 && j != i)
                    dp[i][j] = min(dp[i - 1][j], dp[i - 1][j - 1]) + triangle[i][j];
                else if (j == i)//右边界
                    dp[i][j] = dp[i - 1][j - 1] + triangle[i][j];
                else//左边界
                    dp[i][j] = dp[i - 1][j] + triangle[i][j];
            }
        }
        int minVal = dp[len - 1][0];//取最小值
        for (int i = 1; i < len; i++)
        {
            if (dp[len - 1][i] < minVal)
                minVal = dp[len - 1][i];
        }
        return minVal;
    }
};

//////////////
//
class Solution {
    public:
	int minimumTotal(vector<vector<int>>& triangle) {
	    int len = triangle.size();
	    vector<vector<int>>dp(len, vector<int>(len));
	    if (0 == len)
		return 0;
	    for (int i = 0; i < len; i++)
		dp[len - 1][i] = triangle[len - 1][i];
	    for (int i = len - 2; i >= 0; i--)//自底向上
	    {
		for (int j = 0; j < i + 1; j++)
		{
		    dp[i][j] = min(dp[i + 1][j], dp[i + 1][j + 1]) + triangle[i][j];
		}
	    }
	    return dp[0][0];
	}
};



class Solution {
    public:
	int minimumTotal(vector<vector<int>>& triangle) {
	    int len = triangle.size();
	    if (0 == len)
		return 0;
	    vector<int>dp(len);
	    dp[0] = triangle[0][0];
	    for (int i = 1; i < len; i++)
	    {
		//dp[i] = dp[i - 1] + triangle[i][i];
		for (int j = i; j >= 0; j--)//这里需要从后往前
		{
		    if (0 == j)
			dp[j] = dp[j] + triangle[i][j];
		    else  if (i == j)
			dp[j] = dp[j - 1] + triangle[i][j];
		    else
			dp[j] = min(dp[j], dp[j - 1]) + triangle[i][j];//dp[j]->上一层右侧,dp[j-1]上一层左侧
		}
	    }
	    int minVal = dp[0];
	    for (int i = 0; i < dp.size(); i++)
	    {
		if (dp[i] < minVal)
		    minVal = dp[i];
	    }
	    return minVal;
	}
};


class Solution {
    public:
	int minimumTotal(vector<vector<int>>& triangle) {
	    int len = triangle.size();
	    vector<vector<int>>dp(len, vector<int>(len));
	    if (0 == len)
		return 0;
	    for (int i = 0; i < len; i++)
		dp[len - 1][i] = triangle[len - 1][i];
	    for (int i = len - 2; i >= 0; i--)
	    {
		for (int j = 0; j < i + 1; j++)
		{
		    dp[i][j] = min(dp[i + 1][j], dp[i + 1][j + 1]) + triangle[i][j];
		}
	    }
	    return dp[0][0];
	}
};
