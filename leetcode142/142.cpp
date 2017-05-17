class Solution {
    public:
	ListNode *detectCycle(ListNode *head) {
	    unordered_set<ListNode*> visit;
	    ListNode * p = head;
	    while(p&&p->next)
	    {
		if(visit.find(p)==visit.end())
		{
		    visit.insert(p);
		    p=p->next;
		}
		else
		{
		    return p;
		}
	    }
	    return NULL;
	}

};
