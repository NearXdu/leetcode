class Solution {  
    private:  
	double area(int up,int down,int height)  
	{  
	    if(up==0||down==0)  
		return 0.0;  
	    double result = height*min(up,down)*1.0;  
	    return result;  
	}  
    public:  
	int maxArea(vector<int>& height) {  
	    int i=0;  
	    int j=height.size()-1;  
	    double max = 0.0;  
	    while(i<j)  
	    {  
		double result = area(height[i],height[j],j-i);  
		if(result > max)  
		    max=result;  
		if(height[j]>height[i])  
		    i++;  
		else  
		    j--;  
	    }  
	    return (int)max;  
	}  
}; 
