class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n)
    {
    	vector<vector<int> > result;
    	vector<int> temp;
    	int num[9]={1,2,3,4,5,6,7,8,9};
    	vector<int> number(num,num+9);
    	combinationHelper(k,n,number,result,temp,0);
    	return result;    
    }
private:
	int combinationHelper(int k, int target, vector<int>& number, vector<vector<int> >& result, vector<int>& temp, int start)
	{
		if(target==0 && k==0)
		{
			result.push_back(temp);
			return start;
		}
		else
		{
			for(int i=start; i!=number.size()&&target>=number[i]&&k>0; )
			{
				temp.push_back(number[i]);
				k--;
				i++;
				i=combinationHelper(k,target-number[i-1], number, result, temp, i);
				temp.pop_back();
				k++;
			}
		}
		return start;
	}
};