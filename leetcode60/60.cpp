class Solution {  
    public:  
	string getPermutation(int n, int k) {  
	    vector<char>nums;  
	    string result;  
	    int count = 1;  
	    k = k - 1;  
	    for (int i = 1; i <= n; i++)  
		nums.push_back(i + '0');  
	    for (int i = 2; i < n; i++)  
		count *= i;//每一组数量 (n-1)!  
	    while (n--)  
	    {  
		int index = k / count;//第一个数  
		k = k%count;//更新k的值，剔除第一个数后的全排列的位置  
		result += nums[index];  
		nums.erase(nums.begin() + index);  
		if (n == 0)  
		    break;  
		count /= n;//计算完一次也需要将(n-1)!更新到(n-2)!  
	    }  
	    return result;  
	}  
};  
