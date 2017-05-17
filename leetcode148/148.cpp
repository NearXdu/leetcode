class Solution {
    private:
	ListNode* findMid(ListNode* list);
	ListNode* MergeSort(ListNode* list);
	ListNode* Merge(ListNode* left,ListNode*right);

    public:
	ListNode* sortList(ListNode* head) {
	    return MergeSort(head);
	}

};

ListNode* Solution::findMid(ListNode *list)
{
    if(NULL==list)
	return list;

    ListNode* slow=list;
    ListNode* quick=list->next;
    while(quick&&quick->next)
    {
	slow=slow->next;
	quick=quick->next->next;
    }
    return slow;
}

ListNode* Solution::MergeSort(ListNode* list)
{
    if(list==NULL||list->next==NULL)
	return list;

    ListNode* mid = findMid(list);
    ListNode* right=mid->next;
    mid->next=NULL;
    list=MergeSort(list);
    right=MergeSort(right);
    return Merge(list,right);
}

ListNode* Solution::Merge(ListNode*left,ListNode*right)
{
    ListNode* result=new ListNode(0);
    ListNode * p=result;
    while(left&&right)
    {
	if(left->val<=right->val)
	{
	    p->next=left;
	    p=left;
	    left=left->next;
	}
	else
	{
	    p->next=right;
	    p=right;
	    right=right->next;
	}
    }
    if(NULL!=left)
	p->next=left;
    if(NULL!=right)
	p->next=right;
    return result->next;
}
