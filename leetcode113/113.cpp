class Solution {
    private:
	bool isLeafNode(TreeNode * root)
	{
	    if(root->left==NULL&&root->right==NULL)
		return true;
	    else
		return false;
	}
	void dfs(TreeNode *root,int sum,vector<int>tmp,vector<vector<int>>&res)
	{
	    if(root==NULL)
		return ;
	    tmp.push_back(root->val);
	    if(isLeafNode(root))
	    {
		int val=accumulate(tmp.begin(),tmp.end(),0);
		if(val == sum)
		    res.push_back(tmp);
	    }
	    else
	    {
		dfs(root->left,sum,tmp,res);
		dfs(root->right,sum,tmp,res);
	    }
	}
    public:
	vector<vector<int>> pathSum(TreeNode* root, int sum) {
	    vector<int>tmp;
	    vector< vector<int> >res;
	    if(root==NULL)
		return res;
	    dfs(root,sum,tmp,res);
	    return res;
	}
};
