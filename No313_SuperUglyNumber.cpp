// 313. Super Ugly Number

// Write a program to find the nth super ugly number.

// Super ugly numbers are positive numbers whose all prime factors are in the given prime list primes of size k. For example, [1, 2, 4, 7, 8, 13, 14, 16, 19, 26, 28, 32] is the sequence of the first 12 super ugly numbers given primes = [2, 7, 13, 19] of size 4.

// Note:
// (1) 1 is a super ugly number for any given primes.
// (2) The given numbers in primes are in ascending order.
// (3) 0 < k ≤ 100, 0 < n ≤ 106, 0 < primes[i] < 1000.
// (4) The nth super ugly number is guaranteed to fit in a 32-bit signed integer.


// This problem is similar with Ugly Number II, only difference is the lenght of primes
class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        vector<int> ugly_num;
        ugly_num.emplace_back(1);
        vector<int> id(primes.size(), 0);
        
        vector<int> next_ugly_nums;
        next_ugly_nums.reserve(primes.size());

        while(ugly_num.size() != n){
            int min_ugly = INT_MAX;
            for(int i=0; i<primes.size(); i++){
                next_ugly_nums.emplace_back(primes[i]*ugly_num[id[i]]);
                if(min_ugly > primes[i]*ugly_num[id[i]]){
                    min_ugly = primes[i]*ugly_num[id[i]];
                }
            }
            ugly_num.emplace_back(min_ugly);

            for(int i=0; i<next_ugly_nums.size(); i++){
                if (next_ugly_nums[i] == min_ugly){
                    id[i]++;
                }
            }
            next_ugly_nums.erase(next_ugly_nums.begin(), next_ugly_nums.end());
        }
        return ugly_num[n-1];

    }
};