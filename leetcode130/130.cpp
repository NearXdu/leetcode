class Solution {
    private:
	void bfs(vector< vector<char> >& board,int i,int j,int M,int N);
    public:
	void solve(vector<vector<char>>& board);

};

void Solution::solve(vector < vector<char> >& board)
{
    if(board.size()==0 || board[0].size()==0)
	return;
    int m = board.size();
    int n = board[0].size();

    for(int i=0;i<m;i++)//first col 
    {
	if(board[i][0]=='O')
	{
	    bfs(board,i,0,m,n);
	}
    }
    for(int i=0;i<m;i++) //last col
    {
	if(board[i][n-1]=='O')
	{

	    bfs(board,i,n-1,m,n);
	    //bfs
	}
    }
    for(int i=0;i<n;i++)//first row 
    {
	if(board[0][i]=='O')
	{

	    bfs(board,0,i,m,n);
	    //bfs
	}
    }
    for(int i=0;i<n;i++) //last row  
    {
	if(board[m-1][i]=='O')
	{

	    bfs(board,m-1,i,m,n);
	    //bfs
	}
    }

#if 1
    for(int i=0;i<m;i++)
    {
	for(int j=0;j< n;j++)
	{
	    if(board[i][j]=='O')
	    {
		board[i][j]='X';
	    }
	    if(board[i][j]=='F')
	    {
		board[i][j]='O';
	    }
	}
    }
#endif

}


void Solution::bfs(vector<vector<char>>& board,int i,int j,int M,int N)
{
    queue< pair<int,int>  >q;//index (i,j)

    board[i][j]='F';//flag
    q.push(pair<int,int>(i,j));

    while(!q.empty())
    {
	int row = q.front().first;
	int col = q.front().second;
	q.pop();

	if(row-1>0 &&board[row-1][col]=='O')
	{
	    board[row-1][col]='F';//F: flag
	    q.push(pair<int,int>(row-1,col));
	}

	if(row+1<M &&board[row+1][col]=='O')
	{
	    board[row+1][col]='F';//F: flag
	    q.push(pair<int,int>(row+1,col));
	}
	if(col-1>0 &&board[row][col-1]=='O')
	{
	    board[row][col-1]='F';//F: flag
	    q.push(pair<int,int>(row,col-1));
	}
	if(col+1<N &&board[row][col+1]=='O')
	{
	    board[row][col+1]='F';//F: flag
	    q.push(pair<int,int>(row,col+1));
	}

    }
}
