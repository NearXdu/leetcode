class Solution {
    private:
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
	    if (l2 == NULL)
		return l1;
	    if (l1 == NULL)
		return l2;
	    ListNode *head = new ListNode(0);
	    ListNode *r = head;
	    while (l1 && l2)
	    {
		if (l1->val == l2->val)
		{
		    ListNode*p1 = new ListNode(l1->val);
		    ListNode*p2 = new ListNode(l2->val);
		    r->next = p1;
		    r = p1;
		    r->next = p2;
		    r = p2;
		    l1 = l1->next;
		    l2 = l2->next;
		}
		else if (l1->val < l2->val)
		{
		    ListNode*p1 = new ListNode(l1->val);
		    r->next = p1;
		    r = p1;
		    l1 = l1->next;
		}
		else
		{
		    ListNode*p2 = new ListNode(l2->val);
		    r->next = p2;
		    r = p2;
		    l2 = l2->next;
		}
	    }
	    if (!l1)
	    {
		r->next = l2;
	    }
	    else
	    {
		r->next = l1;
	    }
	    ListNode * p = head;
	    head = head->next;
	    delete p;
	    return head;
	}
    public:
	ListNode* mergeKLists(vector<ListNode*>& lists) {
	    int len = lists.size();
	    if (len == 0)
		return NULL;
	    if (len == 1)
		return lists[0];
	    int i = 0;
	    int j = len - 1;
	    while (i < j&&i<len/2)
	    {
		lists[i] = mergeTwoLists(lists[i], lists[j]);
		i++;
		j--;
		lists.pop_back();//将尾部链表抛弃
	    }
	    return mergeKLists(lists);
	}
};
