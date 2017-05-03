class Solution {
    private:
	void dfs(TreeNode* root,vector<int >&result)//先序遍历（根->左子树->右子树）
	{
	    if (root == NULL)
	    {
		result.push_back(-1);
		return;
	    }
	    result.push_back(root->val);
	    dfs(root->left, result);
	    dfs(root->right, result);
	}
	void dfsr(TreeNode* root, vector<int >&result)//先序遍历（根->右子树->左子树）
	{
	    if (root == NULL)
	    {
		result.push_back(-1);
		return;
	    }
	    result.push_back(root->val);
	    dfsr(root->right, result);
	    dfsr(root->left, result);
	}
    public:
	bool isSymmetric(TreeNode* root) {
	    vector<int>res1;
	    vector<int>res2;
	    dfs(root, res1);
	    dfsr(root, res2);
	    return equal(res1.cbegin(), res1.cend(), res2.cbegin());
	}
};
