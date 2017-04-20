/////////////////////////////
class Solution {  
    public:  
	int lengthOfLastWord(string s) {  
	    auto it = s.begin();  
	    while (*it == ' ')  
		s.erase(it);  
	    if (s.empty())  
		return 0;  
	    stringstream ss(s);  
	    string word;  
	    vector<string>words;  
	    while (ss >> word)  
		words.push_back(word);  
	    return words[words.size() - 1].size();  
	}  
};  
///////////////////////////////
class Solution{  
    public:  
	int lengthOfLastWord(string s) {  
	    int len=s.size()-1;  
	    while(len>=0&&s[len]==' ')//去掉空格  
		len--;  
	    int count =0;  
	    while(len>=0&&isalpha(s[len]))  
	    {  
		len --;  
		count ++;  
	    }  
	    return count;  
	}  
};  
