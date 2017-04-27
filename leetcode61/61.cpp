class Solution {  
    public:  
	ListNode* rotateRight(ListNode* head, int k) {  
	    if (k == 0 || head == NULL)  
		return head;  
	    ListNode*r = head;  
	    int count = 1;  
	    while (r->next)  
	    {  
		count++;//链表长度  
		r = r->next;  
	    }  
	    k = k%count;//处理k  
	    if (k==0)  
	    {  
		return head;  
	    }  
	    r->next = head;//循环链表  
	    int move = count - k;  
	    while (move--)  
	    {  
		head = head->next;  
		r = r->next;  
	    }  
	    r->next = NULL;//拆开  
	    return head;  
	}  
};  
