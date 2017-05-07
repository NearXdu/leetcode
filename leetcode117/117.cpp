class Solution {
    private:
	void bfs(TreeLinkNode *root)
	{
	    if (root == NULL)
		return;
	    vector<TreeLinkNode*>temp;
	    vector<TreeLinkNode*>q;
	    int front = 0;
	    int rear = 1;
	    q.push_back(root);
	    while (front < q.size())
	    {
		rear = q.size();
		while (front < rear)
		{
		    temp.push_back(q[front]);
		    if (q[front]->left != NULL)
			q.push_back(q[front]->left);
		    if (q[front]->right != NULL)
			q.push_back(q[front]->right);
		    ++front;
		}
		int i;
		for ( i = 0; i < temp.size()-1; i++)
		{
		    temp[i]->next = temp[i + 1];
		}
		temp[i]->next = NULL;
		temp.clear();//结束一层
	    }
	}
    public:
	void connect(TreeLinkNode *root) {
	    bfs(root);
	}
};
