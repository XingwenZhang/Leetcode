class Solution {
public:
	//backtracking, recursion
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) 
    {
        vector<vector<int> > result;
        vector<int> temp;
        //candidates sort
        sort(candidates.begin(), candidates.end());

        //eliminate duplicates
        vector<int>::iterator newEnd;
        newEnd = unique(candidates.begin(),candidates.end());
        candidates.erase(newEnd, candidates.end());

        combinationHelper(candidates, target, result, temp, 0);
        return result;
    }
private:
	void combinationHelper(vector<int>& candidates, int target, vector<vector<int> >& result, vector<int>& temp, int start)
	{
		if(target==0)
		{
			result.push_back(temp);
			return;
		}
		else
		{
			//because one element can be used many times, so here using loop
			for(int i=start; i!=candidates.size()&&target>=candidates[i]; i++)
			{
				temp.push_back(candidates[i]);
				//try one element as many times as possible, until the target is negative
				combinationHelper(candidates, target-candidates[i], result, temp, i);
				temp.pop_back();
			}
		}
	}
};