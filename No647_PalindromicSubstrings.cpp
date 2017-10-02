// 647. Palindromic Substrings

// Given a string, your task is to count how many palindromic substrings in this string.

// The substrings with different start indexes or end indexes are counted as different substrings even they consist of same characters.

// Example 1:
// Input: "abc"
// Output: 3
// Explanation: Three palindromic strings: "a", "b", "c".
// Example 2:
// Input: "aaa"
// Output: 6
// Explanation: Six palindromic strings: "a", "a", "a", "aa", "aa", "aaa".
// Note:
// The input string length won't exceed 1000.


class Solution {
public:
    int countSubstrings(string s) {
        int res = 0;
        for(int i=0; i<s.size(); i++){
            palindromic_util(i, i, res, s);
            palindromic_util(i, i+1, res, s);
        }
        return res;
    }

    void palindromic_util(int i, int j, int& res, string& s){
        while(i>=0 && j<s.size() && s[i]==s[j]){
            i--; j++; res++;
        }
    }
};


// This is wrong, but now I have found the where my idea is not correct
class Solution {
public:
    int countSubstrings(string s){
        return palindromic_util2(0, s.size()-1, s);
    }

    int palindromic_util2(int left, int right, string& s){
        if(left > right)
            return 0;
        if(left == right)
            return 1;

        if(s[left] == s[right]){
            return palindromic_util2(left+1, right, s) + palindromic_util2(left, right-1) + 1 - palindromic_util2(left+1, right-1, s);
        }
        else{
            return palindromic_util2(left+1, right, s) + palindromic_util2(left, right -1) - palindromic_util2(left+1, right-1, s);
        }
    }
};