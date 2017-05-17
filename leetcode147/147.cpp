bool comp(ListNode*x,ListNode*y)
{
    return x->val<y->val;
}
class Solution
{
    public:
	ListNode* insertionSortList(ListNode*head)
	{
	    if(!head)
		return NULL;
	    ListNode*p=head;
	    vector<ListNode*>vec;
	    while(p!=NULL)
	    {
		vec.push_back(p);
		p=p->next;
	    }
	    sort(vec.begin(),vec.end(),comp);
	    int i;
	    for(i=0;i<vec.size()-1;i++)
	    {
		vec[i]->next=vec[i+1];
	    }
	    vec[i]->next=NULL;
	    head=vec[0];
	    return head;
	}
};
