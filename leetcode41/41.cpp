class Solution {  
    public:  
	int firstMissingPositive(vector<int>& nums) {  
	    sort(nums.begin(), nums.end());  
	    nums.erase(unique(nums.begin(),nums.end()),nums.end());  
	    if (nums.empty())  
		return 1;  
	    int i;//first  
	    int j;//end  
	    for (i = 0; i < nums.size(); i++)  
	    {  
		if (nums[i]>0)  
		{  
		    break;  
		}  
	    }//找到开始索引  
	    for (j = i; j < nums.size(); j++)  
	    {  
		if (nums[j] != j - i+1)  
		    return j-i+1;  
	    }  
	    return nums[j-1]+1;//返回最后一个元素后面的元素  
	}  
};  
