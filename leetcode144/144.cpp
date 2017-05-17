//递归
//
class Solution {
    private:
	void preOrder(TreeNode*root,vector<int>&res)
	{
	    if(root==NULL)
		return;
	    res.push_back(root->val);
	    preOrder(root->left,res);
	    preOrder(root->right,res);
	}
    public:
	vector<int> preorderTraversal(TreeNode* root) {
	    vector<int>res;
	    preOrder(root,res);
	    return res;
	}
};
//迭代
class Solution {
    private:
	stack<TreeNode*>mystack;
	void preOrder(TreeNode*root,vector<int>&res)
	{

	    TreeNode *p =root;
	    while(p!=NULL||!mystack.empty())
	    {
		while(p!=NULL)
		{
		    res.push_back(p->val);
		    mystack.push(p);
		    p=p->left;
		}
		if(!mystack.empty())
		{
		    p=mystack.top();
		    mystack.pop();
		    p=p->right;
		}
	    }
	}
    public:
	vector<int> preorderTraversal(TreeNode* root) {
	    vector<int>res;
	    preOrder(root,res);
	    return res;
	}
};
