class Solution {
    public:
	ListNode* partition(ListNode* head, int x) {
	    ListNode *start = new ListNode(0);
	    ListNode* k = start;
	    ListNode*q = head;
	    while (NULL != q)//插入小数
	    {
		if (q->val >= x)
		{
		    q = q->next;
		    continue;
		}
		else
		{
		    ListNode* r = new ListNode(q->val);
		    k->next = r;
		    k = r;
		    q = q->next;
		}
	    }
	    q = head;
	    while (NULL != q)//插入大数
	    {
		if (q->val < x)
		{
		    q = q->next;
		    continue;
		}
		else
		{
		    ListNode* r = new ListNode(q->val);
		    k->next = r;
		    k = r;
		    q = q->next;
		}
	    }
	    return start->next;
	}
};
