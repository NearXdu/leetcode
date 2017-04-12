class Solution {
    public:
	int threeSumClosest(vector<int>& nums, int target) {
	    int numLen = nums.size();
	    int i;
	    int j;
	    int k;
	    int closest;
	    int result;
	    int minAbs=INT_MAX;
	    cout << endl;
	    for(i=0;i<numLen-2;i++)
	    {
		for(j=i+1;j<numLen-1;j++)
		{
		    for(k=j+1;k<numLen;k++)
		    {
			closest = nums[i]+nums[j]+nums[k];
			if(closest == target )
			    return closest;
			else if(closest > target)
			{
			    if(closest - target < minAbs)
			    {
				minAbs=closest - target;
				result = closest;
			    }
			}
			else
			{
			    if(target - closest < minAbs)
			    {
				minAbs=target - closest;
				result = closest;
			    }
			}
		    }
		}
	    }
	    return result;
	}
};
