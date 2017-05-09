class Solution {
    int dfs(TreeNode* root,int &maxSum)
    {
	if (root == NULL)
	    return 0;
	int left = dfs(root->left,maxSum);
	int right = dfs(root->right,maxSum);
	int rootval = root->val + max(0, left) + max(0,right);
	if (maxSum < rootval)
	    maxSum = rootval;
	//  return rootval;
	return root->val + max(max(left,right),0);
    }
    public:
    int maxPathSum(TreeNode* root) {
	int maxSum = root->val;
	dfs(root,maxSum);
	return maxSum;
    }
};
