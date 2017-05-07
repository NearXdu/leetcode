class Solution {
    private:
	bool isLeafNode(TreeNode* root)
	{
	    if (root->left == NULL&&root->right == NULL)
		return true;
	    else
		return false;
	}
	bool dfs(TreeNode *root, vector<int>nodes, int sum)
	{
	    if (root == NULL)
		return false;
	    nodes.push_back(root->val);
	    if (isLeafNode(root))
	    {
		int val = accumulate(nodes.begin(), nodes.end(), 0);
		if (sum == val)
		    return true;
		else
		    return false;
	    }
	    else
	    {
		return dfs(root->left, nodes, sum)||dfs(root->right, nodes, sum);
	    }
	}
    public:
	bool hasPathSum(TreeNode* root, int sum) {
	    if (root == NULL)
		return false;
	    vector<int>nodes;
	    return dfs(root, nodes, sum);
	}
};
