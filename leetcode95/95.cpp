class Solution {
    private:
	vector<TreeNode*> help(int left, int right)
	{
	    vector<TreeNode*>res;
	    if (left > right)
	    {
		return vector<TreeNode*>(1,NULL);
	    }
	    for (int i = left; i <= right; i++)
	    {
		//递归左右子树
		vector<TreeNode*>ltree = help(left, i - 1);
		vector<TreeNode*>rtree = help(i + 1, right);
		for (int j = 0; j < ltree.size(); j++)
		{
		    for (int k = 0; k < rtree.size(); k++)
		    {
			TreeNode*root = new TreeNode(i);
			root->left = ltree[j];
			root->right = rtree[k];
			res.push_back(root);//向上合成新的数
		    }
		}
	    }//end for
	    return res;
	}
    public:
	vector<TreeNode*> generateTrees(int n) {
	    return n == 0 ? vector<TreeNode*>() : help(1, n);
	}
};
