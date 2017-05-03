class Solution {
    private:
	void helper(TreeNode*root, TreeNode*&pre, vector<TreeNode*>&res)
	{
	    if (root == NULL)
		return;
	    helper(root->left, pre, res);
	    if (pre != NULL&&pre->val > root->val)
	    {
		res.push_back(pre);
		res.push_back(root);
	    }
	    pre = root;
	    helper(root->right, pre, res);
	}

    public:
	void recoverTree(TreeNode* root) {
	    vector<TreeNode*>res;
	    TreeNode*pre = NULL;
	    helper(root, pre, res);
	    if (res.size() > 0)
	    {
		if(res.size()==2)
		    swap(res[0]->val, res[1]->val);
		if(res.size()==3)
		    swap(res[0]->val,res[2]->val);
		if(res.size()==4)
		    swap(res[0]->val,res[3]->val);
	    }
	}
};
