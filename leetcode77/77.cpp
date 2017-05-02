class Solution {  
    private:   
	void help(int i,int n, int k,vector<int>temp,vector<vector<int>>&result)  
	{  
	    if (temp.size() == k)//k个数  
	    {  
		result.push_back(temp);  
		return;  
	    }  
	    if (temp.size() > 1 && temp.back() < *(temp.end()-2))//递增  
		return;  
	    for (int index = i+1; index < n+1; index++)//i  
	    {  
		temp.push_back(index);  
		help(index , n, k, temp, result);//递归  
		temp.pop_back();//一次完成要弹出  
	    }  
	}  
    public:  
	vector<vector<int>> combine(int n, int k) {  
	    vector<int> temp;  
	    vector<vector<int>>result;  
	    help(0, n, k, temp, result);  

	    return result;  
	}  
};  
