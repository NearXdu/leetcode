class Solution {
    private:
	bool valid(string s)
	{
	    if (s.size() == 2)
	    {
		if (s[0] == '0')//"01"情况排除
		    return false;
	    }
	    if (s.size() == 3)
	    {
		if (s[0] == '0' || atoi(s.c_str()) > 255)//除了"001"还要排除大于255
		    return false;
	    }
	    return true;
	}
	void help(string s, int len, vector<string>& tmpRes, vector<string>&result, int index)
	{
	    if (tmpRes.size() == 4)
	    {
		//当满足条件时，s里面的字符肯定用完，i==s.size()-1，则index==i+1==s.size()
		if (index == s.size())
		{
		    string ip;
		    for (int i = 0; i < tmpRes.size(); i++)
		    {
			ip += (tmpRes[i] + '.');
		    }
		    ip.pop_back();
		    result.push_back(ip);
		}
		return;
		//下述方法每次都计算ip的长度，效率较低
		/*
		   string ip;
		   for (int i = 0; i < tmpRes.size(); i++)
		   {
		   ip += (tmpRes[i] + '.');
		   }
		   ip.pop_back();
		   if (ip.size() == len + 3)
		   {
		   result.push_back(ip);
		   }
		   else
		   return;
		   */
	    }
	    string str;
	    for (int i = index; (i < len) && (str.size()<3); i++)
	    {
		str.push_back(s[i]);
		if (valid(str))
		{
		    tmpRes.push_back(str);
		    help(s, len, tmpRes, result, i + 1);
		    tmpRes.pop_back();
		}
	    }
	}
    public:
	vector<string> restoreIpAddresses(string s) {
	    vector<string>result;
	    vector<string>tmpRes;
	    help(s, s.size(), tmpRes, result, 0);
	    return result;
	}
};
