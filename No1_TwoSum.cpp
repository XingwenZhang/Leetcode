//No.1 Two Sum

//hashmap there is no duplicate
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> hashmap;
        vector<int> res;
        int len = nums.size();
        for(int i=0; i<len; i++){

        	// find if there is an element in the hashmap
        	int pair = target - nums[i];

        	if(hashmap.find(pair) != hashmap.end()){
        		res.push_back(hashmap[pair]);
        		res.push_back(i);
        	}

        	hashmap[nums[i]] = i;
        }

        return res;
        
    }
};

// sort and two pointers, it could have duplicates
class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		vector<int> res;
		vector<int> tmp(nums);
		sort(nums.begin(), nums.end());
		int front = 0, end = nums.size() - 1;
		while (front < end) {
			if (nums[front] + nums[end] == target) {
				break;
			}
			else if (nums[front] + nums[end] > target) {
				end--;
			}
			else {
				front++;
			}
		}
		// in order to handle the duplicates
		for (int i = 0; i < tmp.size(); i++) {
			if (nums[front] == tmp[i]) {
				res.push_back(i);
				break;
			}
		}
		for (int i = tmp.size()-1; i >= 0; i--) {
			if (nums[end] == tmp[i]) {
				res.push_back(i);
				break;
			}
		}
		return res;
	}
};

// hashmap, duplicates
