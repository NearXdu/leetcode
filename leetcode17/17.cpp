class Solution {
    private:
	void MyFunc(string digits,string temp,vector<string> &result,map<char,string>myMap)
	{
	    int i;
	    int currLen=temp.size();
	    if(currLen == digits.size())
	    {
		result.push_back(temp);
		//	temp.clear();
	    }
	    else
	    {
		for(i = 0;i < myMap[ digits[currLen] ].size();i++)
		{
		    temp = temp + myMap[ digits[currLen] ][i];
		    MyFunc(digits,temp,result,myMap);
		    temp.pop_back();
		}
	    }
	}
    public:
	vector<string> letterCombinations(string digits) {
	    vector<string>result;
	    string temp="";
	    if(digits.size()<1)
	    {
		return result;
	    }
	    map<char,string>myMap;
	    myMap['2']="abc";
	    myMap['3']="def";
	    myMap['4']="ghi";
	    myMap['5']="jkl";
	    myMap['6']="mno";
	    myMap['7']="pqrs";
	    myMap['8']="tuv";
	    myMap['9']="wxyz";
	    MyFunc(digits,temp,result,myMap);
	    return result;
	}
};
