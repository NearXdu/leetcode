class Solution {
    private:
	unordered_set<ListNode*> visit;
    public:
	ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
	    ListNode *p=headA;
	    ListNode *r=headB;

	    while(p!=NULL)
	    {
		visit.insert(p);
		p=p->next;
	    }

	    while(r!=NULL)
	    {
		if(visit.find(r)==visit.end())
		    r=r->next;
		else
		    break;
	    }
	    return r;

	}
};
//===================================//

class Solution {
    public:
	ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
	{
	    ListNode *pa=headA;
	    ListNode *pb=headB;
	    while(pa!=pb)
	    {
		pa=pa?(pa->next):headB;
		pb=pb?(pb->next):headA;
	    }
	    return pa;

	}
};
