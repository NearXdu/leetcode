class Solution {
    private:
	void buildMap(string end,vector<string>&connect,unordered_set<string>&visit,string& current,const unordered_set<string>&wordList)
	{
	    connect.clear();
	    string cur = current;
	    /*
	       超时：时间复杂度O(n)
	       for(auto i=wordList.begin();i!=wordList.end();i++)
	       {
	       if(visit.find(*i)!=visit.end())
	       continue;
	       if(isConnect(cur,*i))
	       connect.push_back(*i);
	       }
	       */

#if 1
	    for (int i = 0; i < cur.size(); i++)
	    {
		char t = cur[i];
		for (char c = 'a'; c < 'z'; c++)
		{
		    if (c == t)
		    {
			continue;
		    }
		    cur[i] = c;
		    if ((cur == end || wordList.find(cur) != wordList.end()) && (visit.find(cur) == visit.end()))
		    {
			connect.push_back(cur);
		    }
		}
		cur[i]=t;
	    }
#endif
	}
	int BFS(string beginWord, string endWord, unordered_set<string>& wordList)
	{
	    queue<string>q;
	    queue<int>d;//路径distance的辅助队列
	    unordered_set<string>visit;
	    vector<string>connect;
	    q.push(beginWord);
	    d.push(1);
	    while (!q.empty())
	    {
		string current = q.front();
		int tmpDist = d.front();
		q.pop();
		d.pop();
		buildMap(endWord,connect, visit, current, wordList);//获取临接单词
		if (current == endWord)//找到终点
		{
		    return tmpDist;
		}
		for (int i = 0; i < connect.size(); i++)
		{
		    if (visit.find(connect[i]) == visit.end())//未被访问
		    {
			visit.insert(connect[i]);
			q.push(connect[i]);
			d.push(tmpDist + 1);
		    }
		}
	    }
	    return 0;//没有找到路径
	}

    public:
	int ladderLength(string beginWord, string endWord, unordered_set<string>& wordList) {
	    int res= BFS(beginWord, endWord, wordList);
	    return res;
	}
};
