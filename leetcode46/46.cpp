class Solution {  
    private:  
	void Swap(int &a, int &b)  
	{  
	    int temp = a;  
	    a = b;  
	    b = temp;  
	}  
	bool Permutation(vector<int>&nums, int first, int last)  
	{  
	    if (first == last)//长度为1  
		return false;  
	    int i;  
	    i = last;  
	    while (1)  
	    {  
		int ii = i;  
		--i;  
		//锁定两个相邻的元素  
		if (nums[i] < nums[ii])//前一个元素小于后一个元素  
		{  
		    int j = last;  
		    while (!(nums[i] < nums[j--]));//尾端往前找找到比nums[i]大的元素  
		    Swap(nums[i], nums[j+1]);  
		    reverse(nums.begin()+ii, nums.end());  
		    return true;  
		}  
		if (i == first)  
		{  
		    reverse(nums.begin(),nums.end());  
		    return false;  
		}  
	    }  
	}  
    public:  
	vector<vector<int>> permute(vector<int>& nums) {  
	    vector<vector<int>>result;  
	    sort(nums.begin(),nums.end());  
	    result.push_back(nums);  
	    while(Permutation(nums,0,nums.size()-1))  
	    {  
		result.push_back(nums);  
	    }  
	    // result.push_back(nums);  
	    return result;  
	}  
}; 
