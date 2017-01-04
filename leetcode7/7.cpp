#define INTMAX (int)0x7fffffff   
#define INTMIN (int)0x80000000  
class Solution {  
    public:  
	int reverse(int x) {  
	    int num;  
	    long long int sum=0;  
	    while(x!=0)  
	    {  
		num = x%10;  
		sum = sum*10 + num;  
		x=x/10;  
	    }  
	    /*下述两种方法都行*/  
	    if(sum>INT_MAX || sum < INT_MIN)  
		return 0;  
	    //if(sum > INTMAX || sum < INTMIN)  
	    //  return 0;  
	    return sum;  
	}  
};  
