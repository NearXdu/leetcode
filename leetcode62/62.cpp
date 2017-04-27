class Solution {   
    public:   
	int uniquePaths(int m, int n) {   
	    m--;   
	    n--;   
	    int len = m+n;   
	    int i;   
	    int minNum=min(m,n);   
	    long sum1=1;   
	    long sum2=1;   
	    for(i=1;i<=minNum;i++)   
	    {   
		sum1=sum1*len;   
		len--;   
	    }   
	    for(i=1;i<=minNum;i++)   
	    {   
		sum2=sum2*i;   
	    }   
	    return sum1/sum2;   
	}   
};  
