class Solution {
public:
    bool isValid(string s) 
    {
    	stack<char> bracket;
    	for(int i=0; i<s.size(); i++)    
    	{
    		if((s[i]=='(')||(s[i]=='[')||(s[i]=='{'))
    		{
    			bracket.push(s[i]);
    		}
    		if(s[i]==')')
    		{
    			if(bracket.empty()||(bracket.top()!='('))
    			{
    				return false;
    			}
    			bracket.pop();
    		}
    		if(s[i]==']')
    		{
    			if(bracket.empty()||(bracket.top()!='['))
    			{
    				return false;
    			}
    			bracket.pop();
    		}
    		if(s[i]=='}')
    		{
    			if(bracket.empty()||(bracket.top()!='{'))
    			{
    				return false;
    			}
    			bracket.pop();
    		}
    	}
    	if(bracket.empty())
    		return true;
    	else
    		return false;
    	
    }
};