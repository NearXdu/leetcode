class Solution {
    public:
	bool isNumber(string s) {
	    int count = 0;
	    int indexDot = -1;
	    int dotCount = 0;
	    int indexE = -1;
	    int eCount = 0;
	    int signCount = 0;
	    int plusCount=0;
	    int plusIndex=-1;
	    int minCount=0;
	    int minIndex=-1;
	    auto it = s.begin();
	    while (*it == ' ')
	    {
		s.erase(it);
		//it++;
	    }
	    while (*it == '-' || *it == '+')
	    {
		if (*it == '-' || *it == '+')
		    signCount++;
		s.erase(it);
		//it++;
	    }
	    if (signCount > 1)
		return false;
	    //删除后置空格
	    it = s.end() - 1;
	    while (*it == ' ')
	    {
		s.erase(it);
		it--;
	    }
	    int len = s.size();
	    if (len == 0)
		return false;
	    for (int i = 0; i < len; i++)
	    {
		if ((isalpha(s[i]) && s[i] != 'e') || s[i] == ' ')
		    return false;
		else if (s[i] <= '9'&&s[i] >= '0')
		{
		    count++;
		}
		else if (s[i] == 'e')
		{
		    eCount++;
		    indexE = i;
		}
		else if (s[i] == '.')
		{
		    dotCount++;
		    indexDot = i;
		}
		else if (s[i] == '+')
		{
		    plusCount++;
		    plusIndex=i;
		}
		else if(s[i]=='-')
		{
		    minCount++;
		    minIndex=i;
		}
		else
		{
		    return false;
		}
	    }
	    if (dotCount>1 || eCount > 1)
		return false;
	    if (indexE == len - 1)
		return false;
	    if (indexE>-1 && indexE < indexDot)
		return false;
	    if (indexE == 0)
		return false;
	    if (count == 0)
		return false;
	    if (indexDot == 0 && (indexE == len - 1 || indexE == 1))
		return false;
	    if(plusIndex>-1&&(plusIndex==len-1||plusCount>1||plusIndex!=indexE+1))
		return false;
	    if(minIndex>-1&&(minIndex==len-1||minCount>1||minIndex!=indexE+1))
		return false;
	    return true;
	}
};
