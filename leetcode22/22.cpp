class Solution {  
    private:  
	void MyFunc(vector<string>&result, string temp,int left,int right)  
	{  
	    if (left == 0 && right == 0)  
	    {  
		result.push_back(temp);  
		return;  
	    }  
	    else  
	    {  
		if (left!=0&&left <= right)  
		{  
		    MyFunc(result, temp+'(', left-1, right);  
		}  
		if (left < right&&right != 0)  
		{  
		    MyFunc(result, temp+')', left, right-1);  
		}  
	    }  
	}  
    public:  
	vector<string> generateParenthesis(int n) {  
	    string temp="";  
	    int left=n;  
	    int right=n;  
	    vector<string> result;  
	    if (n == 0)  
		return result;  
	    MyFunc(result, temp, left, right);  
	    return result;  
	}  
};  
