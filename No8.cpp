class Solution {
public:
    int myAtoi(string str) 
    {
    	vector<int> result;
    	long int integerRes=0;
    	bool positive = true;
    	for(int i=0; i<str.size(); i++)
    	{
    		//48 is 0, 57 is 9
    		if((str[i]>=48)&&(str[i]<=57))
    		{
    			result.push_back(str[i]-48);
    		}
    		//45 is negative sign
    		else if((result.empty())&&(str[i]==45))
    		{
    			positive=false;
    		}
    		else if(!result.empty())
    		{
    			break;
    			
    		}
    	}
    	int len = result.size();
    	
    		for(int i=0; i<len; i++)
    		{
    			integerRes += result[i]*pow(10,len-i-1);
    			if((positive)&&(integerRes>INT_MAX))
    			{
    				return INT_MAX;
    			}
    			else if(integerRes>INT_MAX)
    			{
    				return INT_MIN;
    			}
    		}
    	if(positive)
    		return integerRes;
    	else
    		return integerRes*-1;

    }
};





class Solution {
public:
    int myAtoi(string str) 
    {
    	if(str.length()==0)
    	{
    		return 0;
    	}
    	double result=0;
    	int sign=1;
    	int index=0;
    	str.erase(0,str.find_first_not_of(' '));
    	str.erase(str.find_last_not_of(' ')+1);

    	if(str[index]=='+')
    	{
    		index++;
    	}
    	else if(str[index]=='-')
    	{
    		index++;
    		sign=-1;
    	}

    	for(int i=index; i<str.length(); i++)
    	{
    		if((str[i]<'0')||(str[i]>'9'))
    		{
    			break;
    		}
    		else if((str[i]>='0')&&(str[i]<='9'))
    		{
    			result = result*10+str[i]-'0';
    			if((result>INT_MAX)&&(sign>0))
    			{
    				return INT_MAX;
    			}
    			else if(result>INT_MAX)
    			{
    				return INT_MIN;
    			}
    		}
    	}
    	return int(result*sign);

    }
};