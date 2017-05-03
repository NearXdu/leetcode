class Solution {
    private:
	void helper(vector<vector<int>>&result, TreeNode*root)
	{
	    if (root == NULL)
		return;
	    int front=0;
	    int rear=1;
	    int level = 1;
	    vector<TreeNode*>q;
	    vector<int>temp;
	    q.push_back(root);
	    while (front < q.size())
	    {
		rear = q.size();
		while (front < rear)//当前层
		{
		    if ( level % 2 == 1)
		    {
			temp.push_back(q[front]->val);
		    }
		    else if (level %2 ==0)
		    {
			temp.insert(temp.begin(), q[front]->val);
		    }
		    if (q[front]->left != NULL)
			q.push_back(q[front]->left);
		    if (q[front]->right != NULL)
			q.push_back(q[front]->right);
		    ++front;
		}
		++level;
		result.push_back(temp);
		temp.clear();
	    }
	}
    public:
	vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
	    vector<vector<int>>result;
	    helper(result, root);
	    return result;
	}
};
