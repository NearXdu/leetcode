
class Solution {  
    public:  
	int removeDuplicates(vector<int>& nums) {  
	    int count = 0;  
	    int sum=0;  
	    for (int i = 0; i < nums.size(); i++)  
	    {  
		int temp = nums[i];  
		int j = i;  
		while ( nums[j] == temp)//一致  
		{  
		    count++;  
		    if (count > 2)  
		    {  
			nums.erase(nums.begin() + j);//删除重复元素  
			j--;//索引减1，表示回退到删除元素之前的位置  
			count = 2;  
		    }  
		    j++;  
		    if (j > nums.size()-1)  
			break;  
		}  
		sum += count;  
		count = 0;  
		i = j-1;//跳过重复元素  
	    }  
	    return sum;  
	}  
};  

