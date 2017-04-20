class Solution {  
    public:  
	bool canJump(vector<int>& nums) {  
	    int endIndex = nums.size()-1;  
	    int curIndex = 0;  
	    int nextIndex = 0;  
	    int i=0;  
	    while(  i < nums.size())  
	    {  
		if (curIndex >= endIndex)  
		    return true;  
		while (i <= curIndex)  
		{  
		    nextIndex = max(nextIndex, i + nums[i]);  
		    i++;  
		}  
		if (curIndex == nextIndex)//说明已经停滞不前了  
		    return false;  
		curIndex = nextIndex;  
	    }  
	}  
};  
