class Solution {
    public:
	bool isSameTree(TreeNode* p, TreeNode* q) {
	    if (p == NULL && q == NULL)
		return true;
	    if (p==NULL || q==NULL)//节点个数不同
		return false;
	    if (p->val != q->val)//节点个数相同，值不同
		return false;
	    return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
	}
};
