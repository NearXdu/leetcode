class Solution {
    private:
	int dfs(TreeNode* root, int depth, int maxDepth)
	{
	    if (root == NULL)
	    {
		if (depth > maxDepth)
		    maxDepth = depth;
		return maxDepth;
	    }
	    return max(dfs(root->left, depth + 1, maxDepth), dfs(root->right, depth + 1, maxDepth));
	}
    public:
	int maxDepth(TreeNode* root) {
	    int depth = dfs(root, 0, INT_MIN);
	    return depth;
	}
};
class Solution{
    public:
	int maxDepth(TreeNode* root) {
	    if (root == NULL)
		return 0;
	    return max(maxDepth(root->left), maxDepth(root->right)) + 1;
	}
};
class Solution{
    public:
	int maxDepth(TreeNode* root){
	    if (root == NULL)
		return 0;
	    vector<TreeNode*>q;
	    int front = 0;
	    int rear = 1;
	    int level = 0;
	    q.push_back(root);
	    while (front < q.size())
	    {
		rear = q.size();
		while (front < rear)
		{
		    if (q[front]->left != NULL)
		    {
			q.push_back(q[front]->left);
		    }
		    if (q[front]->right != NULL)
		    {
			q.push_back(q[front]->right);
		    }
		    ++front;
		}
		++level;
	    }
	    return level;
	}
};
