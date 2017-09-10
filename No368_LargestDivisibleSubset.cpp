// 368. Largest Divisible Subset

// Given a set of distinct positive integers, find the largest subset such that every pair (Si, Sj) of elements in this subset satisfies: Si % Sj = 0 or Sj % Si = 0.

// If there are multiple solutions, return any subset is fine.

// Example 1:

// nums: [1,2,3]

// Result: [1,2] (of course, [1,3] will also be ok)
// Example 2:

// nums: [1,2,4,8]

// Result: [1,2,4,8]


// variety of Longest Incresing Sequence
class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        vector<int> res;
        if(nums.size() == 0){
            return res;
        }
        vector<pair<int,int> > cache(nums.size(), make_pair(0,-1)); // num, and parent
        sort(nums.begin(), nums.end());
        for(int i=1; i<nums.size(); i++){
            for(int j=0; j<i; j++){
                if(nums[i] % nums[j] == 0 && cache[i].first < cache[j].first + 1){
                    cache[i].first = cache[j].first + 1;
                    cache[i].second = j;
                }
            }
        }
        int max_num = INT_MIN;
        int max_index = -1;
        for(int k=0; k<cache.size(); k++){
            if(cache[k].first > max_num){
                max_num = cache[k].first;
                max_index = k;
            }
        }

        
        while(max_index != -1){
            res.emplace_back(nums[max_index]);
            max_index = cache[max_index].second;
        }
        return res;
    }
};