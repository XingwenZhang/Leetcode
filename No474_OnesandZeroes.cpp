// 474. Ones and Zeroes

// In the computer world, use restricted resource you have to generate maximum benefit is what we always want to pursue.

// For now, suppose you are a dominator of m 0s and n 1s respectively. On the other hand, there is an array with strings consisting of only 0s and 1s.

// Now your task is to find the maximum number of strings that you can form with given m 0s and n 1s. Each 0 and 1 can be used at most once.

// Note:
// The given numbers of 0s and 1s will both not exceed 100
// The size of given string array won't exceed 600.
// Example 1:
// Input: Array = {"10", "0001", "111001", "1", "0"}, m = 5, n = 3
// Output: 4

// Explanation: This are totally 4 strings can be formed by the using of 5 0s and 3 1s, which are “10,”0001”,”1”,”0”
// Example 2:
// Input: Array = {"10", "0", "1"}, m = 1, n = 1
// Output: 2

// Explanation: You could form "10", but then you'd have nothing left. Better form "0" and "1".


// TLE
class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        return max_util(strs, 0, m, n, 0);
    }
    int max_util(vector<string>& strs, int index, int m, int n, int nums){
        if(index >= strs.size() && m >= 0 && n>=0){
            return nums;
        }
        auto pair_num = num_of_0_and_1(strs[index]);
        if(m >= pair_num.first && n >= pair_num.second)
            return max (max_util(strs, index+1, m, n, nums), max_util(strs, index+1, m-pair_num.first, n-pair_num.second, nums+1));
        else
            return max_util(strs, index+1, m, n, nums);
    }

    pair<int,int> num_of_0_and_1(string s){ // return 0,1
        int m=0;
        int n = 0;
        for(auto& i : s){
            if(i == '0'){
                m++;
            }
            else{
                n++;
            }
        }
        return make_pair(m,n);
    }
};


// MLE
class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<vector<int> > > cache(strs.size()+1, vector<vector<int> >(m+1, vector<int>(n+1, -1)));
        return max_util2(strs, 0, m, n, cache);
    }

    int max_util2(vector<string>& strs, int index, int m, int n, vector<vector<vector<int> > >& cache){
        if(m < 0 || n < 0)
            return -1; // retrieve to the origin state
        if(index == strs.size()){
            return 0;
        }
        if(cache[index][m][n] != -1){
            return cache[index][m][n];
        }
        auto pair_num = num_of_0_and_1(strs[index]);
        return cache[index][m][n] = max(max_util2(strs, index+1, m, n, cache), 1+ max_util2(strs, index+1, m-pair_num.first, n-pair_num.second, cache));
    }

    pair<int,int> num_of_0_and_1(string s){ // return 0,1
        int m=0;
        int n = 0;
        for(auto& i : s){
            i == '0' ? ++m : ++n;
        }
        return make_pair(m,n);
    }
};

// 经过分析，实际上index之间的关系是简单的，只需要依赖前一个Index即可
class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int> > cache(m+1, vector<int>(n+1, 0));
        for(auto s : strs){
            int num_zero = count(s.begin(), s.end(), '0');
            for(int i=m; i>=num_zero; i--){
                for(int j=n; j>=(int)s.size()-num_zero; j--){ // 必须转换成int，否则死循环，size_t与int
                    cache[i][j] = max(cache[i][j], cache[i-num_zero][j-s.size()+num_zero]+1);
                }
            }
        }
        return cache[m][n];
    }
};



