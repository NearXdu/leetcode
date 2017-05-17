class Solution {
    private:
	/*计算斜率*/
	double Slope(Point&a ,Point&b)
	{
	    return (b.y-a.y)*1.0/(b.x-a.x);
	}

    public:
	int maxPoints(vector<Point>& points)
	{
	    if(points.size()<2)
		return points.size();
	    int res=0;
	    for(int i=0;i<points.size();i++)
	    {
		int local=0;//局部最优
		int same=0;//与当前点p重合的点
		int infinity=0;//与当前点p平行于Y轴的点
		unordered_map<double,int>count;//与当前点p斜率相同的点

		for(int j=i+1;j<points.size();j++)
		{
		    if(points[i].x==points[j].x&&points[i].y==points[j].y)
		    {
			++same;
		    }
		    else if(points[i].x==points[j].x)
		    {
			++infinity;
		    }
		    else
		    {
			double slope= Slope(points[i],points[j]);

			count[slope]++;
		    }
		}
		int tmp=0;
		for(auto it = count.begin();it!=count.end();it++)
		{
		    tmp=max(tmp,it->second);
		}
		local=max(tmp+same,same+infinity);//局部最优
		res=max(local,res);//全局最优
	    }
	    return res+1;//包含本身
	}
};
