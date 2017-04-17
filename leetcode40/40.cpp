class Solution {
    private:
	void myFun(int sum,int target,int start,vector<vector<int>>&result,vector<int>temp,vector<int>candidates)
	{
	    if (sum == target)
	    {
		result.push_back(temp);
		return;
	    }
	    if (sum > target)
		return;
	    for (int i = start;i<candidates.size();i++)
	    {
		if (i!=start&&candidates[i] == candidates[i - 1])//去重
		    continue;
		temp.push_back(candidates[i]);
		myFun(sum + candidates[i], target,i+1 ,result,temp,candidates );
		temp.pop_back();
	    }
	}
    public:
	vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
	    sort(candidates.begin(), candidates.end());
	    //candidates.erase(unique(candidates.begin(),candidates.end()),candidates.end());
	    vector<vector<int>>result;
	    vector<int>temp;
	    myFun(0, target, 0, result, temp, candidates);
	    //超时
	    //sort(result.begin(),result.end());
	    //result.erase(unique(result.begin(),result.end()),result.end());
	    return result;
	}
};
