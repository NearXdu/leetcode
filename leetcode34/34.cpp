class Solution {
    public:
	vector<int> searchRange(vector<int>& nums, int target) {
	    int len = nums.size();
	    int low = 0;
	    int high = len - 1;
	    int mid;
	    int resNum1;
	    int resNum2;
	    vector<int> result;
	    while (low < high)// 二分查找上界
	    {
		int mid = low + (high - low) / 2;
		if (nums[mid] < target)
		{
		    low = mid + 1;
		}
		else
		    high = mid;
	    }
	    resNum1 = nums[low] == target ? low : -1;

	    low = 0;
	    high = len - 1;
	    while (low < high)//二分查找下界
	    {
		int mid = low + (high - low+1) / 2;//!!!!!若nums[mid]<=target时，若此时low+1==high,进入死循环
		if (nums[mid] > target)
		{
		    high = mid - 1;
		}
		else
		    low = mid;
	    }
	    resNum2 = nums[high] == target ? high : -1;

	    result.push_back(resNum1);
	    result.push_back(resNum2);
	    return result;
	}
};
