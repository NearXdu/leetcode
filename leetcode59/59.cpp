class Solution {  
    public:  
	vector<vector<int>> generateMatrix(int n) {  
	    //vector<int>temp(n);  
	    vector<vector<int>>matrix(n,vector<int>(n));  
	    int i;  
	    int count = n / 2;  
	    int j;  
	    int number = 1;  
	    int mod = n % 2;  
	    for (i = 0; i < count; i++)  
	    {  
		for (int j = i; j < n - i - 1; j++)  
		{  
		    matrix[i][j] = number++;  
		}  
		for (int j = i; j < n - 1 - i; j++)  
		{  
		    matrix[j][n - 1 - i] = number++;  
		}  
		for (int j = n - i - 1; j >= i + 1; j--)  
		{  
		    matrix[n - i - 1][j] = number++;  
		}  
		for (int j = n - 1 - i; j >= i + 1; j--)  
		{  
		    matrix[j][i] = number++;  
		}  
	    }  
	    if (mod == 1)  
		matrix[count][count] = number;  
	    return matrix;  
	}  
};  
