class Solution {
    private:
	void myFun(int sum,int start, vector<int>temp,vector<int>candidates, vector<vector<int>>&result,int target)
	{
	    if (target == sum)
	    {
		result.push_back(temp);
		return;
	    }
	    if (sum > target)
	    {
		//temp.pop_back();
		return;
	    }
	    for (int i = start; i < candidates.size(); i++)
	    {
		temp.push_back(candidates[i]);
		myFun(sum + candidates[i],i, temp, candidates, result, target);
		temp.pop_back();//回溯
	    }
	}
    public:
	vector< vector<int> > combinationSum(vector<int>& candidates, int target) {
	    sort(candidates.begin(), candidates.end());
	    candidates.erase(unique(candidates.begin(), candidates.end()),candidates.end());
	    vector<vector<int>> result;
	    vector<int> temp;
	    int start = 0;
	    myFun(0, start,temp, candidates, result, target);
	    return result;
	}
};
