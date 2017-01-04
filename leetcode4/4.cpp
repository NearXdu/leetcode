
class Solution{  
    public:  
	double findMedianSortedArrays(vector<int>&num1,vector<int>&num2){  
	    vector<int>result;  
	    vector<int>::iterator it1=num1.begin();  
	    vector<int>::iterator it2=num2.begin();  
	    while(it1!=num1.end()||it2!=num2.end())  
	    {  
		if(it1==num1.end())  
		{  
		    result.insert(result.end(),it2,num2.end());  
		    break;  
		}  
		if(it2==num2.end())  
		{  
		    result.insert(result.end(),it1,num1.end());  
		    break;  
		}  
		if(*it1 == *it2)  
		{  
		    result.push_back(*it1);  
		    result.push_back(*it1);  
		    it1++;  
		    it2++;  
		}  
		else if(*it1<*it2)  
		{  
		    result.push_back(*it1);  
		    it1++;  
		}  
		else  
		{  
		    result.push_back(*it2);  
		    it2++;  
		}  
	    }  
	    int length=result.size();  
	    if(length%2 == 0)  
	    {  
		return double((result[length/2]+result[length/2 - 1])/2.0);  
	    }  
	    else  
	    {  
		return double(result[(length-1)/2]*1.0);  
	    }  
	}  
};  
