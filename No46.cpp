class Solution {
public:
    vector<vector<int> > permute(vector<int>& nums) 
    {
   		vector<vector<int> > result;
   		vector<int> temp=nums;
   		permuteHelper(temp,result,0,temp.size());
   		return result;
    }
private:
	void permuteHelper(vector<int>& nums, vector<vector<int> >& result, int start, int end)
	{
		if (start == end)
		{
			result.push_back(nums);
			return;
		}
		else
		{
			for (int i = start; i != nums.size(); i++)
			{
				swap(nums[start], nums[i]);

				//after swap
				cout << "before recursion" << endl;
				cout << "times: " << i << " start value: " << start << endl;
				for (int m = 0; m < nums.size(); m++)
				{
					cout << nums[m] << " ";
				}
				cout << endl;

				permuteHelper(nums, result, start + 1, end);

				cout << "after recursion" << endl;
				cout << "times: " << i << " start value: " << start << endl;
				for (int m = 0; m < nums.size(); m++)
				{
					cout << nums[m] << " ";
				}
				cout << endl;
				
				swap(nums[start], nums[i]);


				cout << "after last swap" << endl;
				cout << "times: " << i << " start value: " << start << endl;
				for (int m = 0; m < nums.size(); m++)
				{
					cout << nums[m] << " ";
				}
				cout << endl;

			}
		}
	}
};


before recursion
times: 0 start value: 0
1 2 3
before recursion
times: 1 start value: 1
1 2 3
before recursion
times: 2 start value: 2
1 2 3
after recursion
times: 2 start value: 2
1 2 3
after last swap
times: 2 start value: 2
1 2 3
after recursion
times: 1 start value: 1
1 2 3
after last swap
times: 1 start value: 1
1 2 3
before recursion
times: 2 start value: 1
1 3 2
before recursion
times: 2 start value: 2
1 3 2
after recursion
times: 2 start value: 2
1 3 2
after last swap
times: 2 start value: 2
1 3 2
after recursion
times: 2 start value: 1
1 3 2
after last swap
times: 2 start value: 1
1 2 3
after recursion
times: 0 start value: 0
1 2 3
after last swap
times: 0 start value: 0
1 2 3
before recursion
times: 1 start value: 0
2 1 3
before recursion
times: 1 start value: 1
2 1 3
before recursion
times: 2 start value: 2
2 1 3
after recursion
times: 2 start value: 2
2 1 3
after last swap
times: 2 start value: 2
2 1 3
after recursion
times: 1 start value: 1
2 1 3
after last swap
times: 1 start value: 1
2 1 3
before recursion
times: 2 start value: 1
2 3 1
before recursion
times: 2 start value: 2
2 3 1
after recursion
times: 2 start value: 2
2 3 1
after last swap
times: 2 start value: 2
2 3 1
after recursion
times: 2 start value: 1
2 3 1
after last swap
times: 2 start value: 1
2 1 3
after recursion
times: 1 start value: 0
2 1 3
after last swap
times: 1 start value: 0
1 2 3
before recursion
times: 2 start value: 0
3 2 1
before recursion
times: 1 start value: 1
3 2 1
before recursion
times: 2 start value: 2
3 2 1
after recursion
times: 2 start value: 2
3 2 1
after last swap
times: 2 start value: 2
3 2 1
after recursion
times: 1 start value: 1
3 2 1
after last swap
times: 1 start value: 1
3 2 1
before recursion
times: 2 start value: 1
3 1 2
before recursion
times: 2 start value: 2
3 1 2
after recursion
times: 2 start value: 2
3 1 2
after last swap
times: 2 start value: 2
3 1 2
after recursion
times: 2 start value: 1
3 1 2
after last swap
times: 2 start value: 1
3 2 1
after recursion
times: 2 start value: 0
3 2 1
after last swap
times: 2 start value: 0
1 2 3