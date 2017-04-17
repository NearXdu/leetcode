class Solution {
    private:
	bool ValidRow(vector< vector<char> >&board)//对行判断
	{
	    map<char, int>myMap;
	    for (int i = 0; i < 9; i++)
	    {
		vector<char> oneRow(board[i]);//存储第i行数据
		for (int j = 0; j < 9; j++)
		{
		    if (oneRow[j] == '.')
			continue;
		    else
		    {
			if (myMap.find(oneRow[j]) != myMap.end())//如果出现同样的数字则立刻返回false
			    return false;
			else
			    myMap[oneRow[j]] = 1;
		    }
		}
		myMap.clear();
		oneRow.clear();
	    }
	    return true;
	}
	bool ValidCol(vector< vector<char> >&board)//对每列进行判断
	{
	    map<char, int>myMap;
	    for (int i = 0; i < 9; i++)
	    {
		vector<char>oneCol;
		for (int j = 0; j < 9; j++)
		{
		    oneCol.push_back(board[j][i]);//第i列
		}
		for (int k = 0; k < 9; k++)
		{
		    if (oneCol[k] == '.')
			continue;
		    else
		    {
			if (myMap.find(oneCol[k]) != myMap.end())//如果有重复立刻返回
			    return false;
			else
			    myMap[oneCol[k]] = 1;
		    }
		}
		myMap.clear();
		oneCol.clear();
	    }
	    return true;
	}
	bool ValidMatrix(vector< vector<char> >&board)//判断每个3X3的九宫格
	{

	    map<char, int>myMap;
	    vector<char>oneMatrix;
	    //九宫格按照从左往右从上往下的顺序
	    for (int k = 0; k < 9; k++)
	    {
		for (int i = 0; i < 3; i++)
		{
		    for (int j = 0; j < 3; j++)
		    {
			oneMatrix.push_back(board[i + (k / 3) * 3][j + (k % 3) * 3]);
		    }
		}


		for (int l = 0; l < 9; l++)
		{
		    if (oneMatrix[l] == '.')
			continue;
		    else
		    {
			if (myMap.find(oneMatrix[l]) != myMap.end())//出现重复数字立刻返回false
			    return false;
			else
			    myMap[oneMatrix[l]] = 1;
		    }
		}
		oneMatrix.clear();
		myMap.clear();
	    }
	    return true;
	}
    public:
	bool isValidSudoku(vector<vector<char>>& board) {
	    return ValidCol(board) && ValidMatrix(board) && ValidRow(board);
	}
};
