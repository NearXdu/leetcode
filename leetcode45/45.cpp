class Solution {  
    public:  
	int jump(vector<int>& nums) {  
	    int endIndex = nums.size() - 1;  
	    int nextIndex = 0;  
	    int curIndex = 0;  
	    int step = 0;  
	    int i = 0;  
	    while (i<nums.size())  
	    {  
		if (curIndex >= endIndex)  
		    break;  
		//int j = i;  
		while (i <= curIndex)  
		{  
		    nextIndex = max(nextIndex, nums[i] + i);//greedy  
		    //j++;  
		    i++;  
		}  
		curIndex = nextIndex;  
		step++;  
	    }  
	    return step;  
	}  
};  
