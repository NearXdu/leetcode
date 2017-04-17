class Solution {
    private:
	int BinaryFindMax(vector<int>nums, int low, int high)//找到最大值的索引
	{
	    if (high - low <= 1)
	    {
		if (nums[high]>nums[low])
		    return high;
		else
		    return low;
	    }
	    int maxIndexL = BinaryFindMax(nums, low, low + (high - low) / 2);//递归左边
	    int maxIndexR = BinaryFindMax(nums, low + (high - low) / 2 + 1, high);//递归右边
	    int maxIndex = nums[maxIndexL] > nums[maxIndexR] ? maxIndexL : maxIndexR;//取两者较大的的索引
	    return maxIndex;
	}
	int BinarySearch(vector<int>nums, int low, int high, int target)//二分查找
	{
	    while (low <= high)
	    {
		int mid = (low + high) / 2;
		if (target == nums[mid])
		{
		    return mid;
		}
		else if (target > nums[mid])
		{
		    low = mid + 1;
		}
		else
		{
		    high = mid - 1;
		}
	    }
	    return -1;//如果没找到则返回-1
	}
    public:
	int search(vector<int>& nums, int target) {
	    int index = BinaryFindMax(nums, 0, nums.size() - 1);//找到最大值的索引
	    if (nums[index] == target)//如果target就是最大值
		return index;
	    int leftIndex = BinarySearch(nums, 0, index, target);//二分查找最大值左边的子序列
	    int rightIndex = BinarySearch(nums, index + 1, nums.size() - 1, target);//二分查找最大值右边的子序列
	    return (leftIndex == -1) ? rightIndex : leftIndex;
	}
};
