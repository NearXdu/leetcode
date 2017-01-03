class Solution{  
    private:  
	void swap(int &index1,int&index2)  
	{  
	    int temp;  
	    temp=index1;  
	    index1=index2;  
	    index2=temp;  
	}  
    public:  
	//Solution(){}  
	vector<int> twoSum(vector<int>& nums, int target)  
	{  
	    map<int,int> myMap;  
	    vector<int>result;  
	    int index1;  
	    int index2;  
	    for(int i= 0;i<nums.size();i++)  
	    {  
		myMap.insert(pair<int,int>(nums[i],i));  
	    }  
	    vector<int>::iterator it;  
	    for(it=nums.begin();it!=nums.end();it++)  
	    {  
		int number = target - *it;  
		if(myMap.find(number)!=myMap.end())  
		{  
		    index1=it-nums.begin()+1;  
		    index2=myMap.find(number)->second + 1;  
		    if(index1>index2)  
		    {  
			swap(index1,index2);  
		    }  
		    else if(index1 == index2)  
		    {  
			continue;  
		    }  
		    result.push_back(index1);  
		    result.push_back(index2);  
		    return result;  
		}  
	    }  
	    return result;  
	}  
};  
