class Solution {
    private:
	TreeNode* helper(vector<int>&inorder, vector<int>&postorder, map<int, int>&index,int pstart,int pend,int instart,int inend)
	{
	    if (instart > inend)
		return NULL;
	    int rootval = postorder[pend];
	    int rootindex = index[rootval];
	    TreeNode*root = new TreeNode(rootval);
	    root->right = helper(inorder, postorder, index, pend-inend+rootindex, pend - 1, rootindex + 1, inend);
	    root->left = helper(inorder, postorder, index, pstart, pend - inend + rootindex-1, instart,rootindex-1);
	    return root;
	}
    public:
	TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
	    map<int, int>index;
	    for (int i = 0; i < inorder.size(); i++)
	    {
		index[inorder[i]] = i;
	    }
	    return helper(inorder, postorder, index, 0, postorder.size() - 1, 0, inorder.size() - 1);
	}
};
