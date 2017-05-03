
class Solution {
    private:
	int counts(ListNode*head)//统计有多少个节点
	{
	    ListNode*p=head;
	    int count=0;
	    while(NULL!=p)
	    {
		++count;
		p=p->next;
	    }
	    return count;
	}
	TreeNode* helper(int n,ListNode*&head)
	{
	    if (0==n)
		return NULL;
	    TreeNode*root=new TreeNode(0);
	    root->left=helper(n/2,head);
	    root->val=head->val;
	    head=head->next;
	    root->right=helper(n-n/2-1);
	    return root;
	}
    public:
	TreeNode* sortedListToBST(ListNode* head) {
	    int n =counts(head);
	    return helper(n,head);
	}
};
