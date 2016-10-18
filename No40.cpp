class Solution {
public:
	vector<vector<int>> combinationSum2(vector<int>& candidates, int target)
	{
		vector<vector<int> >result;
		vector<int> temp;

		//sort candidates
		sort(candidates.begin(), candidates.end());

		//because one element can only be used once, so no need eliminating duplicates


		combinationHelper(candidates, target, result, temp, 0);

		/*//eliminate duplicates in result
		//for there might be duplicate elements in candidates
		vector<vector<int> >::iterator newEnd;
		newEnd = unique(result.begin(), result.end());
		result.erase(newEnd, result.end());*/

	/*	for (int i = 0; i < result.size(); i++)
		{
			for (int j = 0; j < result[i].size(); j++)
			{
				cout << result[i][j] << " ";
			}
			cout << endl;
		}*/

		return result;
	}
private:
	int combinationHelper(vector<int>& candidates, int target, vector<vector<int> >& result, vector<int>& temp, int start)
	{
		if (target == 0)
		{
			int flag = 1;
			for (int m = 0; m < result.size(); m++)
			{
				int n = 0;
				for (n = 0; n < temp.size(); n++)
				{
					if (n >= result[m].size())
					{
						break;
					}
					if (temp[n] == result[m][n])
					{
						continue;
					}
					else
					{
						break;
					}
				}
				if (n == temp.size())
				{
					flag = 0;
					break;
				}
			}
			if(flag)
				result.push_back(temp);
		/*	cout << "temp: " << endl;
			for (int j = 0; j < temp.size(); j++)
			{
				cout << temp[j] << ' ';
			}
			cout << endl;
			cout << start << endl;*/
			return start;
		}
		else
		{
			//int i = start;
			for (int i = start; i != candidates.size() && target >= candidates[i]; )
			{
				temp.push_back(candidates[i]);
				i++;
				i = combinationHelper(candidates, target - candidates[i-1], result, temp, i);
				temp.pop_back();
			}
		}
		/*cout << "time to return start" << endl;
		cout << start << endl;
		cout << "when fail the temp: " << endl;
		for (int j = 0; j < temp.size(); j++)
		{
			cout << temp[j] << ' ';
		}
		cout << endl;*/
		return start;
	}
};