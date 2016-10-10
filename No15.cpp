class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) 
    {
        vector<vector<int> > result;
        if(nums.size()<3)
        {
            return result;
        }
        vector<int> temp;

        sort(nums.begin(),nums.end());
        
        for(int i=0; i<nums.size()-2; i++)
        {
            if(i&&nums[i]==nums[i-1])
            {
                continue;
            }
            for(int j=i+1; j<nums.size()-1; j++)
            {
               if(j!=i+1 && nums[j]==nums[j-1])
               {
                   continue;
               }
               for(int k=j+1; k<nums.size(); k++)
               {
                  if(k!=j+1 && nums[k]==nums[k-1])
                  {
                      continue;
                  }
                  if(nums[i]+nums[j]+nums[k]==0)
                  {
                    temp.push_back(nums[i]);
                    temp.push_back(nums[j]);
                    temp.push_back(nums[k]);
                    result.push_back(temp);
                    temp.clear();
                }
            }
        }

    }

    return result;

}


};