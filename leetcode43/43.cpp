class Solution {  
    public:  
	string multiply(string num1, string num2) {  
	    if (num1 == "0" || num2 == "0")  
	    {  
		return "0";  
	    }  
	    vector<int> n1(num1.size());  
	    vector<int> n2(num2.size());  
	    int i;  
	    int j;  
	    for (j=0,i = num1.size() - 1; i >= 0; i--,j++)  
	    {  
		n1[j] = num1[i] - '0';  
	    }  
	    for (j = 0, i = num2.size() - 1; i >= 0; i--, j++)  
	    {  
		n2[j] = num2[i] - '0';  
	    }  
	    //string 转 vector<int>方便计算  
	    vector<char>tmpRes(num1.size()+num2.size(),'0');  
	    for (i = 0; i < n1.size(); i++)  
	    {  
		for (j = 0; j < n2.size(); j++)  
		{  
		    int tmp = n1[i] * n2[j];  
		    int tmp2 = (tmpRes[i + j] - '0' + tmp % 10);//当前位加上乘积的模  
		    tmpRes[i + j] = tmp2%10 + '0';  
		    tmpRes[i + j + 1] =tmpRes[i+j+1]+tmp2/10+ tmp / 10;//进位  
		}  
	    }  
	    string result(tmpRes.rbegin(), tmpRes.rend());//逆序构造  
	    i = -1;  
	    while (result[++i] == '0');  
	    result.erase(result.begin(), result.begin() + i);//删除前缀0  
	    //debugging  
	    /*  while (1) 
		{ 
		int a; 
		}*/  
	    return result;  
	}  
};  
