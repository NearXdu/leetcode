
class Solution {  
    public:  
	vector<int> spiralOrder(vector<vector<int>>& matrix) {  
	    vector<int> result;  
	    if(matrix.empty())  
		return result;  
	    int m = matrix.size();//m行  
	    int n = matrix[0].size();//n列  
	    int count = min(m,n)/2;//count 圈  
	    int mod = min(m, n) % 2;  
	    for (int i = 0; i < count; i++)  
	    {  
		for (int j = i; j < n - i - 1; j++)  
		{  
		    result.push_back(matrix[i][j]);//从左到右  
		}  
		for (int j = i; j <m-1-i ; j++)  
		{  
		    result.push_back(matrix[j][n-1-i]);//从上到下  
		}  
		for (int j = n-i-1; j >=i+1 ;j--)  
		{  
		    result.push_back(matrix[m-i-1][j]);//从右到左  
		}  
		for (int j = m-1-i;j>=i+1;j--)  
		{  
		    result.push_back(matrix[j][i]);//从下到上  
		}  
	    }  
	    if (mod == 1)  
	    {  
		if (n == m)//相当于方阵，需要在中间补上  
		    result.push_back(matrix[count][count]);  
		else if (n > m)  
		{  
		    for (int j = count; j < n - count; j++)  
			result.push_back(matrix[count][j]);  
		}  
		else  
		{  
		    for (int j = count;j<m-count;j++)  
			result.push_back(matrix[j][count]);  
		}  
	    }  
	    return result;  
	}  
};  

