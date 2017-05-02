class Solution {

    public:
	void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
	    int i = 0;
	    int j = 0;
	    vector<int>result;
	    vector<int>n1(nums1.begin(), nums1.begin() + m);
	    vector<int>n2(nums2.begin(), nums2.begin() + n);
	    while (i < n1.size() && j < n2.size())
	    {
		if (n1[i] < n2[j])
		{
		    result.push_back(n1[i]);
		    ++i;
		}
		else if (n1[i] > n2[j])
		{
		    result.push_back(n2[j]);
		    ++j;
		}
		else
		{
		    result.push_back(n1[i]);
		    result.push_back(n2[j]);
		    ++i;
		    ++j;
		}
	    }
	    if (i >= n1.size())
	    {
		for (; j < n2.size(); j++)
		{
		    result.push_back(n2[j]);
		}
	    }
	    if (j>=n2.size())
	    {
		for (; i < n1.size(); i++)
		{
		    result.push_back(n1[i]);
		}
	    }
	    nums1.clear();
	    auto it = result.begin();
	    for (int k = 0; k < m + n; k++)
	    {
		nums1.push_back(*it);
		it++;
	    }
	}
};
