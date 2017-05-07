class Solution {
    private:
	bool isLeafNode(TreeNode*root)//判断是否为叶子节点
	{
	    if (root->left == NULL&&root->right == NULL)
		return true;
	    else
		return false;
	}
	void dfs(TreeNode *root, int &minCount,int sum)
	{
	    if (root == NULL)
	    {
		return;
	    }
	    if (isLeafNode(root))
	    {
		if (sum < minCount)
		    minCount = sum;
	    }
	    else
	    {
		sum++;
		dfs(root->left,minCount,sum);
		dfs(root->right, minCount, sum);
	    }
	}
    public:
	int minDepth(TreeNode* root) {
	    if(root == NULL)
		return 0;
	    int minCount = INT_MAX;
	    int sum = 1;
	    dfs(root, minCount, sum);
	    return minCount;
	}
};
