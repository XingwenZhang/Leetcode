// 128. Longest Consecutive Sequence

// Given an unsorted array of integers, find the length of the longest consecutive elements sequence.

// For example,
// Given [100, 4, 200, 1, 3, 2],
// The longest consecutive elements sequence is [1, 2, 3, 4]. Return its length: 4.

// Your algorithm should run in O(n) complexity.

// O(n) time complexity, means we need some efficient data structure to assit
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> hash_set(nums.begin(), nums.end());
        int res = 0;

        for(auto i : nums){
            if(!hash_set.count(i)) continue;
            hash_set.erase(i);
            int pre = i-1;
            int next = i+1;
            while(hash_set.count(pre)) hash_set.erase(pre--);
            while(hash_set.count(next)) hash_set.erase(next++);
            res = max(res, next-pre-1);
        }
        return res;
    }
};


// use map to store the corresponding sum
class Solution{
public:
    int longestConsecutive(vector<int>& nums){
        unordered_map<int, int> hash_map;
        int res = 0;
        for(auto i : nums){
            if(!hash_map.count(i)){
                int left = hash_map.count(i-1)? hash_map[i-1] : 0;
                int right = hash_map.count(i+1)? hash_map[i+1] : 0;
                int sum = left+right+1;
                res = max(res, sum);
                hash_map[i]=sum;
                hash_map[i-left]=sum; // update the left boundary
                hash_map[i+right]=sum; // update the right boundary
            }

        }
        return res;
    }
};