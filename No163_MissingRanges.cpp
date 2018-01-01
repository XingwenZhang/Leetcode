163. Missing Ranges

Given a sorted integer array where the range of elements are in the inclusive range [lower, upper], return its missing ranges.

For example, given [0, 1, 3, 50, 75], lower = 0 and upper = 99, return ["2", "4->49", "51->74", "76->99"].



// class Solution {
// public:
//     vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
//         vector<string> res;
//         if(nums.empty()){
//             if(lower != upper)
//                 res.push_back(to_string(lower) + "->" + to_string(upper)); 
//             else
//                 res.push_back(to_string(lower));
//             return res;
//         }
//         int idx = 0;
//         int start = 0;
//         int end = 0;
//         bool flag = true;
//         int max_num = nums.back();
//         int min_num = nums.front();
//         if(min_num!=lower){
//             if(min_num -1 != lower){
//                 res.push_back(to_string(lower) + "->" + to_string(min_num-1));
//             }
//             else{
//                 res.push_back(to_string(lower));
//             }
//         }
        
//         for(int i=min_num; i<=max_num; i++){ // 会有溢出的风险
            
//             if(nums[idx] == i && flag){
//                 idx++;
//             }
//             else if(nums[idx] == i && !flag){
//                 end = i-1;
//                 if(start != end){
//                     res.push_back(to_string(start)+"->"+to_string(end));
//                 }
//                 else{
//                     res.push_back(to_string(start));
//                 }
//                 idx++;
//                 flag = !flag;
//             }
//             else if(flag){
//                 start = i;
//                 flag = !flag;
//             }
//             if(i > i+1){
//                 break;
//             }
//         }
        
//         if(max_num != upper){
//             if(max_num+1 != upper)
//                 res.push_back(to_string(max_num+1) + "->" + to_string(upper));
//             else
//                 res.push_back(to_string(max_num+1));
//         }
        
//         return res;
//     }
// };


// Need to consider to much over flow situations
class Solution {
public:
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
        int next = lower;
        vector<string> res;
        bool over_flow = false;
        for(int i=0; i<nums.size(); i++){
            if(nums[i] < next) continue;
            if(nums[i] == next){
                if(next + 1 < next){
                    over_flow = true;
                    break;
                }
                next++;
                
                continue;
            }
            res.push_back(next == nums[i]-1 ? to_string(next) : to_string(next) + "->" + to_string(nums[i]-1));
            if(nums[i] + 1 <= next)
            {   
                over_flow = true;
                break;
            }
            next = nums[i] + 1;
        }
        if(next <= upper && !over_flow){
            res.push_back(next == upper ? to_string(next) : to_string(next) + "->" + to_string(upper));
        }
        return res;
    }
};