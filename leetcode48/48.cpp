class Solution {  

    public:  
	void rotate(vector<vector<int>>& matrix) {  
	    int len = matrix[0].size()-1;  
	    int i;  
	    int j;  
	    vector<vector<int>>temp(matrix);  
	    for(i=0;i<matrix[0].size();i++)  
	    {  
		for(j=0;j<matrix[0].size();j++)  
		{  
		    //swap(matrix[i][j],temp[j][len-i]);  
		    //matrix[i][j]=temp[j][len-i];  
		    matrix[j][len-i]=temp[i][j];  
		}  
	    }  
	}  
};  
