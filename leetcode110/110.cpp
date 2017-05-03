class Solution {
    private:
	int dfs(TreeNode *root)
	{
	    if (root == NULL)
		return 0;
	    return max(dfs(root->left), dfs(root->right)) + 1;
	}//求树高
    public:
	bool isBalanced(TreeNode* root) {
	    if (root == NULL)
		return true;
	    int lHeight=dfs(root->left);
	    int rHeight = dfs(root->right);
	    if (abs(lHeight - rHeight) > 1)
		return false;
	    return isBalanced(root->left) && isBalanced(root->right);//递归左右子树
	}
};
