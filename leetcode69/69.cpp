class Solution {  
    public:  
	int mySqrt(int x) {  
	    if (x == 1||x==0)  
		return x;  
	    long low = 1;  
	    long high = x;  
	    while (low < high)  
	    {  
		long mid = low + (high - low) / 2;  
		if (mid*mid > x)  
		    high = mid;  
		else if (mid*mid < x)  
		{  
		    low = mid + 1;  
		}  
		else  
		{  
		    return mid;  
		}  
	    }  
	    return low-1;  
	}  
};
