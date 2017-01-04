class Solution {  
    public:  
	int lengthOfLongestSubstring(string s) {  
	    int map[256]={0};  
	    unsigned int i;  
	    unsigned int j=0;  
	    int count=0;  
	    for(i=0;i<s.length();i++)  
	    {  
		//  memset(map,0,sizeof(map));  
		if(map[s[i]-' ']==0)  
		    map[s[i]-' ']=1;  
		else  
		{  
		    count = max(count,(int)(i-j));  
		    //memset(map,0,sizeof(map));  
		    while(s[j]!=s[i])  
		    {  
			map[s[j]-' ']=0;  
			//memset(map,0,sizeof(map));  
			j++;  
		    }  
		    j++;  
		}//考虑重复情况  
	    }  
	    count = max(count,(int)(s.length()-j));//考虑不重复情况类似abcd  
	    return count;  
	}  
};  
