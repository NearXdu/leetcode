#include<iostream>  
using namespace std;  
class Solution {  
    public:  
	int myAtoi(string str) {  
	    int i = 0;  
	    int flag = 0;  
	    long long int result = 0;  
	    while(str[i]==' ')//while space  
		i++;  
	    if(str[i]=='-')  
	    {  
		flag --;  
		i++;  
	    }  
	    else if(str[i]=='+')  
	    {  
		flag ++;  
		i++;      
	    }  
	    else if(str[i]-'0'>=0 && str[i]-'0'<=9)  
		;  
	    else  
		return 0;  
	    while(i<str.length())  
	    {  
		if(str[i]-'0'>=0 && str[i]-'0'<=9)  
		{  
		    result =  result* 10 + (str[i]-'0');  
		    if(flag < 0)  
		    {  
			if(result > INT_MAX)  
			    return INT_MIN;  
		    }  
		    else  
		    {  
			if(result > INT_MAX)  
			    return INT_MAX;  
		    }  
		    i++;  
		}  
		else   
		    break;  
		//i++;  
	    }  
	    if(flag >= 0 )  
		return result;  
	    else  
		return -result;  
	}  
};  
