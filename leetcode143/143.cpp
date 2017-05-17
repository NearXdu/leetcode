class Solution
{
    private:
	void reverse(ListNode * &post)//逆置链表
	{

	    if(post&&post->next)
	    {
		ListNode *p1 = post;
		ListNode *p2 = post->next;
		ListNode *p3 = NULL;
		while(p2!=NULL)
		{
		    p3=p2->next;
		    p2->next=p1;
		    p1=p2;
		    p2=p3;
		}
		post->next=NULL;
		post=p1;
	    }
	    else
	    {
		return ;
	    }

	}
    public:
	void reorderList(ListNode * head)
	{
	    if(!head)
		return ;
	    int count=0;
	    ListNode *p=head;
	    while(p!=NULL)
	    {
		p=p->next;
		count++;
	    }
	    count = (count+1)/2;//find pre
	    ListNode *pre=head;
	    ListNode *post=head;
	    int t=count;
	    while(--t)
	    {
		post=post->next;
	    }

	    ListNode *r = post;
	    post=post->next;
	    r->next=NULL;
	    //cout << post->val<<endl;
	    //      cout << count << endl;

	    reverse(post);

	    ListNode *pPre=pre;
	    ListNode *pPost=post;
	    ListNode *pNext=NULL;

	    while(pPost)
	    {
		pNext=pPost->next;
		pPost->next=pPre->next;
		pPre->next=pPost;
		pPre=pPost->next;
		pPost=pNext;
	    }
	    head=pre; 

	}
};
