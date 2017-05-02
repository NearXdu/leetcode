
class Solution {  
    private:  
	void setRowAndCol(vector<int>point,vector<vector<int>> &matrix)  
	{  
	    //行  
	    for (int j = 0; j < matrix[0].size(); j++)  
	    {  
		matrix[point[0]][j] = 0;  
	    }  
	    //列  
	    for (int i = 0; i < matrix.size(); i++)  
	    {  
		matrix[i][point[1]] = 0;  
	    }  
	}  
    public:  
	void setZeroes(vector<vector<int>>& matrix) {  
	    vector<vector<int>>points;  
	    vector<int>point(2);  
	    for (int i = 0; i < matrix.size(); i++)  
	    {  
		for (int j = 0; j < matrix[0].size(); j++)  
		{  
		    if (matrix[i][j] == 0)  
		    {  
			point[0] = i;  
			point[1] = j;  
			points.push_back(point);  
		    }  
		}  
	    }  
	    for (int i = 0; i < points.size(); i++)  
	    {  
		setRowAndCol(points[i], matrix);  
	    }  
	}  
};  

