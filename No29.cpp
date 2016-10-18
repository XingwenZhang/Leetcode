class Solution {
public:
    int divide(int dividend, int divisor) 
    {
    	long long int dividendtemp = dividend;
    	long long int divisor = divisor;
        bool sign = dividendtemp<0^divisortemp<0?0:1;

        dividendtemp=abs(dividendtemp);
        divisortemp=abs(divisortemp);

        long long int temp=0;
        long long int result = 0;

        //must have the condition equal to 0
        //for there are the situation that result is 1
        for(int i=31; i>=0; i--)
        {
        	if(temp+(divisortemp<<i)<=dividendtemp)
        	{
        		temp += (divisortemp<<i);
        		result |= 1LL << i;
        	}
        }
        if(!sign)
        {
        	result = -result;
        }
        return result>INT_MAX || result<INT_MIN ? INT_MAX : result;
    }
};