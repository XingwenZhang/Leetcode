class Solution {
public:
    int reverse(int x) 
    {
    	if(x==INT_MIN)
    	{
    		return 0;
    	}
        bool isNegative = false;
        if(x<0)
        {
        	isNegative=true;
        	x=x*-1;
        }

        vector<int> number;
        while(x)
        {
        	int a = x%10;
        	number.push_back(a);
        	x=(x-a)/10;
        }
        long int result = 0;
        for(int i=0; i<number.size(); i++)
        {
        	result += number[i]*pow(10,number.size()-i-1);
        	if(result>INT_MAX)
        		return 0;
        }
        if(isNegative)
        {
        	return result*-1;
        }
        else
        {
        	return result;
        }
    }
};