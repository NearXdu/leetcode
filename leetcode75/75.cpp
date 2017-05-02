class Solution {  
    public:  
	void sortColors(vector<int>& nums) {  
	    vector<int>B(nums.size()+1,0);  
	    vector<int>C(3, 0);  
	    for (int i = 0; i < nums.size(); i++)  
	    {  
		C[nums[i]] = C[nums[i]] + 1;  
	    }  
	    for (int i = 1; i < 3; i++)  
	    {  
		C[i] = C[i] + C[i - 1];  
	    }  
	    for (int i = nums.size() - 1; i >= 0; i--)  
	    {  
		B[C[nums[i]]] = nums[i];  
		C[nums[i]] = C[nums[i]] - 1;  
	    }  
	    for (int i = 1; i < nums.size()+1; i++)  
	    {  
		nums[i-1] = B[i];  
	    }  
	}  
};  

/////
class Solution {  
    public:  
	void sortColors(vector<int>& nums) {  
	    vector<int>count(3, 0);//只有0,1,2 辅助数组大小为3，初始全为0  
	    for (int i = 0; i < nums.size(); i++)  
	    {  
		count[nums[i]]++;  
	    }  
	    nums.clear();//清空  
	    for (int i = 0; i < count.size(); i++)  
	    {  
		int j = 0;  
		while (j < count[i])  
		{  
		    nums.push_back(i);  
		    j++;  
		}  
	    }  
	}  
};  


////
//
class Solution{  
    public:  
	void sortColors(vector<int>& nums) {  
	    int index0 = 0;  
	    int index1 = 0;  
	    for (int i = 0; i < nums.size(); i++)  
	    {  
		if (nums[i] == 0)  
		{  
		    nums[i] = 2;  
		    nums[index1++] = 1;  
		    nums[index0++] = 0;  
		}  
		else if (nums[i] == 1)  
		{  
		    nums[i] = 2;  
		    nums[index1++] = 1;  
		}  
	    }  
	}  
};  
