class Solution {
    public:
	int maxProfit(vector<int>& prices) {
	    int len = prices.size();
	    if (0 == len)
		return 0;
	    vector<vector<int>>local(len + 1, vector<int>(3));//局部最优
	    vector<vector<int>>global(len + 1, vector<int>(3));//全局最优
	    for (int i = 0; i <len-1 ; i++)
	    {
		int diff = prices[i + 1] - prices[i];
		for (int j = 0; j < 2; j++)
		{
		    local[i + 1][j + 1] = max(local[i][j + 1] + diff, global[i][j] + max(diff, 0));
		    global[i + 1][j+1] = max(global[i][j+1], local[i + 1][j+1]);
		}
	    }
	    return global[len-1][2];
	}
};


class Solution {
    public:
	int maxProfit(vector<int>& prices) {
	    if(0==prices.size())
		return 0;
	    vector<int>local(3);//局部最优
	    vector<int>global(3);//全局最优
	    for (int i = 0; i < prices.size()-1; i++)
	    {
		int diff = prices[i + 1] - prices[i];
		for (int j = 1; j >= 0; j--)//从后往前
		{
		    local[j + 1] = max(local[j+1]+diff,global[j]+max(diff,0));
		    global[j + 1] = max(global[j + 1], local[j + 1]);
		}
	    }
	    return global[2];
	}
};
