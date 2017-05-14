class Solution {

    public:
	RandomListNode *copyRandomList(RandomListNode *head) 
	{
	    if(head==NULL)
		return NULL;
	    RandomListNode * head_=new RandomListNode(0);//头节点
	    //创建带头节点的链表，方便链表操作
	    RandomListNode * p = head;
	    RandomListNode * k = head_;

	    while(p)//构建新链表
	    {
		RandomListNode* r = new RandomListNode(p->label);
		r->next = p ->next;
		p->next = r;
		p=r->next;
	    }
	    p=head;

	    while(p)//拷贝random指针域
	    {
		if(p->random)
		    p->next->random=p->random->next;
		p=p->next->next;
	    }

	    p=head->next;
	    RandomListNode * o = head;//指针o表示origin原链表

	    while(p)//“删除”节点
	    {
		o->next=o->next->next;
		k->next=p;
		k=p;
		if(p->next)
		    p=p->next->next;
		else//特殊情况处理一下
		    break;
		o=o->next;
	    }

	    return head_->next;

	}

};
