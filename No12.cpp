class Solution {
public:
    string intToRoman(int num) 
    {
    	string indexSign[13]={"I","IV","V","IX","X","XL","L","XC","C","CD","D","CM","M"};
    	int indexValue[13]={1,4,5,9,10,40,50,90,100,400,500,900,1000};
    	vector<int> everyDigit;
    	vector<int> everyDigitTrueValue;
    	string result;
    	while(num)
    	{
    		int a = num%10;
    		num = (num-a)/10;
    		everyDigit.push_back(a);
    	}
    	for(int i=everyDigit.size()-1; i>=0; i--)
    	{
    		everyDigitTrueValue.push_back(everyDigit[i]*pow(10,i));
    	}
    	for(int j=0; j<everyDigitTrueValue.size(); j++)
    	{
    		for(int k=12; k>=0; k--)
    		{
    			if(everyDigitTrueValue[j]>=indexValue[k])
    			{
    				result+=indexSign[k];
    				everyDigitTrueValue[j]-=indexValue[k];
    				if(everyDigitTrueValue[j]==0)
    				{
    					break;
    				}
    				else
    				{
    					k=13;
    					continue;
    				}
    			}
    		}
    	}
    	return result;
    }
};