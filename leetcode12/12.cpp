class Solution {
    public:
	string intToRoman(int num) {
	    string result = "";
	    vector<int> myVec;
	    int x=num;
	    while(x)
	    {
		myVec.push_back(x%10);
		x=x/10;
	    }
	    int i;
	    for(i=myVec.size()-1;i>=0;i--)
	    {
		switch(i){
		    case 3:
			while(myVec[i]--)
			    result=result+"M";
			break;
		    case 2:
			if(myVec[i]==4)
			    result=result+"CD";
			else if(myVec[i]<=3 && myVec[i]>=1)
			{
			    while(myVec[i]--)
				result=result+"C";
			}
			else if(myVec[i]<=8 && myVec[i]>=5)
			{
			    result = result+"D";
			    while((myVec[i]--)-5)
			    {
				result=result+ "C";
			    }
			}
			else if(myVec[i]==9)
			{
			    result =result + "CM";
			}
			else
			    continue;
			break;
		    case 1:
			if(myVec[i]==4)
			    result=result+"XL";
			else if(myVec[i]<=3 && myVec[i]>=1)
			{
			    while(myVec[i]--)
				result=result+"X";
			}
			else if(myVec[i]<=8 && myVec[i]>=5)
			{
			    result = result+"L";
			    while((myVec[i]--)-5)
			    {
				result=result+ "X";
			    }
			}
			else if(myVec[i]==9)
			{
			    result =result + "XC";
			}
			else
			    continue;
			break;
		    case 0:
			if(myVec[i]==4)
			    result=result+"IV";
			else if(myVec[i]<=3 && myVec[i]>=1)
			{
			    while(myVec[i]--)
				result=result+"I";
			}
			else if(myVec[i]<=8 && myVec[i]>=5)
			{
			    result = result+"V";
			    while((myVec[i]--)-5)
			    {
				result=result+ "I";
			    }
			}
			else if(myVec[i]==9)
			{
			    result =result + "IX";
			}
			else
			    continue;
			break;

		}
	    }
	    return result;
	}
};
