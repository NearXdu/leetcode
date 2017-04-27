
class Solution {  
    private:  
	void removeBackSpace(string &s)  
	{  
	    int i = s.size() - 1;  
	    while (i >= 0 && s[i] == ' ')  
	    {  
		s.pop_back();  
		i--;  
	    }  
	}  
    public:  
	vector<string> fullJustify(vector<string>& words, int maxWidth) {  
	    int i = 0;  
	    int lenSum = 0;  
	    int count = 0;  
	    int space;  
	    vector<string> result;  
	    while (i < words.size())  
	    {  
		int j = i;  
		lenSum = 0;  
		int tempSum = lenSum + j - i;  
		while (j<words.size()&&tempSum <= maxWidth)  
		{  
		    lenSum += words[j].size();  
		    j++;  
		    tempSum = lenSum + j - i;  
		}  
		if (tempSum - 1 > maxWidth)  
		{  
		    j--;  
		    lenSum -= (words[j].size());  
		}  
		int distance = j - i;  
		if (distance > 1)  
		{  
		    if (j != words.size())  
		    {  
			space = (maxWidth - lenSum) / (distance - 1);  
			vector<char> tempspace(space, ' ');  
			string spaceWord(tempspace.begin(), tempspace.end());  
			string temp;  
			for (int k = i; k < j; k++)  
			{  
			    temp += words[k];  
			    temp += spaceWord;  
			}  
			removeBackSpace(temp);  
			if (temp.size() < maxWidth)  
			{  
			    int count = maxWidth - temp.size();  
			    for (int k = 0; count > 0 && k < temp.size(); k++)  
			    {  
				if (temp[k] == ' ')  
				{  
				    temp.insert(temp.begin() + k, ' ');  
				    k++;  
				    count--;  
				    continue;  
				}  
			    }  
			}  
			result.push_back(temp);  
		    }  
		    else  
		    {  
			space = 1;  
			vector<char> tempspace(space, ' ');  
			string spaceWord(tempspace.begin(), tempspace.end());  
			string temp;  
			for (int k = i; k < j; k++)  
			{  
			    temp += words[k];  
			    temp += spaceWord;  
			}  
			removeBackSpace(temp);  
			if (temp.size() < maxWidth)  
			{  
			    int count = maxWidth - temp.size();  
			    while (count > 0)  
			    {  
				temp.insert(temp.end(), ' ');  
				count--;  
			    }  
			}  
			result.push_back(temp);  
		    }  
		}  
		else if (distance == 1)  
		{  
		    string temp = words[j - 1];  
		    vector<char>tempspace(maxWidth-words[j-1].size(), ' ');  
		    string spaceWord(tempspace.begin(),tempspace.end());  
		    temp += spaceWord;  
		    result.push_back(temp);  
		}  
		else  
		{  
		    string temp = words[j];  
		    vector<char>tempspace(maxWidth - words[j].size(), ' ');  
		    string spaceWord(tempspace.begin(), tempspace.end());  
		    temp += spaceWord;  
		    result.push_back(temp);  
		    j++;  
		}  
		i = j;  
	    }  
	    return result;  
	}  
};  

