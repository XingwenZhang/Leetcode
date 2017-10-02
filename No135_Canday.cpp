// 135. Candy

// There are N children standing in a line. Each child is assigned a rating value.

// You are giving candies to these children subjected to the following requirements:

// Each child must have at least one candy.
// Children with a higher rating get more candies than their neighbors.
// What is the minimum candies you must give?


// Greedy, start from the min ratings number
class Solution {
public:
    int candy(vector<int>& ratings) {
        vector<int> nums(ratings.size(), 1); // At least 1 for each
        for(int i=0; i<ratings.size(); i++){ // left to right, one increasing sequence
            int pre = i-1 >= 0 ? i-1 : i;
            int next = i+1 < ratings.size() ? i+1 : i;
            if(ratings[i] > ratings[pre] && nums[i] <= nums[pre]){
                nums[i] = nums[pre]+1;
            }
            if(ratings[i] > ratings[next] && nums[i] <= nums[next]){
                nums[i] = nums[next]+1;
            }
        }

        for(int i=(int)ratings.size()-1; i>=0; i--){ // right to left, another increasing sequence
            int pre = i-1 >= 0 ? i-1 : i;
            int next = i+1 < ratings.size()? i+1 : i;
            if(ratings[i] > ratings[pre] && nums[i] <= nums[pre]){
                nums[i] = nums[pre]+1;
            }
            if(ratings[i] > ratings[next] && nums[i] <= nums[next]){
                nums[i] = nums[next]+1;
            }
        }
        return accumulate(nums.begin(), nums.end(), 0);
    }
};