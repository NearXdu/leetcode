//withou dup

class Solution {
    public:
	int search(vector<int>& nums, int target) {
	    int nSize = nums.size();
	    int low = 0;
	    int high = nSize - 1;
	    while (low <= high)
	    {
		int mid = low + (high - low) / 2;//防止溢出
		if (target == nums[mid])//查找结果成功
		    return mid;
		//这里的细节要用>=原因是计算mid的时候是向下取整有可能
		//mid==low那么nums[mid]==nums[low]
		//排除测试用例 [3,1] 1
		else if (nums[mid] >= nums[low])//左边有序
		{
		    if (target < nums[mid] && target>=nums[low])//target在左边
			high = mid - 1;
		    else//target在右边
			low = mid + 1;
		}
		else//右边有序
		{
		    if (target > nums[mid] && target <= nums[high])
			low = mid + 1;
		    else
			high = mid - 1;
		}
	    }
	    return -1;
	}
};

//with dup
//
class Solution {
    public:
	bool search(vector<int>& nums, int target) {
	    int nSize = nums.size();
	    int low = 0;
	    int high = nSize - 1;
	    while (low <= high)
	    {
		int mid = low + (high - low) / 2;
		if (nums[mid] == target)
		    return true;
		else if (nums[low] < nums[mid])//右边有序
		{
		    if (target >= nums[low] && target<nums[mid])
			high = mid - 1;
		    else
			low = mid + 1;
		}
		else if (nums[low] > nums[mid])//左边有序
		{
		    if (target <= nums[high] && target > nums[mid])
			low = mid + 1;
		    else
			high = mid - 1;
		}
		else//相等要"整体右移"
		{
		    low++;
		}
	    }
	    return false;
	}
};
