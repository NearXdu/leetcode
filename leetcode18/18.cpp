bool cmp(const int&a ,const int&b)
{
    return a < b;
}
class Solution {
    public:
	vector< vector<int> > fourSum(vector<int>& nums, int target) {
	    int len = nums.size();
	    int i;
	    int j;
	    int k;
	    int l;
	    vector< vector<int> >result;
	    vector<int>temp;
	    if(len < 4)
	    {
		return result;
	    }
	    sort(nums.begin(),nums.end(),cmp);
	    for(i=0;i<len-3;i++)
	    {
		for(j=i+1;j<len-2;j++)
		{
		    k=j+1;
		    l=len-1;
		    while(k<l)
		    {
			if(nums[i]+nums[j]+nums[k]+nums[l]==target)
			{
			    temp.push_back(nums[i]);
			    temp.push_back(nums[j]);
			    temp.push_back(nums[k]);
			    temp.push_back(nums[l]);
			    result.push_back(temp);
			    temp.clear();
			    while(k<l&&nums[k]==nums[k+1])
				k++;
			    while(k<l&&nums[l]==nums[l-1])
				l--;
			}
			if(nums[i]+nums[j]+nums[k]+nums[l] < target)
			{
			    k++;
			}
			else
			{
			    l--;
			}
		    }
		    while(j<len-2&&nums[j]==nums[j+1])
			j++;
		}
		while(i<len-3&&nums[i]==nums[i+1])
		    i++;
	    }
	    return result;
	}
};
