//递归算法略
class Solution {
    public:
	vector<int> postorderTraversal(TreeNode* root) {
	    vector<int>res;
	    if(!root)
	    {
		return res;
	    }
	    TreeNode *cur;
	    TreeNode *pre=NULL;
	    stack<TreeNode*>s;
	    s.push(root);
	    while(!s.empty())
	    {
		cur=s.top();
		if( (cur->left==NULL&&cur->right==NULL) 
			|| (pre!=NULL&& (pre==cur->left||pre==cur->right) ) )
		{
		    res.push_back(cur->val);
		    s.pop();
		    pre=cur;
		}
		else
		{
		    if(cur->right!=NULL)
		    {
			s.push(cur->right);
		    }
		    if(cur->left!=NULL)
		    {
			s.push(cur->left);
		    }
		}
	    }
	    return res;
	}
};
