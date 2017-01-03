class Solution {  
    private:  
	int max(int a,int b)  
	{  
	    return a>b?a:b;  
	}  
	void insert(ListNode*l,ListNode*p)  
	{  
	    ListNode * r = l;  
	    while(r->next!=NULL)  
	    {  
		r=r->next;  
	    }  
	    r->next=p;  
	}  
    public:  
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {  
	    ListNode* result=new ListNode(0);  
	    int mol=0;  
	    int sum=0;  
	    int exc = 0;  
	    int l1_val=0;  
	    int l2_val=0;  
	    while(l1!=NULL || l2!=NULL)  
	    {  
		if(l1)  
		{  
		    l1_val = l1->val;  
		}  
		else  
		{  
		    l1_val=0;  
		}  
		if(l2)  
		{  
		    l2_val = l2->val;  
		}  
		else  
		{  
		    l2_val=0;  
		}  

		sum=l1_val + l2_val + exc;  
		exc = sum / 10;  
		mol = sum % 10;  
		ListNode*p = new ListNode(mol);  
		insert(result,p);  
		if(l1)  
		    l1=l1->next;  
		if(l2)  
		    l2=l2->next;  
	    }  
	    if(exc>0)  
	    {  
		ListNode*p = new ListNode(exc);  
		insert(result,p);  
	    }  
	    result=result-next;//输出格式  
	    return result;  
	}  
};  
