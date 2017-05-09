class Solution {
    public:
	int longestConsecutive(vector<int>& nums) {
	    if (nums.size() == 1)
		return 1;
	    sort(nums.begin(), nums.end());//排序
	    int count = 1;
	    int maxCount = 1;
	    for (int i = 0; i < nums.size(); i++)
	    {
		if (nums[i + 1] == nums[i] + 1)//满足要求则count++
		    count++;
		else if (nums[i + 1] == nums[i])//相等不计数
		    continue;
		else//出现不满足条件时记录当前最大并count返回
		{
		    if (maxCount < count)
			maxCount = count;
		    count = 1;
		}
	    }
	    if (maxCount < count)//这里是必要的，防止不进入最后一个条件判断里面
		maxCount = count;
	    return maxCount;
	}
};


class Solution {
    public:
	int longestConsecutive(vector<int>& nums) {
	    unordered_set<int> numSet(nums.begin(), nums.end());
	    unordered_set<int> visit;
	    int count = 1;
	    int maxCount = 0;

	    for (auto it = numSet.begin();it!=numSet.end();it++)
	    {
		int curr = *it;
		int i = curr + 1;
		int count = 1;
		while (true)
		{
		    if (numSet.find(i) != numSet.end() && visit.find(i) == visit.end())
		    {
			count++;
			visit.insert(i);
			i++;
		    }
		    else
			break;
		}
		i = curr - 1;
		while (true)
		{
		    if (numSet.find(i) != numSet.end() && visit.find(i) == visit.end())
		    {
			count++;
			visit.insert(i);
			i--;
		    }
		    else
			break;
		}
		if (maxCount < count)
		    maxCount = count;
		if (visit.size() == numSet.size())
		    return maxCount;
	    }
	    return maxCount;

	}
};
