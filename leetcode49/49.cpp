class Solution {  
    public:  
	vector<vector<string>> groupAnagrams(vector<string>& strs) {  
	    map<string, multiset<string>>myMap;//用set不行，需要用multiset  
	    vector< vector<string> >result;  
	    for (int i = 0; i < strs.size(); i++)  
	    {  
		string temp = strs[i];  
		sort(temp.begin(), temp.end());  
		myMap[temp].insert(strs[i]);  
	    }//构建map  
	    auto it = myMap.begin();  
	    while (it != myMap.end())  
	    {  
		vector<string>temp(it->second.begin(), it->second.end());  
		result.push_back(temp);  
		++it;  
	    }  
	    return result;  
	}  
};  
