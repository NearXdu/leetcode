class Solution {
    private:
	TreeNode* helper(vector<int>&nums, int left, int right)
	{
	    if (left > right)
	    {
		return NULL;
	    }
	    int mid = left + (right - left) / 2;
	    TreeNode* root = new TreeNode(nums[mid]);
	    root->left = helper(nums, left, mid - 1);
	    root->right = helper(nums, mid + 1, right);
	    return root;
	}
    public:
	TreeNode* sortedArrayToBST(vector<int>& nums) {
	    TreeNode*root = helper(nums, 0, nums.size() - 1);
	    return root;
	}
};
