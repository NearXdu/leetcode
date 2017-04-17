class Solution {  
    private:  
	void Swap(int &a, int &b)  
	{  
	    int temp = a;  
	    a = b;  
	    b = temp;  
	}  
	void Permutation(vector<int>&nums, int first, int last)  
	{  
	    if (first == last)//长度为1  
		return;  
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
		    return ;  
		}  
		if (i == first)  
		{  
		    reverse(nums.begin(),nums.end());  
		    return ;  
		}  
	    }  
	}  
    public:  
	void nextPermutation(vector<int>& nums) {  
	    //next_permutation(nums.begin(), nums.end());//STL  
	    int first = 0;  
	    int last = nums.size()-1;  
	    if (!nums.empty())  
	    {  
		Permutation(nums, first, last);  
	    }  
	    else  
	    {  
		return;  
	    }  
	}  
};  
