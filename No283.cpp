/*class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        
    	int index=0;
    	int indexCopy=index;
    	for(index=0; index<nums.size();index++)
    	{
    		indexCopy = index +1;
    		while(!nums[index] && indexCopy<nums.size())
    		{
    			if(nums[indexCopy])
    			{
    				swap(nums[index],nums[indexCopy]);
    				
    				break;
    			}
    			indexCopy++;
    			
    		}
    		
    	}

    }
};*/

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int j = 0; 
        int length = nums.size();
        for(int i = 0; i<length; i++)
        {
        	if(nums[i])
        	{
        		swap(nums[j++],nums[i]);
        	}
        }
        
    }
};

/*class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        
        auto new_end = remove(nums.begin(), nums.end(), 0);
        fill(new_end, nums.end(), 0);
    }
};
*/