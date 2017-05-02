class Solution {
    public:
	int largestRectangleArea(vector<int>& heights) {
	    int nSize = heights.size();
	    int i = 0;
	    int maxSize = 0;
	    while (i < nSize)
	    {
		int j = i+1;
		int k = i-1;
		int sum = heights[i];
		while (k > 0&&heights[k]>heights[i])
		{
		    k--;
		    sum += heights[i];
		}
		while (j<nSize&&heights[j]>heights[i])
		{
		    j++;
		    sum += heights[i];
		}
		maxSize = max(maxSize, sum);
		i++;
	    }
	    return maxSize;
	}
};

class Solution {
    public :
	int largestRectangleArea(vector<int>& heights){
	    heights.push_back(0);
	    int nSize = heights.size();
	    stack<int> index;
	    int maxSize = 0;
	    int i=0;
	    while(i<nSize)
	    {
		if (index.empty()||heights[i]>heights[index.top()])
		{
		    index.push(i);
		    i++;
		}
		else
		{
		    int j = index.top();
		    index.pop();
		    maxSize = max(maxSize, heights[j]*(index.empty() ? i : (i - index.top() - 1) ));

		}
	    }
	    return maxSize;
	}
};
