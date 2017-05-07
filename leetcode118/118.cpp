class Solution {
    public:
	vector<vector<int>> generate(int numRows) {
	    int row=numRows;
	    int col=numRows;
	    vector< vector<int> >res(row,vector<int>(col));
	    for (int i = 0; i < res.size(); i++)
	    {
		res[i][0] = 1;
		res[i][i] = 1;
	    }//初始化
	    for (int i = 2; i < row; i++)
	    {
		for (int j = 1; j < col; j++)
		{
		    if (i - 1>=0 && j - 1 >= 0)
		    {
			res[i][j] = res[i - 1][j - 1] + res[i - 1][j];
		    }
		}
	    }//赋值
	    for(int i=0;i<row;i++)
	    {
		for(int j=0;j<col;j++)
		{
		    if(res[i][j]==0)
			res[i].pop_back();
		}
	    }//删去0
	    return res;
	}
};
