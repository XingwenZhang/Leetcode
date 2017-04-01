// Given an array of integers and an integer k, find out whether there are 
// two distinct indices i and j in the array such that nums[i] = nums[j] and 
// the absolute difference between i and j is at most k.


// class Solution {
// public:
// 	// This method will TLE
//     bool containsNearbyDuplicate(vector<int>& nums, int k) {
//         int n = nums.size();
//         for(int i = 0; i<n; i++){
//         	for(int j=i+1; j<=i+k && j < n; j++){
//         		if(nums[i] == nums[j]){
//         			return true;
//         			break;
//         		}
//         	}
//         }
//         return false;
//     }
// };


class Solution {
public:
	// Sliding windows
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set<int> hashSet;
        for(int i=0; i<nums.size(); i++){
        	if(i > k){
        		hashSet.erase(nums[i-k-1]);
        	}

        	// Take care! here not judge if i>k, it operates everytime
        	if(!hashSet.insert(nums[i]).second){
        		return true;
        	}
        }
        return false;
    }
};

