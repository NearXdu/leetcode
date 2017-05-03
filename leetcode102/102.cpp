class Solution {
    private:
	void bfs(TreeNode *root, vector<vector<int>>&result)
	{
	    if (root==NULL)
		return;
	    vector<int>temp;
	    vector<TreeNode*>q;
	    int front = 0;
	    int rear = 1;
	    q.push_back(root);
	    while (front < q.size())
	    {
		rear = q.size();
		while (front < rear)
		{
		    temp.push_back(q[front]->val);
		    if (q[front]->left != NULL)
			q.push_back(q[front]->left);
		    if (q[front]->right != NULL)
			q.push_back(q[front]->right);
		    ++front;
		}
		result.push_back(temp);
		temp.clear();
	    }
	}
    public:
	vector<vector<int>> levelOrder(TreeNode* root) {
	    vector<vector<int>>result;
	    bfs(root, result);
	    return result;
	}
};
