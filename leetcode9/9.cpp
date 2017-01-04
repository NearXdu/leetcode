class Solution {  
    public:  
	bool isPalindrome(int x) {  
	    if (x<0)  
		return false;  
	    long long int sum =0;  
	    long long int origin = x;  
	    while(x)  
	    {  
		int num = x %10;  
		sum = sum*10 + num;  
		x/=10;  
	    }  
	    if(sum == origin)  
		return true;  
	    else  
		return false;  
	}  
};  
