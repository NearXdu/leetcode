class Solution {
    public:
	int evalRPN(vector<string>& tokens) {
	    stack<int>s;
	    for (int i = 0; i < tokens.size(); i++)
	    {
		//第一个条件为了区分负数
		if ((tokens[i].size()==1)&&(tokens[i][0] == '+' || tokens[i][0] == '*' || tokens[i][0] == '/' || tokens[i][0] == '-'))
		{
		    char op = tokens[i][0];
		    int second = s.top();
		    s.pop();
		    int first = s.top();
		    s.pop();
		    switch (op){
			case '+':
			    s.push(first + second);
			    break;
			case '-':
			    s.push(first - second);
			    break;
			case '*':
			    s.push(first * second);
			    break;
			case '/':
			    s.push(first / second);
			    break;
			default:
			    break;
		    }
		}
		else
		{
		    s.push(stoi(tokens[i]));
		}
	    }
	    return s.top();
	}
};
