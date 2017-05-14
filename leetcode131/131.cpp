class Solution {
    private:
	vector< vector<bool> >dict;
    public:
	vector< vector<string> > partition(string s);
	void helper(string s,int index,vector<string>tmp,vector <vector<string> >&res);//搜索
	void init(string s);//初始化dict
	void subPalindrome(string s,int left,int right);//创建dict
};

void Solution::init(string s)
{
    vector<bool> tmp(s.size(),false);
    for(int i=0;i<s.size();i++)
    {
	dict.push_back(tmp);
    }
}

void Solution::subPalindrome(string s,int left,int right)
{    

    while(left>=0&&right<s.size()&&s[left]==s[right])
    {
	dict[left][right]=true;
	left --;
	right ++;
    }
}

void Solution::helper(string s,int index,vector<string>tmp,vector<vector<string> >&res)
{
    if(index == s.size())
    {
	res.push_back(tmp);
	return;
    }
    for(int i=index;i<s.size();i++)
    {
	if(dict[index][i])
	{
	    tmp.push_back(s.substr(index,i-index+1));
	    helper(s,i+1,tmp,res);
	    tmp.pop_back();
	}
    }
}


vector < vector<string> > Solution::partition(string s)
{
    vector < vector<string> > res;
    vector<string> tmp;
    init(s);
    for(int i=0;i<s.size();i++)
    {
	subPalindrome(s,i,i);//奇
	subPalindrome(s,i,i+1);//偶
    }
    helper(s,0,tmp,res);
    return res;
}
