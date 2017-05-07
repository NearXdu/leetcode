class Solution {
    public:
	vector<int> getRow(int rowIndex) {
	    int row=rowIndex+1;
	    int col=rowIndex+1;
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
	    return res[rowIndex];//直接返回
	}
};
////////////////////////////
class Solution {
    public:
	vector<int> getRow(int rowIndex) {
	    vector<int> res(rowIndex+1);
	    res[rowIndex]=1;
	    for(int i=0;i<rowIndex+1;i++)
	    {
		for(int j=rowIndex-1;j>0;j--)
		{
		    res[j]=res[j-1]+res[j];
		}
		res[0]=1;
	    }
	    return res;
	}
};
