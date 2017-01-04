class Solution {  
    private:  
	string subPalindrome(string s,int left,int right)  
	{  
	    int strLen = s.length();  
	    while(left>=0&&right<strLen && s[left]==s[right])  
	    {  
		left--;  
		right++;  
	    }  
	    left++;  
	    right--;  
	    return s.substr(left,right-left +1);  
	}  

    public:  
	string longestPalindrome(string s) {  
	    //Map<string,int>myMap;  
	    int i;  
	    int strLen = s.length();  
	    string sub;  
	    string sub1;  
	    int max = 0;  
	    int subLen = 0;  
	    string result="";  
	    for(i=0;i<strLen;i++)  
	    {  
		sub = subPalindrome(s,i,i+1);//偶数的情况  
		subLen = sub.length();  
		if(subLen > max )  
		{  
		    max = subLen;  
		    result = sub;   
		}  
		sub1 = subPalindrome(s,i,i);//奇数的情况  
		subLen = sub1.length();  
		if(subLen > max )  
		{  
		    max = subLen;  
		    result = sub1;   
		}  

	    }  
	    return result;  
	}  
};  
