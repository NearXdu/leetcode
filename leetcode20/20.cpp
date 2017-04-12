class Solution {
    public:
	bool isValid(string s) {
	    stack<char> brackets;
	    map<char, char>myMap;
	    myMap[')'] = '(';
	    myMap[']'] = '[';
	    myMap['}'] = '{';
	    int len = s.size();
	    int i;
	    for (i = 0; i<len; i++)
	    {
		if (s[i] == '(' || s[i] == '[' || s[i] == '{')
		{
		    brackets.push(s[i]);
		}
		if (s[i] == ')' || s[i] == ']' || s[i] == '}')
		{
		    if (brackets.empty() == true)
			return false;
		    if (brackets.top() != myMap[s[i]])
			return false;
		    else
		    {
			if (!brackets.empty())
			    brackets.pop();
			else
			    return true;
		    }
		}
	    }
	    if (!brackets.empty())
		return false;
	    else
		return true;
	}
};
