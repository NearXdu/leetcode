class Solution {  
    private:  
	int num;  
	bool check(int row, int col, int n, vector<string>m)  
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
	    num++;  
	}  
	void solve(int row, int n, vector<string>m)  
	{  
	    int col;  
	    if (row == n)  
	    {  
		add(m);  
		return;  
	    }  
	    for (col = 0; col<n; col++)  
	    {  
		if (check(row, col, n, m) == true)  
		{  
		    m[row][col] = 'Q';  
		    solve(row + 1, n, m);  
		    m[row][col] = '.';  
		}  
	    }  
	}  
    public:  
	int totalNQueens (int n) {  
	    vector<string>m(n, string(n, '.'));  
	    num = 0;  
	    solve(0, n, m);  
	    return num;  
	}  
};  
