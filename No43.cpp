class Solution {
public:
    string multiply(string num1, string num2) 
    {
    	reverse(num1.begin(),num1.end());
    	reverse(num2.begin(),num2.end());
    	int len1 = num1.size();
    	int len2 = num2.size();
    	string result = "";
    	vector<int> ans(len1+len2,0);
    	for(int i=0; i<len1; i++)
    		for(int j=0; j<len2; j++)
    		{
    			ans[i+j]+=(num1[i]-'0')*(num2[j]-'0');
    			ans[i+j+1]+=ans[i+j]/10;
    			ans[i+j]=ans[i+j]%10;
    		}    
    	int index = len1+len2-1;
    	while(ans[index]==0&&index>0)
    	{
    		index--;
    	}
    	for(;index>=0; index--)
    	{
    		result+=to_string(ans[index]);
    	}
    	return result;

    }
};