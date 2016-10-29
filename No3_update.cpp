class Solution {
public:
    int lengthOfLongestSubstring(string s) 
    {
    	int begin=0;
    	int end=0; 
    	int counter=0;
    	int resLen = 0;
    	vector<int> temp(128,0);
    	while(end<s.size())
    	{
    		if(temp[s[end++]]++>0)
    		{
    			counter++;
    		}
    		while(counter>0)
    		{
    			if(temp[s[begin++]]-->1)
    			{
    				counter--;
    			}
    		}
    		if(end-begin>resLen)
    		{
    			resLen = end-begin;
    		}
    	}
    	return resLen;
    }
};