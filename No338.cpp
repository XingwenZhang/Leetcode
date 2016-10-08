class Solution {
public:
    vector<int> countBits(int num) {
        
    	vector<int> result;

        for(int i=0; i<=num; i++)
        {
        	int count = 0;
        	for(int j=0; j<32; j++)
        	{
        		//这里要与0相比较，而不能与1相比较；同时要注意的一点是不等于的运算有限级要高于按位与
        		if((i&(1<<j))!=0)
        		{
        			count++;
        		}
        	}
        	result.push_back(count);
        }

        return result;


        
    }
};