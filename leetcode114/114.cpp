class Solution {
    private:
	void dfs(TreeNode*root, vector<TreeNode*>&Nodes)
	{
	    if (root == NULL)
		return;
	    Nodes.push_back(root);
	    dfs(root->left, Nodes);
	    dfs(root->right, Nodes);
	}
    public:
	void flatten(TreeNode* root) {
	    if (root == NULL)
		return;
	    vector<TreeNode*>Nodes;
	    dfs(root, Nodes);
	    int i;
	    root->left = NULL;
	    for (i = 0; i < Nodes.size() - 1; i++)
	    {
		Nodes[i]->right = Nodes[i + 1];
		Nodes[i]->left = NULL;
	    }
	    Nodes[i]->right = NULL;
	    root = Nodes[0];
	}
};
