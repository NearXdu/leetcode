class Solution {  
    public:  
	bool searchMatrix(vector<vector<int>>& matrix, int target) {  
	    int i = matrix.size()-1;  
	    int j = 0;  
	    while (i >=0 && j <matrix[0].size())  
	    {  
		if (target > matrix[i][j])  
		{  
		    j++;  
		}  
		else if (target < matrix[i][j])  
		{  
		    i--;  
		}  
		else  
		{  
		    return true;  
		}  
	    }  
	    return false;  
	}  
};  
