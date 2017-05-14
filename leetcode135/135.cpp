class Solution {
    public:
	int candy( vector <int>& ratings)
	{
	    int N= ratings.size();
	    vector<int>count(N,1);
	    for(int i=1;i<ratings.size();i++)
	    {
		if(ratings[i]>ratings[i-1])
		    count[i]=count[i-1]+1;
	    }
	    for(int i=N-1;i>0;i--)
	    {
		if(ratings[i]<ratings[i-1])
		{
		    count[i-1]=max(count[i]+1,count[i-1]);
		}
	    }
	    return accumulate(count.begin(),count.end(),0);
	}
};
