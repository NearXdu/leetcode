bool cmp(const int & a,const int & b)
{
    return a<b;
}
class Solution {
    public:
	int removeElement(vector<int>& nums, int val) {
	    if(nums.size()==0)
		return 0;
	    sort(nums.begin(),nums.end(),cmp);
	    vector<int>::iterator it;
	    while((it=find(nums.begin(),nums.end(),val))!=nums.end())
	    {
		nums.erase(it);
	    }
	    return nums.size();
	}
};
