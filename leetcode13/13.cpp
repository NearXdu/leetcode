class Solution {
    public:
	int romanToInt(string s) {
	    int sum=0;
	    int strLen = s.size();
	    map<char,int> myMap;
	    myMap['I']=1;
	    myMap['V']=5;
	    myMap['X']=10;
	    myMap['L']=50;
	    myMap['C']=100;
	    myMap['D']=500;
	    myMap['M']=1000;

	    //vector<int> myVec(4,0);
	    int i=0;
	    int j;
	    while( i < strLen )
	    {
		while(i<strLen&&myMap[s[i]] >= myMap[s[i+1]])
		{
		    sum = sum + myMap[s[i]];
		    i++;
		}
		while(i<strLen&&myMap[s[i]] < myMap[s[i+1]])
		{
		    sum = sum - myMap[s[i]];
		    i++;
		}

	    }
	    return sum;
	}
};
