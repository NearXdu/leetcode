class Solution {
    private:
	void help(int i, int n, int k, vector<int>temp, vector<vector<int>>&result, vector<int>nums)
	{
	    //  if (temp.size() == k&&(find(result.cbegin(),result.cend(),temp)==result.cend()))//去重方法2
	    if (temp.size() == k)//k个数
	    {
		result.push_back(temp);
		return;
	    }
	    for (int index = i; index < n; index++)//i
	    {
		if(index!=i&&nums[index]==nums[index-1])
		{
		    continue;
		}//去重方法3，效率较好

		temp.push_back(nums[index]);
		help(index + 1, n, k, temp, result, nums);
		temp.pop_back();
	    }
	}
    public:
	vector<vector<int>> subsetsWithDup(vector<int>& nums) {
	    vector<vector<int>>result;
	    vector<int>temp;
	    sort(nums.begin(), nums.end());
	    result.push_back(temp);
	    for (int i = 1; i <= nums.size(); i++)
	    {
		help(0, nums.size(), i, temp, result, nums);
	    }
	    // 去重方法1
	    //  sort(result.begin(),result.end());
	    //  result.erase(unique(result.begin(),result.end()),result.end());
	    return result;
	}
};
