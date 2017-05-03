class Solution {
    private:
	TreeNode* helper(vector<int>&preorder, vector<int>&inorder, map<int, int>&index, int pstart, int pend, int istart, int iend)
	{
	    if (istart > iend)
		return NULL;
	    int rootval = preorder[pstart];//根
	    int rootindex = index[rootval];//根在中序中的索引
	    TreeNode* root = new TreeNode(rootval);
	    root->left = helper(preorder, inorder, index, pstart + 1, pstart + rootindex - istart, istart, rootindex - 1);//递归左子树
	    root->right = helper(preorder, inorder, index, pstart + rootindex - istart + 1, pend, rootindex + 1, iend);//递归右子树
	    return root;
	}
    public:
	TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
	    map<int, int>index;
	    for (int i = 0; i < inorder.size(); i++)
	    {
		index[inorder[i]] = i;//建立值与索引的关系
	    }
	    return helper(preorder, inorder, index,0, preorder.size() - 1, 0, inorder.size() - 1);
	}
};//一定要使用引用否则会超时
