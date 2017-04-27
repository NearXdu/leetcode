class Solution {  
    public:  
	string addBinary(string a, string b) {  
	    int aLen = a.size();  
	    int bLen = b.size();  
	    int maxLen = max(aLen, bLen) + 1;  
	    int aCount = 0;  
	    int bCount = 0;  
	    while (aCount < maxLen - aLen)  
	    {  
		a.insert(a.begin(), '0');  
		aCount++;  
	    }  
	    while (bCount < maxLen - bLen)  
	    {  
		b.insert(b.begin(), '0');  
		bCount++;  
	    }  
	    string result;  
	    int i = a.size() - 1;  
	    int mod = 0;  
	    while (i >= 0 )  
	    {  
		int aNum = a[i] - '0';  
		int bNum = b[i] - '0';  
		int rNum = aNum + bNum + mod;  
		mod = rNum / 2;  
		rNum %= 2;  
		result.insert(result.begin(), rNum + '0');  
		i--;  
	    }  
	    auto it = result.begin();  
	    while (result.size() > 1 &&* it == '0')  
		result.erase(it);  
	    return result;  
	}  
};  
