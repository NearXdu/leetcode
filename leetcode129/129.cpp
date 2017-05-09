class Solution {
    private:
	void dfs(TreeNode *root, vector<int>tmp, int&sum);
    public:
	int sumNumbers(TreeNode* root) {
	    int sum = 0;
	    vector<int>tmp;
	    dfs(root, tmp, sum);
	    return sum;
	}
};
void Solution::dfs(TreeNode *root,vector<int>tmp,int &sum)
{
    if (root == NULL)
    {
	return;
    }
    if (root->left == NULL && root->right == NULL)//叶子节点
    {
	tmp.push_back(root->val);
	int tmpsum = 0;
	for (int i = 0; i < tmp.size(); i++)
	{
	    tmpsum = tmpsum * 10 + tmp[i];//计算path值
	}
	sum += tmpsum;
	return;
    }
    tmp.push_back(root->val);
    dfs(root->left,tmp,sum);
    dfs(root->right, tmp,sum);
}
