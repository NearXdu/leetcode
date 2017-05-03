class Solution {
    private:
	void help(vector<vector<int>>&result,TreeNode * root)
	{
	    if(root == NULL)
		return;
	    vector<TreeNode*> q;
	    vector<int>tmp;
	    int front = 0;
	    int rear =1;
	    q.push_back(root);
	    while(front < q.size())
	    {
		rear=q.size();
		while(front < rear)
		{
		    tmp.push_back(q[front]->val);
		    if(q[front]->left !=NULL)
			q.push_back(q[front]->left);
		    if(q[front]->right !=NULL)
			q.push_back(q[front]->right);
		    ++front;
		}
		result.push_back(tmp);
		tmp.clear();
	    }
	}
    public:
	vector<vector<int>> levelOrderBottom(TreeNode* root) {
	    vector<vector<int>>result;
	    help(result,root);
	    vector<vector<int>>inverse(result.rbegin(),result.rend());
	    return inverse;
	}
};
