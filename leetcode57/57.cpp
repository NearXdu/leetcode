class Solution {  
    private:  
	bool canMerge(Interval &a, Interval &b)  
	{  
	    if (a.end >= b.start&&a.end <= b.end)  
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
	vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {  
	    vector<Interval>result;  
	    int index = 0;  
	    while (index<intervals.size()&&intervals[index].start < newInterval.start)  
		index++;//插入位置的索引  
	    intervals.insert(intervals.begin() + index, newInterval);  
	    int i = 0;  
	    int j;  
	    while (i < intervals.size())  
	    {  
		j = i + 1;  
		while (j<intervals.size() && canMerge(intervals[i], intervals[j]))  
		    j++;  
		result.push_back(intervals[i]);  
		i = j;  
	    }  
	    return result;  
	}  
};  
