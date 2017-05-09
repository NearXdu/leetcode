class Solution {
    public:
	int maxProfit(vector<int>& prices) {
	    if(0==prices.size())
		return 0;
	    int curMin = prices[0];//当前最低买入价格
	    int curMax=0;//prices[0]-prices[0]//当前最大利益
	    for (int i = 1; i < prices.size(); i++)
	    {
		if (curMin>prices[i])
		    curMin = prices[i];
		if (prices[i] - curMin > curMax)
		    curMax = prices[i] - curMin;
	    }
	    return curMax;
	}
};


class Solution{
    public:
	int maxProfit(vector<int>& prices) {
	    if(0==prices.size())
		return 0;
	    vector<int>local(prices.size());//局部最优
	    vector<int>global(prices.size());//全局最优
	    for (int i = 0; i < prices.size()-1; i++)
	    {
		int tmp = prices[i + 1] - prices[i];
		local[i + 1] =max(0,tmp+local[i]);
		global[i + 1] = max(global[i], local[i + 1]);
	    }
	    return global[prices.size() - 1];
	}
};


class Solution{
    public:
	int maxProfit(vector<int>& prices) {
	    if (0 == prices.size())
		return 0;
	    int local = 0;// 局部最优
	    int global = 0;//全局最优
	    for (int i = 0; i < prices.size() - 1; i++)
	    {
		int diff = prices[i + 1] - prices[i];
		local = max(0, diff + local);
		global = max(global, local);
	    }
	    return global;
	}
};
