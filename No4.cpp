class Solution {
public:
    int myAtoi(string str) 
    {
    	vector<int> digit;
    	double result=0;
    	bool isPositive = true;
    	int signalChange=0;
    	for(int i=0; i<str.size(); i++)
    	{
    		//base1: space
    		if((str[i]==32)&&(digit.empty())&&(signalChange==0))
    		{
    			continue;
    		}
    		//base2: many signal+digit = 0, like +-2
    		if((str[i]=='+')&&(digit.empty()))
    		{
    			signalChange++;
    		}
    		if((str[i]=='-')&&(digit.empty()))
    		{
    			signalChange++;
    			isPositive=false;
    		}
    		if(signalChange>1)
    		{
    			return 0;
    		}

    		//base3: no signal + digit = 0, like a2
    		if(((str[i]<48)||(str[i]>57))&&(str[i]!='+')&&(str[i]!='-')&&(digit.empty()))
    		{
    			return 0;
    		}

    		//base4: normal
    		if((str[i]>=48)&&(str[i]<=57))
    		{
    			digit.push_back(str[i]-'0');
    		}

    		//base5: break
    		else if(!digit.empty())
    		{
    			break;
    		}
    	}    
    	for(int i=0; i<digit.size(); i++)
    	{
    		result += digit[i]*pow(10,digit.size()-i-1);
    		if(isPositive)
    		{
    			if(result>INT_MAX)
    			{
    				return INT_MAX;
    			}
    		}
    		else
    		{
    			if(result-1>INT_MAX)
    			{
    				return INT_MIN;
    			}
    		}
    	}
    	if(isPositive)
    	{
    		return result;
    	}
    	else
    	{
    		return result*-1;
    	}

    }
};