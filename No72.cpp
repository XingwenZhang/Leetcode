class Solution {
public:
    int minDistance(string word1, string word2) 
    {
    	int len1 = word1.size();
    	int len2 = word2.size();
    	int distance[len1+1][len2+1];
    	for(int j=0; j<=len2; j++)
    	{
    		distance[0][j]=j;
    	} 
    	for(int i=1; i<=len1; i++)
    	{
    		distance[i][0] = i;
    	}   


    	//there are only three conditions
    	//x[i] and gap in y[j]
    	//gap in x[i] and y[j]
    	//x[i] and y[j]
    	for(int i=1; i<=len1; i++)
    		for(int j=1; j<=len2; j++)
    		{
    			int a = 1 + distance[i][j-1];
    			int b = 1 + distance[i-1][j];
    			int c = INT_MAX;
    			//because the string is 0 based, so i-1, j-1
    			if(word1[i-1]==word2[j-1])
    			{
    				c = distance[i-1][j-1];
    			}
    			else
    			{
    				c = 1 + distance[i-1][j-1];
    			}
    			distance[i][j] = min(min(a,b),c);
    		}

    	return distance[len1][len2];
    }

};