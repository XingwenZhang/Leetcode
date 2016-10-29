class Solution {
public:
    int lengthOfLongestSubstring(string s) 
    {
    	int maxLength = 1;
    	int curlength = 1;
    	int prev = -2;
    	int* visited = new int[256];

    	//corner-case
    	if(s.length()==0)
    	{
    		return 0;
    	}
    	if(s.length()==1)
    	{
    		return 1;
    	}

    	for(int i=0; i<256; i++)
    	{
    		visited[i]=-1;
    	}
		
		visited[s[0]]=0;

		for(int i=1; i<s.length(); i++)
		{
			prev=visited[s[i]];
			if((prev==-1)||(i-prev>curlength))
			{
				curlength++;
			}
			else
			{
				if(curlength>maxLength)
				{
					maxLength=curlength;
				}
				curlength=i-prev;
			}
			visited[s[i]]=i;
		}
		delete[] visited;
		if(curlength>maxLength)
		{
			maxLength=curlength;
		}
		return maxLength;
    }
};



