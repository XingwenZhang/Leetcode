class Solution {
public:
    vector<string> letterCombinations(string digits) 
    {
    	string digitToLetter[10]={"0","1","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    	vector<string> ans;
    	if(digits.size()==0)
    	{
    		return ans;
    	}
    	ans.push_back("");
    	for(int i=0; i<digits.size(); i++)
    	{
    		string lookUpChar = digitToLetter[digits[i]-'0'];
    		vector<string> temp;
    		for(int j=0; j<lookUpChar.size(); j++)
    		{
    			for(int k=0; k<ans.size(); k++)
    			{
    				temp.push_back(ans[k]+lookUpChar[j]);
    			}
    		}
    		ans = temp;
    	}
    	return ans;
    }
};