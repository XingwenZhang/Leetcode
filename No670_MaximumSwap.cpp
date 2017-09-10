// 670. Maximum Swap

// Given a non-negative integer, you could swap two digits at most once to get the maximum valued number. Return the maximum valued number you could get.

// Example 1:
// Input: 2736
// Output: 7236
// Explanation: Swap the number 2 and the number 7.
// Example 2:
// Input: 9973
// Output: 9973
// Explanation: No swap.
// Note:
// The given number is in the range [0, 108]

class Solution {
public:
    int maximumSwap(int num) {
        vector<int> origin_v = get_digits(num);
        vector<int> sort_v(origin_v);
        sort(sort_v.rbegin(), sort_v.rend());
        for(int i=0; i<origin_v.size(); i++){
            if(sort_v[i] != origin_v[i]){
                auto big_loc = find(origin_v.begin(), origin_v.end(), sort_v[i]);
                int temp = origin_v[i];
                origin_v[i] = *big_loc;
                *big_loc = temp;
                break;
            }
        }
        return get_num(origin_v);

    }
    vector<int> get_digits(int num){
        vector<int> v;
        while(num){
            v.push_back(num%10);
            num = num / 10;
        }
        return reverse(v.begin(), v.end());
    }
    int get_num(vector<int>& v){
        int r = 0;
        for(int i=0; i<v.size(); i++){
            r = r*10 + v[i];
        }
        return r;
    }
};