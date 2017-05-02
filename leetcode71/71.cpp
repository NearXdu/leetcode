
class Solution {  
    private:  
	void remove(string & path)  
	{  
	    int i = path.size() - 1;  
	    while (i > 0 && path[i] == '/')  
	    {  
		path.pop_back();  
		i--;  
	    }  
	}  
    public:  
	string simplifyPath(string path) {  
	    remove(path);  
	    vector<char>tmpResult;  
	    stack<char>symbol;  
	    int dotCount = 0;  
	    for (int i = 0; i < path.size(); i++)  
	    {  
		if (path[i] == '/')  
		{  
		    if (!symbol.empty() && symbol.top() == '/')  
			continue;  
		    symbol.push(path[i]);  
		}  
		else if (path[i] == '.')  
		{  
		    if (path[i + 1] == '.')  
		    {  
			dotCount = 0;  
			int j = i;  
			while (j < path.size() && path[j] == '.')  
			{  
			    dotCount++;  
			    j++;  
			}  
			if (dotCount == 2)  
			{  
			    if (path[j] == '/'||j==path.size())  
			    {  
				symbol.pop();//去掉'/'  
				while (!symbol.empty() && symbol.top() != '/')  
				    symbol.pop();  
				if (!symbol.empty())  
				    symbol.pop();  
				i = i + 1;  
			    }  
			    else  
			    {  
				symbol.push('.');  
			    }  
			}  
			else  
			{  
			    i += dotCount - 1;  
			    while (dotCount--)  
			    {  
				symbol.push('.');  
			    }  
			}  
		    }  
		    else if (isalpha(path[i + 1]))  
		    {  
			symbol.push(path[i]);  
			continue;  
		    }  
		}  
		else  
		{  
		    symbol.push(path[i]);  
		}  
	    }  
	    if (symbol.empty())  
		return "/";  
	    while (!symbol.empty())  
	    {  
		tmpResult.insert(tmpResult.begin(), symbol.top());  
		symbol.pop();  
	    }  
	    string result(tmpResult.begin(), tmpResult.end());  
	    remove(result);  
	    return result;  
	}  
};  

