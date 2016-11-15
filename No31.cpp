class Solution {
public:
    void nextPermutation(vector<int>& nums) {

    //code by self to work as below
  	//next_permutation(nums.begin(),nums.end()); 
	int i,j;
	int len = nums.size();

	//corner case
	if(len==0||len==1)
	{
		return;
	}

	i=len-1;
	//find the rightmost digit that its right part is in descending order
	while(true)
	{
		j=i;
		i--;

		//if true, then nums[i] is that digit
		if(nums[i]<nums[j])
		{
			int k=len-1;

			//find the next largest num of nums[i]
			while(!(nums[i]<nums[k]))
			{
				k--;
			}

			//swap the i and the digit which is just bigger than nums[i]
			swap(nums[i],nums[k]);

			//the right part is in descending order, so just make it in ascending order
			reverse(nums.begin()+j,nums.end());
			return;
		}

		//if the whole seq is in descending order
		if(i==0)
		{

			reverse(nums.begin(),nums.end());
			return;
		}

	}

    }
};