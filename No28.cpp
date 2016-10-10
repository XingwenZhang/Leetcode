class Solution {
public:
    int strStr(string haystack, string needle) 
    {
        int i=0,j=0,m=0;
        int result=-1;
        int lenHay=haystack.size();
        int lenNdl=needle.size();
        if(lenNdl==0)
        	return 0;
        if((lenNdl>lenHay)||(lenHay==0))
        	return result;

        for(i=0; i<lenHay-lenNdl+1; i++)
        {
        	if(haystack[i]==needle[j])
        	{
        		m=i+1;
        		j+=1;
        		while(j<lenNdl)
        		{
        			if(haystack[m]!=needle[j])
        			{
        				break;
        			}
        			j++;
        			m++;
        		}
        		if(j==lenNdl)
        		{
        			result = i;
        			break;
        		}
        		
        		j=0;
        	}
        	

        }
        return result;
    }
};