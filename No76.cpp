class Solution {
public:
    string minWindow(string s, string t) 
    {
    	int p=0;
    	int resLen = INT_MAX;
    	//ASCII
    	vector<int> temp(256,0);    
    	int counter = 0;
    	int tLen = t.size();
    	for(int i=0; i<t.size(); i++)
    	{
    		temp[t[i]]++;
    	}
    	for(int j=0; j<s.size(); j++)
    	{
    		if(temp[s[j]]-->0)
    		{
    			counter++;
    		}
    		while(counter==tlen)
    		{
    			//q=j;
    			if(j-p+1<resLen)
    			{
    				resLen=j-p+1;
    			}
    			if(temp[s[p++]]++==0)
    			{
    				counter--;
    			}
    		}
    	}
    	return resLen == INT_MAX ? "" : s.substr(p,resLen);

    }
};