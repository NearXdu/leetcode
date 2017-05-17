class Solution {
    public:
	bool hasCycle(ListNode *head) {
	    ListNode * p = new ListNode(0);
	    p->next=head;
	    unordered_set<ListNode *>visit;
	    bool flag=false;
	    while(p&&p->next)
	    {
		if(visit.find(p)==visit.end())
		{
		    visit.insert(p);
		    p=p->next;
		}
		else
		{
		    flag=true;
		    break;
		}
	    }
	    if(flag)
		return true;
	    else
		return false;
	}

};


//////
//


class Solution {
    public:
	bool hasCycle(ListNode *head) {
	    ListNode *p1 =head;
	    ListNode *p2=head;
	    while(p2&&p2->next)
	    {
		p1=p1->next;
		p2=p2->next->next;
		if(p1==p2)
		    return true;
	    }
	    return false;
	}
};
