class Solution {
    private:
	void helper(TreeNode* root,vector<int>&result)//中序遍历
	{
	    if (root == NULL)
		return;
	    helper(root->left, result);
	    result.push_back(root->val);
	    helper(root->right, result);
	}
    public:
	bool isValidBST(TreeNode* root) {
	    vector<int>result;
	    helper(root, result);
	    for (int i = 0; i < result.size()-1; i++)
	    {
		if (result[i]>result[i + 1])
		    return false;
	    }
	    return true;
	}
};


class Solution {
    private:
	bool helper(TreeNode * root, long & pre)
	{
	    if (root == NULL)
		return true;
	    bool left = helper(root->left, pre);
	    if (pre >= root->val)
		return false;
	    pre = root->val;
	    return left && helper(root->right, pre);
	}

    public:
	bool isValidBST(TreeNode* root) {
	    //  int pre = INT_MIN;
	    long pre = numeric_limits<long>::min();
	    return helper(root, pre);
	}
};


class Solution {
    private:
	bool helper(TreeNode * root, long  minVal, long maxVal)
	{
	    if (root == NULL)
		return true;
	    if (minVal >= root->val || maxVal<=root->val)
		return false;
	    return helper(root->left, minVal, root->val)&&helper(root->right,root->val,maxVal);
	}

    public:
	bool isValidBST(TreeNode* root) {
	    //  int pre = INT_MIN;
	    long minVal = numeric_limits<long>::min();
	    long maxVal = numeric_limits<long>::max();
	    return helper(root, minVal,maxVal);
	}
};
