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
	    sort(nums.begin(),nums.end());
	    for(int i=0;i<nums.size()-2;i+=3)
	    {
		int n1=nums[i];
		int n2=nums[i+1];
		int flag1=n1^n2;
		if(flag1!=0)
		    return n1;
	    }
	    return nums[nums.size()-1];
	}
};
