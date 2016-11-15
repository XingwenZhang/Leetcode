class Solution {
public:
    int longestValidParentheses(string s) 
    {
        int len = s.size();

        //store the index of opening parentheses
        //initiate with -1
        stack<int> index;
        index.push(-1);

        int ans = 0;

        for(int i = 0; i<len; i++)
        {
        	//if ( , store the index
        	if(s[i] == '(')
        		index.push(i);

        	else
        	{
        		//make-pair
        		index.pop();

        		//update ans
        		//tricky one is that i-index.top()
        		//because the index always update,even it is empty
        		//for example, if index is empty
        		//the rest seq is )))))(), first time push first ), 
        		//however, next loop, the first operation is pop() then push
        		//so the top value is always correct
        		if(!index.empty())
        		{
        			ans = max(ans, i-index.top());
        		}
        		else
        		{
        			index.push(i);
        		}
        	}
        }
        return ans;
    }
};