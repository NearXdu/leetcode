class MinStack {
    private:
	stack <int> s1;//s1正常的栈
	stack <int> s2;//s2栈顶元素记录当前最小值
    public:
	MinStack() {
	}



	void push(int x) 
	{
	    s1.push(x);
	    if(s2.empty())
	    {
		s2.push(x);
	    }
	    else
	    {
		if(x<=s2.top())
		{
		    s2.push(x);
		}
	    }

	}

	void pop() {
	    int x=s1.top();
	    s1.pop();
	    if(x==s2.top())
		s2.pop();
	}
	int top() {
	    return s1.top();
	}
	int getMin() {
	    return s2.top();
	}
};
