class Solution {
    public:
	ListNode* deleteDuplicates(ListNode* head) {
	    ListNode * start = new ListNode(0);
	    start->next = head;
	    ListNode * p = start->next;
	    ListNode*q = start;
	    while (NULL!=p&&p->next != NULL)
	    {
		if (p->next != NULL&&p->next->val == p->val)
		{
		    while (p->next != NULL&&p->next->val == p->val)
		    {
			ListNode * r = p;
			p = p->next;
			delete r;
		    }
		    q->next = p;//保留一个元素
		    q=q->next;//始终让q位于可行链表的最后一个位置
		    p = p->next;
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
