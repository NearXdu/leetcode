bool cmp(const Interval &a, const Interval &b)  
{  
    return a.start < b.start;  
}  
class Solution {  
    private:  
	bool canMerge(Interval &a, Interval &b)//可以合并的情况  
	{  
	    if (a.end >= b.start&&a.end<=b.end)  
	    {  
		a.end = b.end;  
		return true;  
	    }  
	    else if (a.end > b.end)  
	    {  
		return true;  
	    }  
	    return false;  
	}  
    public:  
	vector<Interval> merge(vector<Interval>& intervals) {  
	    int i = 0;  
	    int j;  
	    vector<Interval>result;  
	    sort(intervals.begin(), intervals.end(),cmp);  
	    while (i < intervals.size())  
	    {  
		j = i+1;  
		while (j<intervals.size()&&canMerge(intervals[i], intervals[j]))  
		    j++;  
		result.push_back(intervals[i]);  
		i = j;//一次合并完成，更新判断起点  
	    }  
	    return result;  
	}  
};  
