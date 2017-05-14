class Solution {
    public:
	int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
	    int start = 0;
	    int cur = 0;
	    int pre = 0;
	    int i;
	    int N = gas.size();
	    for (i = 0; i < N; i++)
	    {
		cur = cur + gas[i] - cost[i];
		if (cur < 0)//更新起点
		{
		    pre = pre + cur;//前半圈负总和
		    start = i + 1;
		    cur = 0;
		}
	    }
	    if (cur + pre >= 0)//前后总和大于0
		return start;
	    else
		return -1;
	}
};
