class Solution {
public:
    Solution(vector<int> nums) {
        tempnums = nums;
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return tempnums;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
    	//srand(time(NULL));
    	//为什么这句话会导致每次调用函数产生相同结果？
        int size = tempnums.size();
        vector<int> result;
       	int* seq = getRandom(size);
       	for(int i=0; i<size; i++)
       	{
       		result.push_back(tempnums[seq[i]]);
       	}
       	delete[] seq;
       	return result;
    }

private:
	vector<int> tempnums;
	int* getRandom(int size)
	{
		int* seq = new int[size];
		for(int i=0; i<size; i++)
		{
			seq[i]=i;
		}
		
		for(int j=0; j<size; j++)
		{
			int randNum = rand()%(size-j);
			swap(seq[size-j-1],seq[randNum]);
		}
		return seq;
	}
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * vector<int> param_1 = obj.reset();
 * vector<int> param_2 = obj.shuffle();
 */