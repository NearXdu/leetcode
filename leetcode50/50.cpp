class Solution {  
    public:  
	double myPow(double x, int n) {  
	    double result = 1.0;  
	    int flag = 1;  
	    if(x <0 &&n%2==1)//考虑负数的情况  
	    {  
		flag =0;  
	    }  
	    x=abs(x);  
	    if (n == 0)  
		return 1.0;  
	    else if (n > 0)  
	    {  
		while (n>0)  
		{  
		    if (n%2== 1)  
		    {  

			result *= x;  
		    }  
		    x = x*x;  
		    n =n>> 1;  
		}  
	    }  
	    else  
	    {  
		n = -n;  
		while (n>0)  
		{  
		    if (n % 2 == 1)  
		    {  

			result *= x;  
		    }  
		    x = x*x;  
		    n = n >> 1;  
		}  
		result = 1 / result;  
	    }  

	    return flag==0?-result:result;  
	}  
};  
