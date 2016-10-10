class Solution {
public:
	//double pointer
    int romanToInt(string s) 
    {
    	char index[7]={'I','V','X','L','C','D','M'};
    	int indexValue[7]={1,5,10,50,100,500,1000};
    	vector<int> value;
    	for(int i=0; i<s.size(); i++)
    	{
    		for(int j=6; j>=0; j--)
    		{
    			if(s[i]==index[j])
    			{
    				value.push_back(indexValue[j]);
    			}
    		}
    	}
    	for(int k=0; k<value.size()-1; k++)
    	{
    		if(value[k]<value[k+1])
    		{
    			value[k]=value[k]*-1;
    		}
    	}
    	int sum = accumulate(value.begin(),value.end(),0);
    	return sum;
    }
};