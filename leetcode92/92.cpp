class Solution {
    public:
	ListNode* reverseBetween(ListNode* head, int m, int n) {
	    if (m == 0 || n == 0)
	    {
		return head;
	    }
	    //创建头结点
	    ListNode*p = new ListNode(0);
	    p->next = head;
	    head = p;
	    p = p->next;

	    //把需要逆置的部分“抠”出来
	    //并记录原链表的入口和出口
	    ListNode*enter = head;//原链表的入口
	    ListNode*exit = p;//原链表的出口
	    ListNode*last = NULL;//逆置部分的最后一个节点
	    ListNode*first = p;//逆置部分的头结点
	    int i = 0;
	    while (i++ < n)
	    {
		if (i < m)
		{
		    enter = enter->next;
		    first = first->next;
		}
		if (i == n)
		{
		    last = exit;
		}
		exit = exit->next;
	    }
	    enter->next = NULL;
	    last->next = NULL;

	    //完成逆置
	    ListNode*pPre = first;
	    ListNode*pCur = pPre->next;
	    ListNode*pNext = NULL;
	    while (pCur != NULL)
	    {
		pNext = pCur->next;
		pCur->next = pPre;
		pPre = pCur;
		pCur = pNext;
	    }
	    //将原链表与逆置部分组装
	    first->next = exit;
	    first = pPre;
	    enter->next = first;
	    return head->next;
	}
};
