class Solution {
    public:
	int singleNumber(vector<int>& nums) {
	    unordered_map<int,int>table;
	    for(int i=0;i<nums.size();i++)
	    {
		table[nums[i]]=table[nums[i]]+1;
	    }
	    for(auto it = table.begin();it!=table.end();it++)
	    {
		if(it->second==1)
		    return it->first;
		else
		    continue;
	    }
	    return nums[0];
	}
};
class Solution {
    public:
	int singleNumber(vector<int>& nums) {
	    if(nums.size()==1)
		return nums[0];
	    for(int i = 1;i<nums.size();i++)
	    {
		nums[0]^=nums[i];
	    }
	    return nums[0];
	}
};
