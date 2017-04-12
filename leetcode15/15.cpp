bool cmp(const int & x,const int & y)
{
    return x<y;
}
class Solution {
    public:
	vector< vector<int> > threeSum(vector<int>& nums) {
	    int numLen = nums.size();
	    int i;
	    int j;
	    int k;
	    vector< vector<int> >result;
	    if(numLen  < 3)
	    {
		return result;
	    }
	    vector<int>temp;
	    sort(nums.begin(),nums.end(),cmp);
	    for(i=0;i<numLen-2;i++)
	    {
		j=i+1;
		k=numLen - 1;
		while(j<k)
		{
		    if(nums[i] + nums[j] + nums[k] == 0)
		    {
			temp.push_back(nums[i]);
			temp.push_back(nums[j]);
			temp.push_back(nums[k]);
			result.push_back(temp);
			temp.clear();
			while(j<k&&nums[j]==nums[j+1])
			    j++;
			while(j<k&&nums[k]==nums[k-1])
			    k--;
			/*
			   if(find(result.begin(),result.end(),temp) == result.end())
			   {
			   result.push_back(temp);
			   }//时间复杂度为O(n)
			   */
		    }
		    if(nums[i] + nums[j] + nums[k] < 0)
			j++;
		    else
			k--;
		    //j++;
		    //k--;
		}
		while(i<numLen-2&&nums[i]==nums[i+1])
		    i++;
	    }

	    return result;
	}
};
