class Solution {
    public:
	ListNode* deleteDuplicates(ListNode* head) {
	    ListNode *start = new ListNode(0);
	    start->next = head;
	    ListNode * p = start->next;
	    ListNode *q = start;
	    while (NULL != p&&NULL != p->next)
	    {
		if (NULL != p->next&&p->next->val == p->val)
		{
		    while (NULL != p->next&&p->next->val == p->val)
		    {
			ListNode* r = p;
			p = p->next;
			delete r;
		    }
		    ListNode*r = p;
		    q->next = r->next;
		    p = r->next;
		    delete r;
		}
		else
		{
		    p = p->next;
		    q = q->next;
		}
	    }
	    return start->next;
	}
};
