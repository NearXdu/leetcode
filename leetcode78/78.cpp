
class Solution {  
    private:  
	void help(int i, int n, int k, vector<int>temp, vector<vector<int>>&result,vector<int>nums)  
	{  
	    if (temp.size() == k)//k个数  
	    {  
		result.push_back(temp);  
		return;  
	    }  
	    if (temp.size() > 1 && temp.back() < *(temp.end() - 2))  
		return;  
	    for (int index = i ; index < n ; index++)//i  
	    {  
		temp.push_back(nums[index]);  
		help(index+1, n, k, temp, result,nums);  
		temp.pop_back();  
	    }  
	}  
    public:  
	vector<vector<int>> subsets(vector<int>& nums) {  
	    vector<vector<int>>result;  
	    vector<int>temp;  
	    sort(nums.begin(), nums.end());  
	    result.push_back(temp);  
	    for (int i = 1; i <= nums.size(); i++)  
	    {  
		help(0, nums.size(), i, temp, result,nums);  
	    }  
	    return result;  
	}  
};  

