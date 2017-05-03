class Solution {
    private:
	void helper(TreeNode*root, vector<int>&result)
	{
	    if (root == NULL)
		return;
	    helper(root->left,result);//递归左子树
	    result.push_back(root->val);//访问根
	    helper(root->right,result);//递归右子树
	}
    public:
	vector<int> inorderTraversal(TreeNode* root) {
	    vector<int>result;
	    helper(root, result);
	    return result;
	}
};
