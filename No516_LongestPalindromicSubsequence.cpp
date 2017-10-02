// 516. Longest Palindromic Subsequence

// Given a string s, find the longest palindromic subsequence's length in s. You may assume that the maximum length of s is 1000.

// Example 1:
// Input:

// "bbbab"
// Output:
// 4
// One possible longest palindromic subsequence is "bbbb".
// Example 2:
// Input:

// "cbbd"
// Output:
// 2
// One possible longest palindromic subsequence is "bb".

// Of course, it TLE
class Solution {
public:
    int longestPalindromeSubseq(string s) {
        return palindrome_util(s, 0, s.size()-1);
    }

    int palindrome_util(string& s, int left, int right){
        if(left > right){
            return 0;
        }
        if(left == right){
            return 1;
        }

        if(s[left] == s[right]){
            return 2 + palindrome_util(s, left+1, right-1);
        }
        else{
            return max(max(palindrome_util(s, left+1, right-1), palindrome_util(s, left+1, right)),palindrome_util(s,left, right-1));
        }
    }
};

class Solution{
public:
    int longestPalindromeSubseq(string s){
        vector<vector<int> >cache(s.size(), vector<int>(s.size(), -1));
        return palindrome_util2(s, 0, s.size()-1, cache);
    }

    int palindrome_util2(string& s, int left, int right, vector<vector<int> >& cache){
        if(left > right)
            return 0;
        if(left == right)
            return 1;
        if(cache[left][right] != -1)
            return cache[left][right];

        if(s[left] == s[right])
            return cache[left][right] = 2 + palindrome_util2(s, left+1, right-1, cache);
        else
            return cache[left][right] = max(max(palindrome_util2(s, left+1, right-1, cache), palindrome_util2(s, left+1, right, cache)),palindrome_util2(s,left, right-1, cache));
    }
};