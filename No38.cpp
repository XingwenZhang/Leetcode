class Solution {
public:
    string countAndSay(int n) 
    {
    	string front;
    	string back;
    	string initial;
    	int times=1;
    	int m=n;
    	stack<int> a;

    	//because misunderstand the question
    	//I supposed that the start number is also n
    	//but actually the start number is fixed 1
    	n=1;
    	while(n)
    	{
    		a.push(n%10);
    		n/=10;
    	}
    	while(!a.empty())
    	{
    		initial +='0'+a.top();
    		a.pop();
    	}
    	front = initial;
    	//front += 'z';
    	back = initial;
    	for(int i=0; i<m-1; i++)    
    	{
    		back.clear();
    		front +='z';
    		for(int j=0; j<front.length()-1; j++)
    		{

    			if(front[j]==front[j+1])
    			{
    				times++;
    			}
    			else
    			{
    				back += times+'0';
    				back += front[j];
    				times=1;
    			}
    		}
    		
    		
    		front = back;
    	}
    	return back;
    }
};