class Solution {
    private:
	unordered_set<int>index;
	bool dfs(string s, unordered_set<string>&wordDict,int start)
	{
	    if (start==s.size())//DFS返回
		return true;
	    if (index.find(start) != index.end())//不满足条件的索引
		return false;
	    for (int i = 1; i <= s.size()-start; i++)
	    {
		string sub = s.substr(start, i);
		if (wordDict.find(sub) != wordDict.end())
		{
		    if (dfs(s, wordDict, start+i))
			return true;
		    else
			index.insert(start+i);//将不满足条件的索引添加到容器中
		}
	    }
	    return false;
	}
    public:
	bool wordBreak(string s, unordered_set<string>& wordDict) {
	    return dfs(s, wordDict,0);
	}
};
