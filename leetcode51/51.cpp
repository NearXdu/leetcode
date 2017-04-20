class Solution {  
    private:  
	vector<vector<string>>result;  
	bool check(int row,int col, int n,vector<string>m)//检测每行，每列，左右两个斜行  
	{  
	    if (row == 0)  
		return true;  
	    int i;  
	    int j;  
	    for (i = 0; i < row; i++)  
	    {  
		if (m[i][col] == 'Q')  
		    return false;  
	    }  
	    i = row - 1;  
	    j = col - 1;  
	    while (i >= 0 && j >= 0)  
	    {  
		if (m[i][j] == 'Q')  
		    return false;  
		i--;  
		j--;  
	    }  
	    i = row - 1;  
	    j = col + 1;  
	    while (i >= 0 && j < n)  
	    {  
		if (m[i][j] == 'Q')  
		    return false;  
		i--;  
		j++;  
	    }  
	    return true;  
	}  
	void add(vector<string>m)  
	{  
	    result.push_back(m);  
	}  
	void solve(int row,int n,vector<string>m)  
	{  
	    int col;  
	    if (row == n )//所有行已经全部放置  
	    {  
		add(m);  
		return;  
	    }  
	    for (col = 0; col<n; col++)  
	    {  
		if (check(row, col,n,m) == true)//查看row行col列  
		{  
		    m[row][col] = 'Q';//放置一枚Q  
		    solve(row + 1,n,m);//往下行继续递归放置  
		    m[row][col] = '.';//如果没有达到递归到返回条件，将之前放置的Q取消  
		}  
	    }  
	}  
    public:  
	vector<vector<string>> solveNQueens(int n) {  
	    vector<string>m(n,string(n,'.'));//Init  
	    solve(0, n,m);  
	    return result;  
	}  
};  
