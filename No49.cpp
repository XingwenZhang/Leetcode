class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) 
    {
    	vector<vector<string>> ans;

    	//using hashtable to store the string
    	unordered_map<string,vector<string>> hashTable;
    	for(int i=0; i<strs.size(); i++)
    	{
    		string copy = strs[i];
    		sort(copy.begin(),copy.end());
    		hashTable[copy].push_back(strs[i]);
    	}    
    	for(auto& item : hashTable)
    	{
    		ans.push_back(item.second);
    	}
    	return ans;
    }
};