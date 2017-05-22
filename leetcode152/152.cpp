class Solution {

    public:

	int maxProduct(vector<int>& nums)
	{
	    vector<int>dp_min(nums.size());
	    vector<int>dp_max(nums.size());
	    dp_min[0]=nums[0];
	    dp_max[0]=nums[0];
	    int global=nums[0];
	    for(int i = 1;i<nums.size();i++)
	    {
		if(nums[i]>0)
		{
		    dp_max[i]=max(dp_max[i-1]*nums[i],nums[i]);
		    dp_min[i]=min(dp_min[i-1]*nums[i],nums[i]);
		}
		else
		{
		    dp_max[i]=max(dp_min[i-1]*nums[i],nums[i]);
		    dp_min[i]=min(dp_max[i-1]*nums[i],nums[i]);

		}

		global=max(global,dp_max[i]);
	    }
	    return global;

	}

};
