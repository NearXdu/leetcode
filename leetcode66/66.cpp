class Solution {  
    public:  
	vector<int> plusOne(vector<int>& digits) {  
	    int len = digits.size();  
	    int mod;  
	    for (int i = len - 1; i >= 0; i--)  
	    {  
		digits[i] = (digits[i] + 1);  
		mod = digits[i] / 10;  
		if (mod == 0)  
		    break;  
		digits[i] %= 10;  
	    }  
	    if (mod == 1)  
		digits.insert(digits.begin(), 1);  
	    return digits;  
	}  
};  
